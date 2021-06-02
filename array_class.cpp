#include<iostream>

using namespace std;


class Matrix{
public:

	int in_row,in_col;
	int multiplier_row,multiplier_col;
	float in_data[50][50];
	float multiplier[50][50];
	float result[50][50];

	void matmul(int in_row,int in_col,int multiplier_row,int multiplier_col,float in_data[][50],float multiplier[][50],float result[][50]);
	void matdisplay(int in_row,int multiplier_col,float result[][50]);
	void insertmatrixdata(int row,int col,float data_mat[][50]);
};

void Matrix::matmul(int in_row,int in_col,int multiplier_row,int multiplier_col,float in_data[][50],float multiplier[][50],float result[][50])
{
	int row,col,k;
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
void Matrix::matdisplay(int in_row,int multiplier_col,float result[][50])
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
void Matrix::insertmatrixdata(int row,int col,float data_mat[][50])
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
	char ch;
	do{
		Matrix obj;
	
		cout<<"ENTER THE NO OF ROWS AND COLUMNS FOR in_data MATRIX"<<endl;
		cout<<"ENTER NO OF ROWS:";
		cin>>obj.in_row;
		cout<<"ENTER NO OF COLUMNS:";
		cin>>obj.in_col;
		cout<<"ENTER THE NO OF ROWS AND COLUMNS FOR multiplier MATRIX"<<endl;
		cout<<"ENTER NO OF ROWS:";
		cin>>obj.multiplier_row;
		cout<<"ENTER NO OF COLUMNS:";
		cin>>obj.multiplier_col;
		cout<<"ENTER THE INPUT DATA"<<endl;

		obj.insertmatrixdata(obj.in_row,obj.in_col,obj.in_data);

		obj.matdisplay(obj.in_row,obj.in_col,obj.in_data);

		cout<<"ENTER THE MULTIPLIER DATA"<<endl;

		obj.insertmatrixdata(obj.multiplier_row,obj.multiplier_col,obj.multiplier);

		obj.matdisplay(obj.multiplier_row,obj.multiplier_col,obj.multiplier);

		obj.matmul(obj.in_row,obj.in_col,obj.multiplier_row,obj.multiplier_col,obj.in_data,obj.multiplier,obj.result);
		
		obj.matdisplay(obj.in_row,obj.multiplier_col,obj.result);

		cout<<"Do you want to continue:(y/n)";

		cin>>ch;

	}while(ch=='y'||ch=='Y');
	
}