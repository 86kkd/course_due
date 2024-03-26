#include <8051.h>

typedef unsigned char bit8;

bit8 wordbuf[4]; // 字型码缓冲区
void delay(); // 保留
void read_digpot(__sbit PIN, bit8 index);

void main(void)
{

	IT0 = 1; //	中断0下降沿触发
	EA = 1;
	EX0 = 1; // 中断0开中断
	IT1 = 1;
	EX1 = 1;

	P1 = 0xff;
}

void int1(void) __interrupt(1)
{
	read_signal(); // 读取转换结果
	EX1 = 1; // 中断1关
}
void read_signal(void)
{
	read_digpot(P1_4, 0); // 读取第一位/最高位
	read_digpot(P1_5, 1); // 读取第二位
	read_digpot(P1_6, 2); // 读取第三位
	read_digpot(P1_7, 3); // 读取第四位
}
void read_digpot(__sbit PIN, bit8 index)
{
	bit8 reg = 0;
	while (PIN == 0)
	{
	}
	delay();
	reg = PIN;
		reg = reg & 0x0f;
	if (reg < 0x0a)
		wordbuf[index] = reg;
}
void delay()
{
	int j;
	for (j = 0; j++; j < 1000)
	{
	};
}
