#include "cooperative_task_scheduler.h"
#include <time.h>
#include <stdio.h>

uint64_t now_ms(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

void scheduler_init(Scheduler_t *s)
{
    s->count = 0;
}

int scheduler_add(Scheduler_t *s,
                   task_fn_t fn,
                   uint32_t period_ms)
{
    if(s->count == MAX_TASKS)
        return -1;

    s->tasks[s->count].fn = fn;
    s->tasks[s->count].period_ms = period_ms;
    s->tasks[s->count].last_run_ms = 0;
    s->tasks[s->count].enabled = 1;
    return s->count++;
}

void scheduler_run(Scheduler_t *s)   /* chiama una volta nel loop */
{
    for (size_t i = 0; i < s->count; i++)
    {
        if(now_ms() - s->tasks[i].last_run_ms >= s->tasks[i].period_ms && s->tasks[i].enabled == 1)
        {
            printf("Before running task: %ld\n", now_ms());

            s->tasks[i].fn();

            printf("After running task: %ld\n", now_ms());

            s->tasks[i].last_run_ms = now_ms();
        }
    }
}


void scheduler_enable (Scheduler_t *s, int id)
{
    s->tasks[id].enabled = 1;
}

void scheduler_disable(Scheduler_t *s, int id)
{
    s->tasks[id].enabled = 0;
}

/*

typedef void (*task_fn_t)(void);   /* puntatore a funzione 

typedef struct {
    task_fn_t fn;           /* funzione da eseguire 
    uint32_t  period_ms;    /* ogni quanti ms eseguire 
    uint64_t  last_run_ms;  /* timestamp ultima esecuzione 
    int       enabled;      /* 0 = disabilitato 
} Task_t;

typedef struct {
    Task_t tasks[MAX_TASKS];
    size_t count;
} Scheduler_t;

void scheduler_init(Scheduler_t *s); */