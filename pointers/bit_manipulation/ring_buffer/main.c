
#include "ring_buffer.c"

int main()
{   
    RingBuffer_t ring_buffer;

    rb_init(&ring_buffer);

    int res1 = rb_push(&ring_buffer, 12);
    printf("First push: %d\n", res1);

    int res2 = rb_push(&ring_buffer, 23);
    printf("Second push: %d\n", res2);

    uint8_t tail1;
    rb_pop(&ring_buffer, &tail1);
    printf("First pop: %d\n", tail1);

    uint8_t tail2;
    rb_pop(&ring_buffer, &tail2);
    printf("Second pop: %d\n", tail2);


    printf("Is full: %d\n", rb_full(&ring_buffer));
    printf("Is empty: %d\n", rb_empty(&ring_buffer));
    printf("Count: %ld\n", rb_count(&ring_buffer));



    uint8_t tail3;
    rb_pop(&ring_buffer, &tail3);
    printf("Third pop: %d\n", tail3);


    rb_push(&ring_buffer, 1);
    rb_push(&ring_buffer, 2);
    rb_push(&ring_buffer, 3);
    rb_push(&ring_buffer, 4);
    rb_push(&ring_buffer, 5);
    rb_push(&ring_buffer, 6);
    rb_push(&ring_buffer, 7);
    rb_push(&ring_buffer, 8);
    rb_push(&ring_buffer, 9);
    rb_push(&ring_buffer, 10);
    rb_push(&ring_buffer, 11);
    rb_push(&ring_buffer, 12);
    rb_push(&ring_buffer, 13);
    rb_push(&ring_buffer, 14);
    rb_push(&ring_buffer, 15);


    int res16 = rb_push(&ring_buffer, 16); // 16
    printf("16th push: %d\n", res16);

    int res17 = rb_push(&ring_buffer, 17); // 17
    printf("17th push: %d\n", res17);

    uint8_t tail4;

    for (size_t i = 0; i < RB_SIZE; i++)
    {
        rb_pop(&ring_buffer, &tail4);
        printf("%ldth pop: %d\n", i, tail4);
    }
    

}   