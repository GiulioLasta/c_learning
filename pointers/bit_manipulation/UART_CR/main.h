#include <stdint.h>
#include <stdio.h>


typedef struct {
    uint32_t EN      : 1;
    uint32_t TXEN    : 1;
    uint32_t RXEN    : 1;
    uint32_t STOP    : 1;
    uint32_t PARITY  : 2;
    uint32_t WORDLEN : 2;
    uint32_t reserved: 24;
} UART_CR_bits_t;

// 00100011 = 0x23 = 35

typedef union {
    UART_CR_bits_t bits;
    uint32_t       raw;
} UART_CR_t;


uint32_t get_EN(UART_CR_bits_t * pointer);
void set_EN(UART_CR_bits_t * pointer, uint32_t val);

uint32_t get_TXEN(UART_CR_bits_t * pointer);
void set_TXEN(UART_CR_bits_t * pointer, uint32_t val);

uint32_t get_RXEN(UART_CR_bits_t * pointer);
void set_RXEN(UART_CR_bits_t * pointer, uint32_t val);

uint32_t get_STOP(UART_CR_bits_t * pointer);
void set_STOP(UART_CR_bits_t * pointer, uint32_t val);

uint32_t get_PARITY(UART_CR_bits_t * pointer);
void set_PARITY(UART_CR_bits_t * pointer, uint32_t val);

uint32_t get_WORDLEN(UART_CR_bits_t * pointer);
void set_WORDLEN(UART_CR_bits_t * pointer, uint32_t val);