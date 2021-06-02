#include<stdio.h>

int main()
{
	int i,j,n=5,m=7;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{

			if(((m-i)==6 || (m-i)==2) && ((m-j)==3))
			{
				printf("*");
			}
			else if(((m-i)==5 || (m-i)==3) && ((m-j)==4 || (m-j)==2))
			{
				printf("*");
			}
			else if((m-i)==4 && ((m-j)==6 || (m-j)==0))
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
