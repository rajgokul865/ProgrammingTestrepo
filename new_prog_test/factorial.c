#include<stdio.h>
int main()
{
	int i,num,fact;
	char ch;
	do
	{
		printf("Enter any positive Integer:");
		scanf("%d",&num);

		if(num==0)
		{
			printf("0 factorial is 1\n");
		}	
		else if(num>0)
		{
			fact=1;
			for(i=num;i>=1;i--)
			{
				fact=fact*i;
			}
			printf("%d factorial is %d\n",num,fact);
		}
		else
		{
			printf("Invalid number");
		}
		printf("Do you want to check another number:(y/n)");
		scanf(" %c",&ch);
	}while(ch=='y'||ch=='Y');
	//printf("%d factorial is %d\n",num,fact);
	return 0;
}
