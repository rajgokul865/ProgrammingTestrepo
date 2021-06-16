#include<stdio.h>
//#define swap(a,b) a=a+b;b=a-b;a=a-b;
int swap2(int *,int *);
void main()
{
    int x=5, y=10,ret;
//swap (x,y);
//printf(%d %dn,x,y);
    //printf(%d,%d,%dn,x,x< >2);
    //printf("%d %d %d\n",x,x< >2);
    ret = swap2(&x,&y);
    printf("%d %d %d\n", x, y,ret);


}

int swap2(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}