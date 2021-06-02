#include<stdio.h>
int main()
{
int num1,num2,temp;
printf("\n enter first number:");
scanf("%d",&num1);
printf("\n enter second number:");
scanf("%d",&num2);
temp=num1;
num1=num2;
num2=temp;
printf("\n after swap first number:%d",num1);
printf("\n after swap second number:%d",num2);
return 0;
}
