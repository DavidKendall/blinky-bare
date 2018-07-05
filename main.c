#include <stdint.h>
#include <stdbool.h>

/* Register address and mask definitions for the 
 * System Clock Gating Control Register 5 
 * See reference manual, chapter 12, pp 273ff
 */
#define SIM_SCGC5            (*((volatile uint32_t *)(0x40048038u)))
#define SIM_SCGC5_PORTB_MASK (1u << 10)

/* Register address and mask definitions for the Pin Control Register for
 * pin 21 in PORT B
 * See the reference manual, chapter 10, pp 243ff, and chapter 11, pp 273ff
 */ 
#define PORTB_PCR21          (*((volatile uint32_t *)(0x4004A054u)))
#define PORTx_PCRn_MUX_MASK  (0x0700u)
#define MUX_ALT1_MASK        (1u << 8)

/* Register address and mask definitions for GPIO PORT B 
 * Port Data Direction Register and Port Data Output Register
 * See the reference manual, chapter 55, pp 1757ff
 */ 
#define GPIOB_PDDR           (*((volatile uint32_t *)(0x400FF054u)))
#define GPIOB_PDOR           (*((volatile uint32_t *)(0x400FF040u)))
#define PIN21_MASK           (1u << 21)

void led_blue_init(void);
void led_blue_on(void);
void led_blue_off(void);
void led_blue_toggle(void);
void delay(int count);

int main(void)
{
    led_blue_init();

    while (true) {
	led_blue_on();
    	delay(1000);
	led_blue_off();
	delay(1000);
    }
    return 0;
}

void led_blue_init(void) {
    /* Enable the clock to PORT B */
    SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;

    /* Select the GPIO function (Alternative 1) for pin 21 of PORT B */
    PORTB_PCR21 &= ~PORTx_PCRn_MUX_MASK;
    PORTB_PCR21 |= MUX_ALT1_MASK;

    /* Set the data direction for pin 21 of PORT B to output */
    GPIOB_PDDR |= PIN21_MASK;
}

void led_blue_on(void) {
    GPIOB_PDOR &= ~PIN21_MASK; 
}

void led_blue_off(void) {
    GPIOB_PDOR |= PIN21_MASK; 
}

void led_blue_toggle(void) {
    GPIOB_PDOR ^= PIN21_MASK; 
}

void delay(int count) {
    int i = 0;
    for (i = count*1000 ; i !=0; i--) {
	/* skip */
    }
}
