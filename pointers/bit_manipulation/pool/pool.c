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
    pool->free_count = POOL_BLOCKS;

    pool->free_head = tmp;
}

void *pool_alloc(Pool_t *pool)
{
    FreeNode_t *tmp = pool->free_head;

    if(tmp == NULL)
    {
        return NULL;
    }

    pool->free_head = tmp->next;
    pool->free_count--;

    return tmp;
}

void  pool_free (Pool_t *pool, void *ptr)
{
    FreeNode_t *tmp = pool->free_head;
    pool->free_head = ptr;
    pool->free_head->next = tmp;
    pool->free_count++;
}

int   pool_free_count(Pool_t *pool)
{
    return pool->free_count;
}

/*

typedef struct FreeNode {
    struct FreeNode *next;
} FreeNode_t;

typedef struct {
    uint8_t     buf[BLOCK_SIZE * POOL_BLOCKS]; // 32 * 16 * 8
    FreeNode_t *free_head; // 16
    size_t      free_count; // 32
} Pool_t;

 */