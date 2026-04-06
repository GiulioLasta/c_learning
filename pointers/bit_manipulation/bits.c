#include <stdio.h>
#include <stdint.h>


uint32_t bit_set (uint32_t reg, uint8_t pos)
{
    return reg | (1u << pos);
}

uint32_t bit_clear (uint32_t reg, uint8_t pos)
{
    return reg & ~(1u << pos);
}

// 00001000000
// 11110111111

// &&

// 10111111111


uint32_t bit_toggle(uint32_t reg, uint8_t pos)
{
    return reg ^ (1u << pos);
}
// &   AND
// |   OR
// ^   XOR
// ~   NOT (inverte tutti i bit)
// <<  shift sinistra
// >>  shift destra

//     00000000001
// pos 00001000000

// &&

// reg 10111111111

// pos 00000000000


int bit_check (uint32_t reg, uint8_t pos)  /* 0 o 1 */
{
    return (reg >> pos) & 1u;
}


/* --- rotazioni (no UB, a differenza di shift) --- */
uint32_t bit_rotl(uint32_t val, uint8_t n)
{
    // 01001101 original
    // 00110100 shiftato l 2
    // 00000001 shiftato r 8-2
    // 00110101 wanted res

    return (val >> (32 - n)) | (val << n);
}


uint32_t bit_rotr(uint32_t val, uint8_t n)
{
    return (val << (32 - n)) | (val >> n);
}


/* --- conteggio e ricerca --- */
int bit_popcount(uint32_t val)   /* numero di bit a 1 */
{
    // 01001101 original

    // 01001100 val - 1
    // 01001100 AND tra i due

    int cnt=0;
    while (val > 0) {
        val = val & (val - 1);
        cnt++;
    }
    return cnt;

    // 10110010 NOT


    // res 4
}

    int bit_ffs (uint32_t val)   /* first set, 1-indexed, 0 se nessuno */
    {
        // 01001100 val
        for (int i = 0; i < 32; i++)
        {
            if ((val >> i) & 1u)
                return i + 1;
        }
        return 0;
    }


int bit_fls (uint32_t val)   /* last  set, 1-indexed, 0 se nessuno */
{
    // 01001100 val
    for (int i = 31; i >= 0; i--)
    {
        if ((val >> i) & 1u)
            return i + 1;
    }
    return 0;
}

uint32_t bf_read (uint32_t reg, uint8_t start, uint8_t len)
{
    uint32_t tmp  = (reg >> start);
    uint32_t mask = (1u << len) - 1;
    return tmp & mask;
}


uint32_t bf_write(uint32_t reg, uint8_t start, uint8_t len, uint32_t val)
{
    // 01001100 reg - 5 3 101
    uint32_t mask = ((1u << len) - 1) << start;
    // 00000111 // 11000000
    reg = reg & ~mask;
    // 01001100 AND NOT 11000000
    // 01001100 AND 00111111
    // 00011100


    uint32_t aaa = (val << (start-len)); // se val 101 --> 00101000


    return aaa | bbb;
    // uint32_t mask = (1u << start) - 1;        // 000111111
    // uint32_t mask2 = (1u << (start-len)) - 1; // 000001111
    // uint32_t maskXOR = mask ^ mask2;          // 000110000
    // uint32_t maskAND = ~maskXOR;              // 111001111

    // reg = reg & maskAND;    

    // uint32_t maskVal = (val << start);        // 000100000

    // return maskVal | maskAND;
}

/*
uint32_t mask = (1u << start) - 1;        // 000111111
    uint32_t mask2 = (1u << (start-len)) - 1; // 000001111
    uint32_t maskXOR = mask ^ mask2;          // 000110000
    uint32_t maskAND = ~maskXOR;              // 111001111

    reg = reg & maskAND;    

    uint32_t maskVal = (val << start);        // 000100000

    return maskVal | maskAND;
     */

int main(int argc, char *argv[])
{


}