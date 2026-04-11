#include "ring_buffer.h"


void rb_init (RingBuffer_t *rb)
{
    rb->count = 0;
    rb->head = 0;
    rb->tail = 0;
}

int rb_push (RingBuffer_t *rb, uint8_t byte)  /* 0=ok, -1=full */
{
    if(rb->count == RB_SIZE)
    {
        return -1;
    }

    rb->buf[rb->head & (RB_SIZE - 1)] = byte;
    rb->head++;
    ++rb->count;

    return 0;
}


int rb_pop (RingBuffer_t *rb, uint8_t *byte) /* 0=ok, -1=empty */
{
    if(rb->count == 0)
    {
        return -1;
    }

    printf("%ld\n", rb->tail & (RB_SIZE - 1));

    *byte = rb->buf[rb->tail & (RB_SIZE - 1)];

    rb->tail++;
    --rb->count;

    return 0;
}


int rb_full (RingBuffer_t *rb)
{
    if(rb->count == RB_SIZE) 
    {
        return 1;
    }
    return 0;
}


int rb_empty(RingBuffer_t *rb)
{
    return rb->count == 0;
}


size_t rb_count(RingBuffer_t *rb)
{
    return rb->count;
}

// #define RB_SIZE 16   /* deve essere potenza di 2 */

// typedef struct {
//     volatile uint8_t buf[RB_SIZE];
//     volatile size_t  head;   /* ISR scrive qui */
//     volatile size_t  tail;   /* main legge qui */
//     volatile size_t  count;
// } RingBuffer_t;

