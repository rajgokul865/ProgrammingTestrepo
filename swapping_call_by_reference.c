#include<stdio.h>
void swap(int *num1,int *num2)
{
int temp;
temp=*num1;
*num1=*num2;
*num2=temp;
}
int main()
{
int var1=45,var2=30;
printf("\n the numbers before swap: %d,%d",var1,var2);
swap(&var1,&var2);
printf("\n the numbers after swap: %d,%d",var1,var2);
return 0;
}

