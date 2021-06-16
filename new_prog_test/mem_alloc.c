#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	printf("enter the size of string:");
	scanf("%d",&n);
	char *ptr1;//*ptr2;
	//ptr1 = (char*)malloc(n * sizeof(char));
	if(ptr1==NULL)
	{
		printf("memory not available\n");
	}
	else
	{
		//ptr1 = "string";
		for(i=0;i<n;i++)
		{
			ptr1 = "string";
			//scanf("%s",ptr1);
			//ptr1++;
		}
		printf("string is %s\n",ptr1);
	}
	//free(ptr1);
}