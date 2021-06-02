#include<iostream>
using namespace std;
int main()
{
	int i,num,fact;
	char ch;
	do
	{
		cout<<"Enter any positive Integer:";
		cin>>num;

		if(num==0)
		{
			cout<<"0 factorial is 1"<<endl;
		}	
		else if(num>0)
		{
			fact=1;
			for(i=num;i>=1;i--)
			{
				fact=fact*i;
			}
			cout<<num<<" factorial is "<<fact<<endl;
		}
		else
		{
			cout<<"Invalid number"<<endl;
		}
		cout<<"Do you want to check another number:(y/n)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	//printf("%d factorial is %d\n",num,fact);
	return 0;
}
