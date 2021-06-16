#include<iostream>

using namespace std;


class Matrix{
public:

	int in_row,in_col;
	int A_matrow,A_matcol;
	int B_matrow,B_matcol;
	int con_row,con_col;
	float in_data[50][50];
	float A_mat[50][50];
	float B_mat[50][50];
	float control_data[50][50];
	float resultA[50][50];
	float resultB[50][50];
	float resultTotal[50][50];
	float transposematrix[50][50];
	float IdentityMatrix[50][50];
	float SumMatrix[50][50];
	float ControlVar[50][50];

	void matmul(int in_row,int in_col,int multiplier_row,int multiplier_col,float in_data[][50],float multiplier[][50],float result[][50]);
	void matdisplay(int in_row,int multiplier_col,float result[][50]);
	void insertmatrixdata(int row,int col,float data_mat[][50]);
	void matTranspose(int row,int col,float mat[][50],float transres[][50]);
	void matIdentity(int row,int col,float IdentityMat[][50]);
	void matSum(int row,int col,float firstmat[][50],float secondmat[][50],float SumMat[0][50]);
};

void Matrix::matSum(int row,int col,float firstmat[][50],float secondmat[][50],float SumMat[0][50])
{
	int i,j;
	//int sumrow = row;
	//int sumcol = col;
	for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				SumMat[i][j]=firstmat[i][j]+secondmat[i][j];
			}
		}
		//matdisplay(row,col,sumMat);
}
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
	int drow,dcol;
	float data;
	for(drow=0;drow<row;drow++)
	{
		for(dcol=0;dcol<col;dcol++)
		{
			cin>>data;
			data_mat[drow][dcol]=data;
		}
	}
}
void Matrix::matTranspose(int row,int col,float mat[][50],float transres[][50])
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			transres[j][i]=mat[i][j];
		}
	}
}
void Matrix::matIdentity(int row,int col,float IdentityMat[][50])
{
	int i,j;

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			IdentityMat[i][j]=1;
		}
	}
	cout<<"IDENTITY MATRIX"<<endl;
	matdisplay(row,col,IdentityMat);
}

int main()
{
	char ch;
	do{
		Matrix obj;
		
		cout<<"KALMAN FILTER 1-D WITH TWO VARIABLE EXAMPLE."<<endl;
		//cout<<"ENTER THE NO OF ROWS AND COLUMNS FOR in_data MATRIX"<<endl;
		//cout<<"ENTER NO OF ROWS:";
		//cin>>obj.in_row;
		obj.in_row = 2;
		//cout<<"ENTER NO OF COLUMNS:";
		//cin>>obj.in_col;
		obj.in_col = 1;
		//cout<<"ENTER THE NO OF ROWS AND COLUMNS FOR multiplier MATRIX"<<endl;
		//cout<<"ENTER NO OF ROWS:";
		//cin>>obj.multiplier_row;
		//cout<<"ENTER NO OF COLUMNS:";
		//cin>>obj.multiplier_col;
		//cout<<"ENTER THE INPUT DATA"<<endl;
		obj.A_matrow = 2;
		obj.A_matcol = 2;

		obj.B_matrow = 2;
		obj.B_matcol = 1;


		obj.con_row = 1;
		obj.con_col = 1;

		cout<<"ENTER INITIAL INPUT CONDITION ie POSITION AND VELOCITY STATE MATRIX"<<endl;

		obj.insertmatrixdata(obj.in_row,obj.in_col,obj.in_data);

		obj.matdisplay(obj.in_row,obj.in_col,obj.in_data);

		cout<<"ENTER THE MATRIX 'A' DATA"<<endl;

		obj.insertmatrixdata(obj.A_matrow,obj.A_matcol,obj.A_mat);
		//obj.A_mat[A_matrow][A_matcol] = {{1,1},{0,1}};

		obj.matdisplay(obj.A_matrow,obj.A_matcol,obj.A_mat);

		obj.matmul(obj.A_matrow,obj.A_matcol,obj.in_row,obj.in_col,obj.A_mat,obj.in_data,obj.resultA);
		
		obj.matdisplay(obj.A_matrow,obj.in_col,obj.resultA);

		cout<<"ENTER INITIAL CONTROL VARIABLE MATRIX"<<endl;
		
		obj.insertmatrixdata(obj.con_row,obj.con_col,obj.control_data);

		obj.matdisplay(obj.con_row,obj.con_col,obj.control_data);

		cout<<"ENTER THE MATRIX 'B' DATA"<<endl;

		obj.insertmatrixdata(obj.B_matrow,obj.B_matcol,obj.B_mat);

		obj.matdisplay(obj.B_matrow,obj.B_matcol,obj.B_mat);

		obj.matmul(obj.B_matrow,obj.B_matcol,obj.con_row,obj.con_col,obj.B_mat,obj.control_data,obj.resultB);
		
		obj.matdisplay(obj.B_matrow,obj.con_col,obj.resultB);

		cout<<"TOTAL RESULT ie NEW PREDICTED STATE MATRIX WITH POSTION AND VELOCITY"<<endl;

		obj.matSum(obj.in_row,obj.in_col,obj.resultA,obj.resultB,obj.SumMatrix);

		obj.matdisplay(obj.in_row,obj.in_col,obj.SumMatrix);		

		cout<<"TRANSPOSE OF THE MATRIX IN_DATA"<<endl;

		obj.matTranspose(obj.in_row,obj.in_col,obj.in_data,obj.transposematrix);

		obj.matdisplay(obj.in_col,obj.in_row,obj.transposematrix);

		obj.matIdentity(obj.in_row,obj.in_col,obj.IdentityMatrix);

		cout<<"Do you want to continue:(y/n)";

		cin>>ch;

	}while(ch=='y'||ch=='Y');
	
}