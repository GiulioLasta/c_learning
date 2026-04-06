#ifndef BITS_H
#define BITS_H

#include <stdint.h>

/* --- operazioni singolo bit --- */
uint32_t bit_set   (uint32_t reg, uint8_t pos);
uint32_t bit_clear (uint32_t reg, uint8_t pos);
uint32_t bit_toggle(uint32_t reg, uint8_t pos);
int      bit_check (uint32_t reg, uint8_t pos);  /* 0 o 1 */

/* --- rotazioni (no UB, a differenza di shift) --- */
uint32_t bit_rotl(uint32_t val, uint8_t n);
uint32_t bit_rotr(uint32_t val, uint8_t n);

/* --- conteggio e ricerca --- */
int bit_popcount(uint32_t val);   /* numero di bit a 1 */
int bit_ffs     (uint32_t val);   /* first set, 1-indexed, 0 se nessuno */
int bit_fls     (uint32_t val);   /* last  set, 1-indexed, 0 se nessuno */

/* --- campi a più bit (bitfield manuale) --- */
uint32_t bf_read (uint32_t reg, uint8_t start, uint8_t len);
uint32_t bf_write(uint32_t reg, uint8_t start, uint8_t len, uint32_t val);

#endif