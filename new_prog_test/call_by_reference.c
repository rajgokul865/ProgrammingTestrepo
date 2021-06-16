#include<stdio.h>
void increment(int *var)
{
*var = 1 + *var ;
}
int main()
{
int num=20;
increment(&num);
printf("output=%d",num);
return 0;
}

