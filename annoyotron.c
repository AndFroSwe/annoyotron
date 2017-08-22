/* File: annoyotron.c
 * Author: andfro
 * Description: Sends out high pitched noises with irregular intervals. just to 
 * annoy people.
 */

#include <avr/io.h>

int main(int argc, char *argv[])
{
    DDRD |= 1 << PD6;
    /*PORTD |= 1 << PD6;*/

    // Setup PWM
    /*TCCR0B |= _BV(CS00) | _BV(CS02); // Clock source, prescaler 1024*/
    TCCR0B |= _BV(CS00); // Clock source, prescaler 1024
    TCCR0A |= _BV(WGM00) | _BV(WGM01); // Wave generator mode Fast PWM
    TCCR0B |= _BV(WGM02); // Toggle on compare match
    TCCR0A |= _BV(COM0A0); // Toggle on compare match
    OCR0A = 50;

    // Main loop
    while(1)
    {

    }

    return 0;
}
