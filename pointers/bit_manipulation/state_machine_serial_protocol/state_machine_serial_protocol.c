#include "state_machine_serial_protocol.h"


static uint8_t crc8_update(uint8_t crc, uint8_t byte) {
    crc ^= byte;
    for (int i = 0; i < 8; i++) {
        if (crc & 0x80)
            crc = (crc << 1) ^ 0x07;
        else
            crc <<= 1;
    }
    return crc;
}


void parser_init  (Parser_t *p)
{
    p->crc_accum = 0;
    p->len = 0;
    p->received = 0;
    p->state = STATE_IDLE;
}

int  parser_feed  (Parser_t *p, uint8_t byte) /* 0=ok, 1=done, -1=error */
{

    switch(p->state) {
        case STATE_IDLE: 
            if(byte == HEADER_BYTE)
            {
                p->state = STATE_LEN;
            }
        break;    /* aspetto 0xAA */


        case STATE_LEN:     /* prossimo byte è la lunghezza */

            if(byte == 0)
            {
                p->state = STATE_CRC;
                p->crc_accum = crc8_update(p->crc_accum, 0);
                break;
            }

            p->len = byte; p->state = STATE_PAYLOAD;
            p->crc_accum = crc8_update(p->crc_accum, byte); 
            break;
        case STATE_PAYLOAD: /* accumulo byte payload */
            p->payload[p->received++] = byte; 
            p->crc_accum = crc8_update(p->crc_accum, byte);
            
            if(p->received == p->len)
            {
                p->state = STATE_CRC;
            } 

            break; 
        case STATE_CRC: /* verifico checksum */


            if(byte == p->crc_accum){
                parser_reset(p);
                p->state = STATE_DONE;
                return p->state;
            }
            else {
                parser_reset(p);
                p->state = STATE_ERROR;
                return p->state;
            }
        case STATE_DONE:
            break;
        case STATE_ERROR:
            break;
    }

    return 0;
}

void parser_reset (Parser_t *p)
{
    p->crc_accum = 0;
    p->len = 0;
    p->received = 0;
    p->state = STATE_IDLE;
}