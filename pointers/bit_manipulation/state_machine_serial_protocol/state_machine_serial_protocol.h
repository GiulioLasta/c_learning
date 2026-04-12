#include <stdint.h>
#include <stdio.h>

#define MAX_PAYLOAD 64
#define HEADER_BYTE 0xAA

typedef enum {
    STATE_IDLE,
    STATE_LEN,
    STATE_PAYLOAD,
    STATE_CRC,
    STATE_DONE,
    STATE_ERROR
} ParserState_t;

typedef struct {
    ParserState_t state;
    uint8_t       payload[MAX_PAYLOAD];
    uint8_t       len;
    uint8_t       received;   /* byte payload ricevuti finora */
    uint8_t       crc_accum;  /* CRC accumulato durante ricezione */
} Parser_t;

void parser_init  (Parser_t *p);
int  parser_feed  (Parser_t *p, uint8_t byte); /* 0=ok, 1=done, -1=error */
void parser_reset (Parser_t *p);
