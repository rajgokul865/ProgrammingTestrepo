#include<iostream>
using namespace std;
/*class Matrix{
public:
	float in_data[50][50];
	float multiplier[50][50];
	float result[50][50];
	float data;
	int in_row,in_col,k,row,col;
	int multiplier_row,multiplier_col;
}; */
void matmul(int in_row,int in_col,int multiplier_row,int multiplier_col,float in_data[][50],float multiplier[][50],float result[][50])
{
	int row,col,k;
	//float result[50][50];
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
}
void matdisplay(int in_row,int multiplier_col,float result[][50])
{
	int row,col;
	for(row=0;row<in_row;row++)
	{
		for(col=0;col<multiplier_col;col++)
		{
			cout<<"res["<<row<<"]["<<col<<"]="<<result[row][col]<<"  ";
		}
		cout<<"\n";
	}	
}
void insertmatrixdata(int row,int col,float data_mat[][50])
{
	int data,drow,dcol;
	for(drow=0;drow<row;drow++)
	{
		for(dcol=0;dcol<col;dcol++)
		{
			cin>>data;
			data_mat[drow][dcol]=data;
		}
	}
}
int main()
{
	/*int m,n;
	cout<<"Enter size of array:";
	cout<<"m*n matrix with m =";
	cin>>m;
	cout<<" n =";
	cin>>n;*/
	float data;
	int in_row,in_col,k,row,col;
	int multiplier_row,multiplier_col;
	float in_data[50][50];
	float multiplier[50][50];
	float result[50][50];
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

	
	cout<<"ENTER THE INPUT DATA"<<endl;
	/*for(row=0;row<in_row;row++)
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
	}*/
	
	insertmatrixdata(in_row,in_col,in_data);

	matdisplay(in_row,in_col,in_data);

	cout<<"ENTER THE MULTIPLIER DATA"<<endl;

	insertmatrixdata(multiplier_row,multiplier_col,multiplier);

	matdisplay(multiplier_row,multiplier_col,multiplier);

	matmul(in_row,in_col,multiplier_row,multiplier_col,in_data,multiplier,result);
	
	matdisplay(in_row,multiplier_col,result);
	
}