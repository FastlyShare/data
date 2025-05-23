#include <LPC21XX.H>
Vord clock_wise(void);
Void anti_clock_wire(void);
unsigned long int var1, var2
unsigned int i=0, j = 0, k=0;
int main (void)
{
PINSELO = 0X00FFFFFF;
IOO DIR = 0x0000F000; 
while (1) {
for (j=0; j<50; j++)
Clock_wise( );

for(K=0; K<65000; k++);
for(j=0, j<50;j++)
anti_clock_wise( );

for (k=0; k <15000; k++);
}
}
Vold clock_wise(void) {
Var1 = 0x00000800;
for (i=0;i<=3; i++)
{
var1= var1 << 1;
var2= ~var1;
var2=var2 & 0X0000F000;
IO0PIN=~var2;
for (k=0;k<3000, k++);
}
}
Void anti-clock_wise(void)
{
var1 = 0X00010000;
for (i=0;k=3;i++)
{
var1 = var1>>1;
var2 = ~ var1;
var2= var2 & 0x0000F000;
IOOPIN = ~var2;
for (k=0;K<3000; k++)
}
}