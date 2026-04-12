#include <stdint.h>
#include <stddef.h>
#include <time.h>
#define MAX_TASKS 8

typedef void (*task_fn_t)(void);   /* puntatore a funzione */

typedef struct {
    task_fn_t fn;           /* funzione da eseguire */
    uint32_t  period_ms;    /* ogni quanti ms eseguire */
    uint64_t  last_run_ms;  /* timestamp ultima esecuzione */
    int       enabled;      /* 0 = disabilitato */
} Task_t;

typedef struct {
    Task_t tasks[MAX_TASKS];
    size_t count;
} Scheduler_t;

void scheduler_init(Scheduler_t *s);

int  scheduler_add(Scheduler_t *s,
                   task_fn_t fn,
                   uint32_t period_ms);

void scheduler_run(Scheduler_t *s);   /* chiama una volta nel loop */

void scheduler_enable (Scheduler_t *s, int id);
void scheduler_disable(Scheduler_t *s, int id);
