#include <stdint.h>
#include <stdio.h>

typedef struct {
    volatile uint32_t       DIR;
    volatile uint32_t       OUT;
    volatile uint32_t       IN;
    volatile uint32_t       SET;
    volatile uint32_t       CLR;
} GPIO_Bank_t;

void gpio_init      (GPIO_Bank_t *gpio);
void gpio_set_output(GPIO_Bank_t *gpio, uint8_t pin);
void gpio_set_input (GPIO_Bank_t *gpio, uint8_t pin);
void gpio_set       (GPIO_Bank_t *gpio, uint8_t pin);
void gpio_clear     (GPIO_Bank_t *gpio, uint8_t pin);
void gpio_toggle    (GPIO_Bank_t *gpio, uint8_t pin);
int  gpio_read      (GPIO_Bank_t *gpio, uint8_t pin);
void gpio_sync      (GPIO_Bank_t *gpio);