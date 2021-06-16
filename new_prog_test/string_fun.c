#include<stdio.h>

char* reverse(char *str)
{
	static char strrev[50];
	static int i = 0;
	//char *ptr;
	//ptr = strrev;
	//static int j;
	//printf("%c",str[1]);
	//static int count =0;
	//count = n;
	//for(i=0;i<n;i++);
	/*for(i=0;str[i]!='\0';i++)
	{
		count=count+1;
	}

	printf("string length is %d\n",count);*/
	if(*str)
	{//strrev[i]=str[n-1];
		//*ptr++;
		//i++;
		//printf("n is %d \n",n);
		reverse(str + 1);
		//printf("%c",*str);
		strrev[i++] = *str;
	}
	//strrev[count] = '\0';
	//printf("n is %d \n",n);
	//printf("reverse of string is %s\n",strrev);
	return strrev;
}
int main()
{
	char str1[50],str2[50];
	int i,j,count=0;
	char *rev;
	printf("enter the string:");
	scanf("%s",str1);
	printf("string is %s\n",str1);
	for(i=0;str1[i]!='\0';i++)
	{
		count=count+1;
	}
	printf("string length is %d\n",count);
	/*for(i=0;i<count;i++);
	for(j=0;j<count;j++)
	{
		str2[j]=str1[i-1];
		--i;
	}
	str2[count] = '\0';
	printf("reverse of string is %s\n",str2);
	for(i=0;i<count;i++)
	{
		str2[i]=str1[i];
	}
	str2[count]='\0';
	printf("original string is str1 ie %s ,copy of string is str2 and is %s\n",str1,str2);*/
	rev = reverse(str1);

	printf("the reversed string is %s \n",rev);
}