#include<stdio.h>
int main()
{
	int i,n;
	printf("enter the size:");
	scanf("%d",&n);
	char str[n][50];
	//char *ptr;
	//ptr = str[0];
	for(i=0;i<n;i++)
	{
		//ptr = str[i];
		scanf("%s",str[i]);
		//printf("1st %s\n",ptr);//(ptr+i));
		//ptr++;
		//printf("2nd %s\n",ptr);
	}
	//ptr = str[0];
	for(i=0;i<n;i++)
	{
		//ptr = str[i];
		printf("\n%s\n",str[i]);
		//ptr++;
	}
}