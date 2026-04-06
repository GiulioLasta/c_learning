#include "main.h"

uint32_t get_EN(UART_CR_bits_t * pointer)
{
    return (*pointer).EN;
}
void set_EN(UART_CR_bits_t * pointer, uint32_t val)
{
    pointer->EN = val;
}

uint32_t get_TXEN(UART_CR_bits_t * pointer)
{
    return (*pointer).TXEN;
}
void set_TXEN(UART_CR_bits_t * pointer, uint32_t val)
{
    pointer->TXEN = val;
}

uint32_t get_RXEN(UART_CR_bits_t * pointer)
{
    return (*pointer).RXEN;
}
void set_RXEN(UART_CR_bits_t * pointer, uint32_t val)
{
    pointer->RXEN = val;
}

uint32_t get_STOP(UART_CR_bits_t * pointer)
{
    return (*pointer).STOP;
}
void set_STOP(UART_CR_bits_t * pointer, uint32_t val)
{
    pointer->STOP = val;
}

uint32_t get_PARITY(UART_CR_bits_t * pointer)
{
    return (*pointer).PARITY;
}
void set_PARITY(UART_CR_bits_t * pointer, uint32_t val)
{
    pointer->PARITY = val;
}

uint32_t get_WORDLEN(UART_CR_bits_t * pointer)
{
    return (*pointer).WORDLEN;
}
void set_WORDLEN(UART_CR_bits_t * pointer, uint32_t val)
{
    pointer->WORDLEN = val;
}

uint32_t bf_read (UART_CR_t * pointer, uint8_t start, uint8_t len)
{
    uint32_t tmp  = (pointer->raw >> start);
    uint32_t mask = (1u << len) - 1;
    return tmp & mask;
}

uint32_t bf_write(UART_CR_t * pointer, uint8_t start, uint8_t len, uint32_t val)
{
    uint32_t mask = ((1u << len) - 1) << start;
    pointer->raw = pointer->raw & ~mask;
    return pointer->raw = pointer->raw | (val << (start));
}

int main()
{
    UART_CR_bits_t mem;
    printf("%ld\n", sizeof(mem));

    UART_CR_t reg;
    reg.raw = 0;
    set_EN(&reg.bits, 1);
    printf("0x%08X\n", reg.raw);

    set_TXEN(&reg.bits, 1);
    printf("0x%08X\n", reg.raw);

    set_PARITY(&reg.bits, 2);
    printf("0x%08X\n", reg.raw);

    printf("TXEN: %d\n", bf_read(&reg, 1, 1));

    bf_write(&reg, 1, 1, 0);
    printf("TXEN: %d\n", bf_read(&reg, 1, 1));

    bf_write(&reg, 1, 1, 1);
    printf("TXEN: %d\n", bf_read(&reg, 1, 1));

}