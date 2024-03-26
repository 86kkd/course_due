#include <8051.h>

__xdata unsigned int __at(0x7FFF) input1;//P2_7=0
__xdata unsigned int __at(0xBFFE) input2;//P2_6=0
__xdata unsigned int __at(0xDFFF) start;//P2_5=0
typedef unsigned char byte;

void delay(void)
{
	unsigned int j;
	for (j = 0; j++; j < 1000)
	{
	};
}
void main(void){
    byte i;
    while (1)
    {
        for (i = 0; i < 255; i++){
            input1 = i;
            input2 = i;
            delay();
            start = i;
        }
    }
    
}