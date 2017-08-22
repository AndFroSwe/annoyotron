/* File: annoyotron.c
 * Author: andfro
 * Description: Sends out high pitched noises with irregular intervals. just to 
 * annoy people.
 */

#define MAX_WAIT_MINUTES 10 // The maximum amount of minutes to wait before new tone

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main(int argc, char *argv[])
{
    DDRD |= 1 << PD6; // Enable PWM oscillator flag

    // Setup PWM
    /*TCCR0B |= _BV(CS00) | _BV(CS02); // Clock source, prescaler 1024*/
    TCCR0B |= _BV(CS00); // Clock source, prescaler 1024
    TCCR0A |= _BV(WGM00) | _BV(WGM01); // Wave generator mode Fast PWM
    TCCR0B |= _BV(WGM02); // Toggle on compare match
    TCCR0A |= _BV(COM0A0); // Toggle on compare match
    OCR0A = 40; // This yields approx 10 kHz signal

    // Main loop
    int wait_minutes = 5;
    while(1)
    {
        // Make a tone
        _delay_ms(500);
        TCCR0B &= ~_BV(WGM02); // PWM off
        // Wait until next tone
        int i;
        for (i = 0; i < wait_minutes; ++i)
        {
            _delay_ms(60000);
        }
        TCCR0B |= _BV(WGM02); // PWM on
        wait_minutes = ++wait_minutes%MAX_WAIT_MINUTES;
    }

    return 0;
}
