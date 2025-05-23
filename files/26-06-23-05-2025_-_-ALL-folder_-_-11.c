#include <PC21xx.h>
unsigned int delay;

int main()
{
PINSEL0 = 0x00000000; 
PINSEL1 = 0x00000000; 
IODIR = 0x00000200;
while (1)
    {
IOCLR = 0x00000200; 
for (delay = 0; delay <500000; delay++);
for (delay = 0; delay <500000; delay++);
IOSET = 0x00000200;
for (delay = 0; delay <500000; delay++);
for (delay = 0; delay <500000; delay++);
    }
}