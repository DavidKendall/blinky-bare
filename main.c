#include <stdbool.h>
#include "MK64F12.h"

void led_blue_init(void);
void led_blue_toggle(void);
void delay(int count);

int main(void)
{
    led_blue_init();

    while (true) {
	led_blue_toggle();
    	delay(2000);
    }
    return 0;
}

void led_blue_init(void) {
    SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; 
    PORTB_PCR21 = PORT_PCR_MUX(1); 
    GPIOB_PDDR |= (1 << 21);
}

void led_blue_toggle(void) {
    GPIOB_PTOR |= (1 << 21); 
}

void delay(int count) {
    int i = 0;
    for (i = count*1000 ; i !=0; i--) {
	/* skip */
    }
}
