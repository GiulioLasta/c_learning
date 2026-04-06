#include "pool.h"

// collega tutti i blocchi in una free list. Ogni blocco punta al successivo, l'ultimo punta a NULL.
void  pool_init (Pool_t *pool)
{
    FreeNode_t *tmp = NULL;
    for (int i = POOL_BLOCKS - 1; i >= 0; i--)
    {
        FreeNode_t *node = (FreeNode_t *)(pool->buf + i * BLOCK_SIZE);
        node->next = tmp;
        tmp = node;
    }

    pool->free_head = tmp;
}

/*

* typedef struct {
    uint8_t     buf[BLOCK_SIZE * POOL_BLOCKS];
    FreeNode_t *free_head;
    size_t      free_count;
} Pool_t;

 */