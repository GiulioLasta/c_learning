#include "state_machine_serial_protocol.c"

int main()
{   
    Parser_t p;

    parser_init(&p);

    uint8_t payload[16];

    payload[0] = 0xAA; // header
    payload[1] = 3; // len
    uint8_t cr8 = crc8_update(0, 3); // correct
    // uint8_t cr8 = crc8_update(0, 12); // wrong
    payload[2] = 1; // payload
    cr8 = crc8_update(cr8, 1);
    payload[3] = 2; // payload
    cr8 = crc8_update(cr8, 2);
    payload[4] = 4; // payload
    cr8 = crc8_update(cr8, 4);
    
    // payload[4] = cr8; // CRM
    payload[5] = cr8; // CRM
    
    printf("State : %d\n", p.state);

    parser_feed(&p, payload[0]);

    printf("State : %d\n", p.state);
    parser_feed(&p, payload[1]);

    printf("State : %d\n", p.state);
    parser_feed(&p, payload[2]);

    printf("State : %d\n", p.state);
    parser_feed(&p, payload[3]);
    parser_feed(&p, payload[4]);
    parser_feed(&p, payload[5]);

    printf("Length: %d\n", p.len);
    printf("Payload : %d\n", p.payload[0]);
    printf("Payload : %d\n", p.payload[1]);
    printf("Payload : %d\n", p.payload[2]);
    printf("Payload : %d\n", p.payload[3]);
    printf("Payload : %d\n", p.payload[4]);


    printf("State : %d\n", p.state);

}   