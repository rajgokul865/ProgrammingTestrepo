#include<iostream>
using namespace std;
int main()
{
	float data;
	int in_row,in_col,k,row,col;
	int multiplier_row,multiplier_col;
	cout<<"ENTER THE NO OF ROWS AND COLUMNS FOR in_data MATRIX"<<endl;
	cout<<"ENTER NO OF ROWS:";
	cin>>in_row;
	cout<<"ENTER NO OF COLUMNS:";
	cin>>in_col;
	cout<<"ENTER THE NO OF ROWS AND COLUMNS FOR multiplier MATRIX"<<endl;
	cout<<"ENTER NO OF ROWS:";
	cin>>multiplier_row;
	cout<<"ENTER NO OF COLUMNS:";
	cin>>multiplier_col;
	float in_data[in_row][in_col];
	float multiplier[multiplier_row][multiplier_col];
	float result[in_row][multiplier_col];
	/*float data;
	int in_row,in_col,k,row,col;
	int multiplier_row,multiplier_col;
	cout<<"ENTER THE NO OF ROWS AND COLUMNS FOR in_data MATRIX"<<endl;
	cout<<"ENTER NO OF ROWS:";
	cin>>in_row;
	cout<<"ENTER NO OF COLUMNS:";
	cin>>in_col;
	cout<<"ENTER THE NO OF ROWS AND COLUMNS FOR multiplier MATRIX"<<endl;
	cout<<"ENTER NO OF ROWS:";
	cin>>multiplier_row;
	cout<<"ENTER NO OF COLUMNS:";
	cin>>multiplier_col;*/
	cout<<"ENTER THE INPUT DATA"<<endl;
	for(row=0;row<in_row;row++)
	{
		for(col=0;col<in_col;col++)
		{
			cin>>data;
			in_data[row][col]=data;
		}
	}
	for(row=0;row<in_row;row++)
	{
		for(col=0;col<in_col;col++)
		{
			cout<<"in_data["<<row<<"]["<<col<<"]="<<in_data[row][col]<<"  ";
		}
		cout<<"\n";
	}
	cout<<"ENTER THE MULTIPLIER DATA"<<endl;
	for(row=0;row<multiplier_row;row++)
	{
		for(col=0;col<multiplier_col;col++)
		{
			cin>>data;
			multiplier[row][col]=data;
		}
	}
	for(row=0;row<multiplier_row;row++)
	{
		for(col=0;col<multiplier_col;col++)
		{
			cout<<"multiplier["<<row<<"]["<<col<<"]="<<multiplier[row][col]<<"  ";
		}
		cout<<"\n";
	}
	cout<<"PRODUCT OF TWO MATRICES."<<endl;	
	if(in_col!=multiplier_row)
	{
		cout<<"MULTIPLICATION OF MATRICES IS NOT POSSIBLE DUE TO SIZE MISMATCH."<<endl;
	}
	else
	{
		for(row=0;row<in_row;row++)
		{
			for(col=0;col<multiplier_col;col++)
			{
				result[row][col]=0;
				for(k=0;k<in_col;k++)
				{
					result[row][col] += in_data[row][k]*multiplier[k][col];
				}
			}
		}
	}
	for(row=0;row<in_row;row++)
	{
		for(col=0;col<multiplier_col;col++)
		{
			cout<<"res["<<row<<"]["<<col<<"]="<<result[row][col]<<"  ";
		}
		cout<<"\n";
	}
}