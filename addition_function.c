#include<stdio.h>
int addition(int var1,int var2)
{
int sum = var1 + var2 ;
return sum;
}
int main()
{
int num1,num2;
printf("\n enter first number:");
scanf("%d",&num1);
printf("\n enter second number:");
scanf("%d",&num2);
int result = addition(num1,num2);
printf(" output : %d \n",result);
return 0;
}
