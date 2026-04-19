#include "driver_GPIO_con_MMIO.c"

int main()
{   
    GPIO_Bank_t gpio;
    gpio_init(&gpio);

    uint8_t pinOUT = 3;
    uint8_t pinIN = 5;

    gpio_set_output(&gpio, pinOUT);
    gpio_set_input (&gpio, pinIN);


    gpio_set(&gpio, 3);    //  ← scrivi 1 su SET per pin 3
    gpio_sync(&gpio);      //   ← applica SET a OUT, copia in IN
    int res = gpio_read(&gpio, 3);   //   ← deve restituire 1

    printf("Res 3: %d\n", res); // is 1
    printf("Res 5: %d\n", gpio_read(&gpio, 5)); // is 0

    gpio_clear(&gpio, 3);

    gpio_sync(&gpio);      // 
    int resNew = gpio_read(&gpio, 3);   //

    printf("Res 3: %d\n", resNew); // is 0

    for (int i = 0; i < 5; i++) {
        gpio_toggle(&gpio, 3);
        gpio_sync(&gpio);
        printf("toggle %d: %d\n", i, gpio_read(&gpio, 3));
    }

}   