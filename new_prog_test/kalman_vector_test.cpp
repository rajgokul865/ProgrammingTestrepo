#include<iostream>
#include<vector>

using namespace std;


class Matrix{
public:

	int x_row = 2,x_col = 1;
	int A_matrow = 2,A_matcol = 2;
	int B_matrow = 2,B_matcol = 1;
	int con_row = 1,con_col = 1;
	int cov_row = 2,cov_col = 2;


	void matmul(int in_row,int in_col,int multiplier_row,int multiplier_col,vector<vector<float>> & in_data,vector<vector<float>> & multiplier,vector<vector<float>> & result);
	void matdisplay(int in_row,int multiplier_col,vector<vector<float>> & result);
	void insertmatrixdata(int row,int col,vector<vector<float>> & data_mat);
	void matSum(int row,int col,vector<vector<float>> & firstmat,vector<vector<float>> & secondmat,vector<vector<float>> & SumMat);
	void matTranspose(int row,int col,vector<vector<float>> & mat,vector<vector<float>> & transres);
	void matIdentity(int row,int col,vector<vector<float>> & IdentityMat);
};


void Matrix::matSum(int row,int col,vector<vector<float>> & firstmat,vector<vector<float>> & secondmat,vector<vector<float>> & SumMat)
{
	int i,j;
	for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				SumMat[i][j]=firstmat[i][j]+secondmat[i][j];
			}
		}
}
void Matrix::matmul(int in_row,int in_col,int multiplier_row,int multiplier_col,vector<vector<float>> & in_data,vector<vector<float>> & multiplier,vector<vector<float>> & result)
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
void Matrix::matdisplay(int in_row,int multiplier_col,vector<vector<float>> & result)
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
void Matrix::insertmatrixdata(int row,int col,vector<vector<float>> & data_mat)
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
void Matrix::matTranspose(int row,int col,vector<vector<float>> & mat,vector<vector<float>> & transres)
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
void Matrix::matIdentity(int row,int col,vector<vector<float>> & IdentityMat)
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
}

int main()
{
	char ch;

	do{
		Matrix obj;
		
		cout<<"KALMAN FILTER 1-D WITH TWO VARIABLE EXAMPLE."<<endl;

			
		vector<vector<float > > X_Matrix(50/*obj.x_row*/, vector<float>(50/*obj.x_col*/,0));
		vector < vector < float > > u_ControlMatrix(50/*obj.con_row*/, vector< float >(50/*obj.con_col*/,0));
		vector < vector < float > > A_Matrix(50/*obj.A_matrow*/, vector< float >(50/*obj.A_matcol*/,0));
		vector < vector < float > > B_Matrix(50/*obj.B_matrow*/, vector< float >(50/*obj.B_matcol*/,0));
		vector < vector < float > > resultA(50/*obj.A_matrow*/, vector< float >(50/*obj.x_col*/,0));
		vector < vector < float > > resultB(50/*obj.B_matrow*/, vector< float >(50/*obj.con_col*/,0));
		vector < vector < float > > resultTotal(50/*obj.x_row*/, vector< float >(50/*obj.x_col*/,0));
		vector<vector<float > > SumMatrix(50/*obj.x_row*/, vector<float>(50/*obj.x_col*/,0));
		vector<vector<float > > transposematrix(50/*obj.A_matcol*/, vector<float>(50/*obj.A_matrow*/,0));
		vector<vector<float > > IdentityMatrix(50/*obj.x_row*/, vector<float>(50/*obj.x_col*/,0));


		vector<vector<float > > ProcessCovMatrix(obj.cov_row, vector<float>(obj.cov_col,0));

		cout<<"ENTER THE MATRIX 'A' DATA"<<endl;

		//obj.insertmatrixdata(obj.A_matrow,obj.A_matcol,A_Matrix);
		A_Matrix = {{1,1},{0,1}};

		obj.matdisplay(obj.A_matrow,obj.A_matcol,A_Matrix);

		cout<<"ENTER INITIAL INPUT CONDITION ie POSITION AND VELOCITY STATE MATRIX"<<endl;

		obj.insertmatrixdata(obj.x_row,obj.x_col,X_Matrix);

		obj.matdisplay(obj.x_row,obj.x_col,X_Matrix);

		cout<<"A*X_Matrix"<<endl;

		obj.matmul(obj.A_matrow,obj.A_matcol,obj.x_row,obj.x_col,A_Matrix,X_Matrix,resultA);
		
		obj.matdisplay(obj.A_matrow,obj.x_col,resultA);

		cout<<"ENTER THE MATRIX 'B' DATA"<<endl;

		//obj.insertmatrixdata(obj.B_matrow,obj.B_matcol,B_Matrix);

		B_Matrix = {{0.5},{1}};

		obj.matdisplay(obj.B_matrow,obj.B_matcol,B_Matrix);

		cout<<"ENTER INITIAL CONTROL VARIABLE MATRIX"<<endl;
		
		obj.insertmatrixdata(obj.con_row,obj.con_col,u_ControlMatrix);

		obj.matdisplay(obj.con_row,obj.con_col,u_ControlMatrix);

		cout<<"B*u_ControlMatrix"<<endl;

		obj.matmul(obj.B_matrow,obj.B_matcol,obj.con_row,obj.con_col,B_Matrix,u_ControlMatrix,resultB);
		
		obj.matdisplay(obj.B_matrow,obj.con_col,resultB);				

		cout<<"TOTAL RESULT ie NEW PREDICTED STATE MATRIX WITH POSTION AND VELOCITY"<<endl;

		obj.matSum(obj.x_row,obj.x_col,resultA,resultB,SumMatrix);

		obj.matdisplay(obj.x_row,obj.x_col,SumMatrix);

		cout<<"ENTER PROCESS COVARIANCE MATRIX"<<endl;

		obj.insertmatrixdata(obj.cov_row,obj.cov_col,ProcessCovMatrix);

		cout<<"A*ProcessCovMatrix"<<endl;

		obj.matmul(obj.A_matrow,obj.A_matcol,obj.cov_row,obj.cov_col,A_Matrix,ProcessCovMatrix,resultA);

		obj.matdisplay(obj.A_matrow,obj.cov_col,resultA);

		cout<<"TRANSPOSE OF THE A_Matrix"<<endl;

		obj.matTranspose(obj.A_matrow,obj.A_matcol,A_Matrix,transposematrix);

		obj.matdisplay(obj.A_matcol,obj.A_matrow,transposematrix);		

		cout<<"A*ProcessCovMatrix*A_transpose"<<endl;

		obj.matmul(obj.A_matrow,obj.cov_col,obj.A_matcol,obj.A_matrow,resultA,transposematrix,resultB);

		obj.matdisplay(obj.A_matrow,obj.cov_col,resultB);		

		/*cout<<"TRANSPOSE OF THE MATRIX IN_DATA"<<endl;

		obj.matTranspose(obj.x_row,obj.x_col,X_Matrix,transposematrix);

		obj.matdisplay(obj.x_col,obj.x_row,transposematrix);

		obj.matIdentity(obj.x_row,obj.x_col,IdentityMatrix);

		obj.matdisplay(obj.x_row,obj.x_col,IdentityMatrix);*/

		cout<<"Do you want to continue:(y/n)";

		cin>>ch;

	}while(ch=='y'||ch=='Y');
	
}