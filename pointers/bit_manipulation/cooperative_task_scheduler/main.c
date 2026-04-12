#include "cooperative_task_scheduler.c"
#include <time.h>

void read_sensor()
{
    printf("read_sensor\n");
}
void print_on_screen()
{
    printf("print_on_screen\n");
}

void send_data()
{
    printf("send_data\n");
}

int main()
{   
    Scheduler_t scheduler;
    uint64_t start = now_ms();

    scheduler_init(&scheduler);

    scheduler_add(&scheduler, read_sensor, 200);
    int id = scheduler_add(&scheduler, print_on_screen, 500);
    scheduler_add(&scheduler, send_data, 1000);

    
    while(now_ms() - start < 3000) {
        if(now_ms() - start >= 1500)
            scheduler_disable(&scheduler, id);
        
        scheduler_run(&scheduler);
    }
}