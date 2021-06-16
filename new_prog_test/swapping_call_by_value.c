#include<stdio.h>
void swap(int var1,int var2)
{
int temp;
temp=var1;
var1=var2;
var2=temp;
}
int main()
{
int num1=20,num2=30;
printf("\n values before swap:");
printf("\n num1,num2:%d,%d",num1,num2);
swap(num1,num2);
printf("\n values after swap:");
printf("\n num1,num2:%d,%d",num1,num2);
}

