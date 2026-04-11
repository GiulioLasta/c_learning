#include "pool.c"

int main()
{   
    Pool_t pool;

    pool_init(&pool);

    Pool_t *pool1 = pool_alloc(&pool);
    Pool_t *pool2 = pool_alloc(&pool);
    Pool_t *pool3 = pool_alloc(&pool);
    Pool_t *pool4 = pool_alloc(&pool);
    Pool_t *pool5 = pool_alloc(&pool);
    Pool_t *pool6 = pool_alloc(&pool);
    Pool_t *pool7 = pool_alloc(&pool);
    Pool_t *pool8 = pool_alloc(&pool);
    Pool_t *pool9 = pool_alloc(&pool);
    Pool_t *pool10 = pool_alloc(&pool);
    Pool_t *pool11 = pool_alloc(&pool);
    Pool_t *pool12 = pool_alloc(&pool);
    Pool_t *pool13 = pool_alloc(&pool);
    Pool_t *pool14 = pool_alloc(&pool);
    Pool_t *pool15 = pool_alloc(&pool);

    Pool_t *tmp1 = pool_alloc(&pool);
    printf("%p\n", tmp1);

    Pool_t *tmp2 = pool_alloc(&pool);
    printf("%p\n", tmp2);


    printf("free count before free: %d\n", pool_free_count(&pool));

    printf("Pointer 11 before free: %p\n", pool11);
    pool_free(&pool, pool11);
    printf("Pointer 11 after free: %p\n", pool11);
    pool11 = NULL;
    
    printf("free count dopo free: %d\n", pool_free_count(&pool));

}   