#include <8051.h>

typedef unsigned char byte;

const unsigned int in_address[8] = {0xFE00, 0xFE01, 0xFE02, 0xFE03, 0xFE04, 0xFE05, 0xFE06, 0xFE07};
__xdata unsigned int *pointer;
byte out[8];
byte num = 0;

void delay_ms(unsigned int t);
void time_init()
{
    TMOD = 0x10; // Timer 0 mode 1, 8-bit reload
    TH0 = 0xFF;  // Set timer 0 high byte to 0xFF
}

void main()
{
    TMOD = 0x10; // Timer 0 mode 1, 8-bit reload
    TH0 = 0xFF;  // Set timer 0 high byte to 0xFF
    EA = 1;      // Enable interrupts
    ET0 = 1;     // Enable timer 0 interrupt
    TR0 = 1;     // Start timer 0

    while (1)
    {
    }
}

void timer0_interrupt() __interrupt(1)
{
    time_init(); // Reinitialize timer 0
    if (num < 1)
        num++;
    else
    {
        for (byte i = 0; i < 8; i++)
        {   
            pointer = in_address[i]; // Set pointer to input address
            out[i] = *pointer; // Read input data
            delay_ms(100); // Simulate delay
        }
    }
}
void delay_ms(unsigned int t)
{
    unsigned int i, j;
    for (i = 0; i < t; i++)
    {
        for (j = 0; j < 1000; j++)
        {
        }
    }
}