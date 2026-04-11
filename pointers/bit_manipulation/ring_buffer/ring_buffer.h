#include <stdint.h>
#include <stdio.h>

#define RB_SIZE 16   /* deve essere potenza di 2 */

typedef struct {
    volatile uint8_t buf[RB_SIZE];
    volatile size_t  head;   /* ISR scrive qui */
    volatile size_t  tail;   /* main legge qui */
    volatile size_t  count;
} RingBuffer_t;

void    rb_init (RingBuffer_t *rb);
int     rb_push (RingBuffer_t *rb, uint8_t byte);  /* 0=ok, -1=full */
int     rb_pop  (RingBuffer_t *rb, uint8_t *byte); /* 0=ok, -1=empty */
int     rb_full (RingBuffer_t *rb);
int     rb_empty(RingBuffer_t *rb);
size_t  rb_count(RingBuffer_t *rb);