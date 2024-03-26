#include <8051.h>

typedef unsigned char bit8;

bit8 wordbuf[4]; // �����뻺����
void delay(); // ����
void read_digpot(__sbit PIN, bit8 index);

void main(void)
{

	IT0 = 1; //	�ж�0�½��ش���
	EA = 1;
	EX0 = 1; // �ж�0���ж�
	IT1 = 1;
	EX1 = 1;

	P1 = 0xff;
}

void int1(void) __interrupt(1)
{
	read_signal(); // ��ȡת�����
	EX1 = 1; // �ж�1��
}
void read_signal(void)
{
	read_digpot(P1_4, 0); // ��ȡ��һλ/���λ
	read_digpot(P1_5, 1); // ��ȡ�ڶ�λ
	read_digpot(P1_6, 2); // ��ȡ����λ
	read_digpot(P1_7, 3); // ��ȡ����λ
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
