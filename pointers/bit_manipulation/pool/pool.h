#include <stdint.h>
#include <stdio.h>

#define BLOCK_SIZE  32     /* byte per blocco */
#define POOL_BLOCKS 16     /* numero di blocchi */

typedef struct FreeNode {
    struct FreeNode *next;
} FreeNode_t;

typedef struct {
    uint8_t     buf[BLOCK_SIZE * POOL_BLOCKS]; // 32 * 16 * 8
    FreeNode_t *free_head; // 16
    size_t      free_count; // 32
} Pool_t;

void  pool_init (Pool_t *pool);
void *pool_alloc(Pool_t *pool);
void  pool_free (Pool_t *pool, void *ptr);
int   pool_free_count(Pool_t *pool);