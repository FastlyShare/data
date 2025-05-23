#include <lp21xx.h>
Char * msg = "Hello world \n";
int main()
{
PINSELO = 0X05;
UOLCR=0X83;
U00LL= 0X61;
UODLM = 0X00;
UOLCR=0X03;
while (* msg != 0X00)
{
while (! (UO1SR & 0x20));
U0THR=*msg;
msg ++;
}