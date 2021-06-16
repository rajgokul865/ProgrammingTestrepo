#include<stdio.h>
long long overtakes(int N,int *A)
{
	int i,j;
	//int count[N];
	long long count =0;
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			//printf("*(A + %d) = %d   *(A + %d) = %d\n",i,*(A+i),j,*(A+j));
			if((*(A+i)) > (*(A+i+1)))
			{
				count=count +1;
			}
		}
	}
	return count;
}
int main()
{
	int n;
	long long op;
	printf("enter the value of n:");
	scanf("%d",&n);
	int array[n];
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	op = overtakes(n,array);
	printf("no of overtakes:%lld",op);
}