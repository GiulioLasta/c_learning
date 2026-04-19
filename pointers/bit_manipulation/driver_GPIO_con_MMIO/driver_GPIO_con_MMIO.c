#include "driver_GPIO_con_MMIO.h"

void gpio_init      (GPIO_Bank_t *gpio)
{
    gpio->CLR = 0;
    gpio->DIR = 0;
    gpio->IN = 0;
    gpio->OUT = 0;
    gpio->SET = 0;
}


void gpio_set_output(GPIO_Bank_t *gpio, uint8_t pin)
{
    gpio->DIR = gpio->DIR | (1u << pin);
}

void gpio_set_input (GPIO_Bank_t *gpio, uint8_t pin)
{
    gpio->DIR = gpio->DIR & ~(1u << pin);
}


void gpio_set       (GPIO_Bank_t *gpio, uint8_t pin)
{
    gpio->SET = gpio->SET | (1u << pin);
}

void gpio_clear     (GPIO_Bank_t *gpio, uint8_t pin)
{
    gpio->CLR = gpio->CLR | (1u << pin);
}


void gpio_toggle    (GPIO_Bank_t *gpio, uint8_t pin)
{
    gpio->OUT = gpio->OUT ^ (1u << pin);
}
int  gpio_read      (GPIO_Bank_t *gpio, uint8_t pin)
{
    return (gpio->IN >> pin) & 1u;
}

void gpio_sync      (GPIO_Bank_t *gpio)
{
    gpio->OUT |= gpio->SET;
    gpio->OUT &= ~gpio->CLR;

    gpio->SET = 0;
    gpio->CLR = 0;

    gpio->IN = gpio->OUT;
}