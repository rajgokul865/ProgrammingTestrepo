#include<stdio.h>
int main(int argc,char* argv[])
{
	int i,j,n,count=0;
	printf("enter the size:");
	scanf("%d",&n);
	char name[n][50];
	int age[n];
	for(i=1;i<=n;i++)
	{
		printf("Enter the name:");
		//fflush(stdin);
		//scanf("%s",name[i]);
		scanf("%s",name[i]);
		//fgets(name[i],50,stdin);
		//fflush(stdin);
		printf("Enter the age:");
		//fflush(stdin);
		scanf("%d",&age[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(age[i]>35)
		{
			printf("\n%s with age %d\n",name[i],age[i]);
			count=count+1;
		}
	}
	if(count==0)
	{
		printf("\nnot found!\n");
	}
	printf("argc = %d,arv[0]= %s",argc,argv[1]);
}