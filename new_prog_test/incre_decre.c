#include<stdio.h>
int main()
{
	int x =20, y= 35;

	//x++;
	x = y++ + x++;
	y = ++y + ++x;
	printf("%d %d\n",x,y);
	return 0;
}