#include<iostream>
#include<vector>
#include<math.h>
#define ROW 50
#define COLUMN 50
#define DEBUGPRINT 0
using namespace std;



class Matrix{
public:

	int x_row = 2,x_col = 1;
	int A_matrow = 2,A_matcol = 2;
	int B_matrow = 2,B_matcol = 1;
	int C_matrow = 2,C_matcol = 2;
	int H_matrow = 2,H_matcol = 2;
	int R_matrow = 2,R_matcol = 2;
	int Meas_matrow = 2,Meas_matcol = 1;
	int Obs_matrow = 2,Obs_matcol = 1;
	int con_row = 1,con_col = 1;
	int cov_row = 2,cov_col = 2;
	int MeasNoise_matrow,MeasNoise_matcol;


	void matmul(int in_row,int in_col,int multiplier_row,int multiplier_col,vector<vector<float>> & in_data,vector<vector<float>> & multiplier,vector<vector<float>> & result);
	void matdisplay(int in_row,int multiplier_col,vector<vector<float>> & result);
	void insertmatrixdata(int row,int col,vector<vector<float>> & data_mat);
	void matSum(int row,int col,vector<vector<float>> & firstmat,vector<vector<float>> & secondmat,vector<vector<float>> & SumMat);
	void matSub(int row,int col,vector<vector<float>> & firstmat,vector<vector<float>> & secondmat,vector<vector<float>> & SubMat);
	void matTranspose(int row,int col,vector<vector<float>> & mat,vector<vector<float>> & transres);
	void matIdentity(int row,int col,vector<vector<float>> & IdentityMat);
	float determinant(float k,vector<vector<float>> & mat);
	void inverse(float r,vector<vector<float>> & num,vector<vector<float>> & fac,vector<vector<float>> & inverse);
	void cofactor(float f,vector<vector<float>> & num,vector<vector<float>> & fac);
};

float Matrix::determinant(float k,vector<vector<float>> & mat)
{
	float s = 1,det = 0;
	vector < vector < float > > b_mat(ROW, vector<float>(COLUMN,0));
	int i,j,m,n,c;
	if(k==1)
	{
		return (mat[0][0]);
	}
	else
	{
		det = 0;
		for(c=0;c<k;c++)
		{
			m=0;
			n=0;
			for(i=0;i<k;i++)
			{
				for(j=0;j<k;j++)
				{
					b_mat[i][j] = 0;
					if(i!=0 && j!=c)
					{
						b_mat[m][n] = mat[i][j];
						if (n < (k - 2))
						{
							n++;
						}
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			det = det + s*(mat[0][c]*determinant(k-1,b_mat));

			s = -1 * s;
		}
	}
	return (det);
}

void Matrix::inverse(float r,vector<vector<float>> & num,vector<vector<float>> & fac,vector<vector<float>> & inverse)
{

  int i, j;

  //float b[25][25], inverse[25][25], d;
  float d;

  vector < vector < float > > b_mat(ROW, vector<float>(COLUMN,0));
 

  for (i = 0;i < r; i++)

    {

     for (j = 0;j < r; j++)

       {

         b_mat[i][j] = fac[j][i];

        }

    }

  d = determinant(r,num);

  for (i = 0;i < r; i++)

    {

     for (j = 0;j < r; j++)

       {

        inverse[i][j] = b_mat[i][j] / d;

        }

    }
}

void Matrix::cofactor(float f,vector<vector<float>> & num,vector<vector<float>> & fac)
{

 //float b[25][25], fac[25][25];

 vector < vector < float > > b_mat(ROW, vector<float>(COLUMN,0));
 //vector < vector < float > > fac(ROW, vector<float>(COLUMN,0));

 int p, q, m, n, i, j;

 for (q = 0;q < f; q++)

 {

   for (p = 0;p < f; p++)

    {

     m = 0;

     n = 0;

     for (i = 0;i < f; i++)

     {

       for (j = 0;j < f; j++)

        {

          if (i != q && j != p)

          {

            b_mat[m][n] = num[i][j];

            if (n < (f - 2))

             n++;

            else

             {

               n = 0;

               m++;

               }

            }

        }

      }

      fac[q][p] = pow(-1, q + p) * determinant(f - 1,b_mat);

    }

  }

  //inverse(f,num, fac);

}

void Matrix::matSub(int row,int col,vector<vector<float>> & firstmat,vector<vector<float>> & secondmat,vector<vector<float>> & SubMat)
{
	int i,j;
	for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				SubMat[i][j]=firstmat[i][j] - secondmat[i][j];
			}
		}
}

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
	//cout<<"PRODUCT OF TWO MATRICES."<<endl;	
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
			if(i==j)
			{
				IdentityMat[i][j]=1;
			}
			else
			{
				IdentityMat[i][j]=0;
			}
			
		}
	}
	//cout<<"IDENTITY MATRIX"<<endl;
}

int main()
{
	char ch;
	float d;
	//int input_row,input_col;
	int i = 0;


	vector<float>TestDataPosition;
	vector<float>TestDataVelocity;


	vector < vector < float > > X_Matrix(ROW, vector<float>(COLUMN,0));
	vector < vector < float > > u_ControlMatrix(ROW, vector< float >(COLUMN,0));
	vector < vector < float > > Mea_Matrix(ROW, vector<float>(COLUMN,0));
	vector < vector < float > > R_Matrix(ROW, vector<float>(COLUMN,0));
	vector < vector < float > > A_Matrix(ROW, vector< float >(COLUMN,0));
	vector < vector < float > > B_Matrix(ROW, vector< float >(COLUMN,0));
	vector < vector < float > > C_Matrix(ROW, vector< float >(COLUMN,0));
	vector < vector < float > > H_Matrix(ROW, vector< float >(COLUMN,0));
	vector < vector < float > > resultA(ROW, vector< float >(COLUMN,0));
	vector < vector < float > > resultB(ROW, vector< float >(COLUMN,0));
	vector < vector < float > > resultTotal(ROW, vector< float >(COLUMN,0));
	vector < vector < float > > KalmanGain(ROW, vector< float >(COLUMN,0));		
	vector < vector < float > > StatePredMatrix(ROW, vector<float>(COLUMN,0));
	vector < vector < float > > CovPredMatrix(ROW, vector<float>(COLUMN,0));
	vector < vector < float > > transposematrix(ROW, vector<float>(COLUMN,0));
	vector < vector < float > > IdentityMatrix(ROW, vector<float>(COLUMN,0));
	vector < vector < float > > EstimCov(ROW, vector<float>(COLUMN,0));
	vector < vector < float > > EstimState(ROW, vector<float>(COLUMN,0));
	vector < vector < float > > ObsMea(ROW, vector<float>(COLUMN,0));
	vector < vector < float > > MeasMatrix(ROW,vector<float>(COLUMN,0));
	vector < vector < float > > MeasNoise(ROW,vector<float>(COLUMN,0));
	vector < vector < float > > fac(ROW, vector<float>(COLUMN,0));
	vector < vector < float > > InverseMat(ROW, vector<float>(COLUMN,0));

	vector<vector<float > > ProcessCovMatrix(ROW, vector<float>(COLUMN,0));

	Matrix obj;

	TestDataPosition = {4000,4260,4550,4860,5110,4578};
	TestDataVelocity = {280,282,285,286,290,287};



	#if DEBUGPRINT

	cout<<"TestDataPosition no of elements = "<<TestDataPosition.size()<<endl;

	//cout<<"MEASUREMENT INPUT"<<endl;

	/*Yk = C * Ykm + Zk*/

	//cout<<"ENTER THE MATRIX 'MeasMatrix' DATA"<<endl;

	//obj.insertmatrixdata(obj.A_matrow,obj.A_matcol,A_Matrix);

	#endif
	
	//MeasMatrix = {{4260},{282}};

	#if DEBUGPRINT

	obj.matdisplay(obj.Meas_matrow,obj.Meas_matcol,MeasMatrix);

	cout<<"ENTER THE MATRIX 'H' DATA"<<endl;

	//obj.insertmatrixdata(obj.A_matrow,obj.A_matcol,A_Matrix);
	#endif
	
	H_Matrix = {{1,0},{0,1}};

	#if DEBUGPRINT

	obj.matdisplay(obj.H_matrow,obj.H_matcol,H_Matrix);

	cout<<"ENTER THE MATRIX 'R' DATA"<<endl;

	//obj.insertmatrixdata(obj.A_matrow,obj.A_matcol,A_Matrix);
	#endif
	
	R_Matrix = {{625,0},{0,36}};

	#if DEBUGPRINT
	obj.matdisplay(obj.R_matrow,obj.R_matcol,R_Matrix);

	cout<<"ENTER THE MATRIX 'A' DATA"<<endl;

	#endif

	//obj.insertmatrixdata(obj.A_matrow,obj.A_matcol,A_Matrix);
	
	A_Matrix = {{1,1},{0,1}};

	#if DEBUGPRINT

	obj.matdisplay(obj.A_matrow,obj.A_matcol,A_Matrix);

	cout<<"ENTER THE MATRIX 'B' DATA"<<endl;

	//obj.insertmatrixdata(obj.B_matrow,obj.B_matcol,B_Matrix);
	#endif

	B_Matrix = {{0.5},{1}};

	#if DEBUGPRINT

	obj.matdisplay(obj.B_matrow,obj.B_matcol,B_Matrix);

	cout<<"ENTER THE MATRIX 'C' DATA"<<endl;

	//obj.insertmatrixdata(obj.A_matrow,obj.A_matcol,A_Matrix);

	#endif
	
	C_Matrix = {{1,0},{0,1}};

	#if DEBUGPRINT

	obj.matdisplay(obj.C_matrow,obj.C_matcol,C_Matrix);

	cout<<"ENTER INITIAL INPUT CONDITION ie POSITION AND VELOCITY STATE MATRIX"<<endl;

	//obj.insertmatrixdata(obj.x_row,obj.x_col,X_Matrix);
	#endif

	X_Matrix = {{4000},{280}};

	#if DEBUGPRINT

	obj.matdisplay(obj.x_row,obj.x_col,X_Matrix);

	cout<<"ENTER INITIAL CONTROL VARIABLE MATRIX"<<endl;
	
	//obj.insertmatrixdata(obj.con_row,obj.con_col,u_ControlMatrix);
	#endif

	u_ControlMatrix = {{2}};

	#if DEBUGPRINT

	obj.matdisplay(obj.con_row,obj.con_col,u_ControlMatrix);

	cout<<"ENTER PROCESS COVARIANCE MATRIX"<<endl;

	//obj.insertmatrixdata(obj.cov_row,obj.cov_col,ProcessCovMatrix);
	#endif
	
	ProcessCovMatrix = {{400,0},{0,25}};

	#if DEBUGPRINT

	obj.matdisplay(obj.cov_row,obj.cov_col,ProcessCovMatrix);

	#endif
	
	do{
		//Matrix obj;
		cout<<"LOOP NEW 'MeasMatrix' DATA"<<endl;

		MeasMatrix = {{TestDataPosition[i + 1]},{TestDataVelocity[i + 1]}};

		cout<<endl;

		if((i+1) >= TestDataPosition.size())
		{
			break;
		}

		obj.matdisplay(obj.Meas_matrow,obj.Meas_matcol,MeasMatrix);
		#if DEBUGPRINT
		cout<<"KALMAN FILTER 1-D WITH TWO VARIABLE EXAMPLE."<<endl;

		/*vector < vector < float > > input_Matrix(ROW, vector<float>(COLUMN,0));

		cout<<"ENTER INPUT ROW:";
		cin>>input_row;
		cout<<"ENTER INPUT COL:";
		cin>>input_col;

		cout<<"ENTER INPUT_MATRIX ELEMENTS"<<endl;
		obj.insertmatrixdata(input_row,input_col,input_Matrix);
		obj.matdisplay(input_row,input_col,input_Matrix);*/
			

		/************************************PREDICTION**********************************************/

		/*===============================STATE MATRIX PREDICTION=====================================*/

		cout<<"A*X_Matrix"<<endl;
		#endif
		obj.matmul(obj.A_matrow,obj.A_matcol,obj.x_row,obj.x_col,A_Matrix,X_Matrix,resultA);
		#if DEBUGPRINT
		obj.matdisplay(obj.A_matrow,obj.x_col,resultA);

		cout<<"B*u_ControlMatrix"<<endl;
		#endif
		obj.matmul(obj.B_matrow,obj.B_matcol,obj.con_row,obj.con_col,B_Matrix,u_ControlMatrix,resultB);
		#if DEBUGPRINT
		obj.matdisplay(obj.B_matrow,obj.con_col,resultB);				

		cout<<"TOTAL RESULT ie NEW PREDICTED STATE MATRIX WITH POSTION AND VELOCITY"<<endl;
		#endif
		obj.matSum(obj.x_row,obj.x_col,resultA,resultB,StatePredMatrix);
		#if DEBUGPRINT
		obj.matdisplay(obj.x_row,obj.x_col,StatePredMatrix);

		/*===============================COVARIANCE MATRIX PREDICTION=====================================*/

		cout<<"A*ProcessCovMatrix"<<endl;
		#endif
		obj.matmul(obj.A_matrow,obj.A_matcol,obj.cov_row,obj.cov_col,A_Matrix,ProcessCovMatrix,resultA);
		#if DEBUGPRINT
		obj.matdisplay(obj.A_matrow,obj.cov_col,resultA);

		cout<<"TRANSPOSE OF THE A_Matrix"<<endl;
		#endif
		obj.matTranspose(obj.A_matrow,obj.A_matcol,A_Matrix,transposematrix);
		#if DEBUGPRINT
		obj.matdisplay(obj.A_matcol,obj.A_matrow,transposematrix);		

		cout<<"A*ProcessCovMatrix*A_transpose"<<endl;
		#endif
		obj.matmul(obj.A_matrow,obj.cov_col,obj.A_matcol,obj.A_matrow,resultA,transposematrix,CovPredMatrix);

		CovPredMatrix[0][1] = 0;
		CovPredMatrix[1][0] = 0;
		#if DEBUGPRINT
		obj.matdisplay(obj.A_matrow,obj.A_matrow,CovPredMatrix);

		/*===============================KALMAN GAIN CALCULATION=====================================*/		

		cout<<"KALMAN GAIN CALCULATION"<<endl;

		cout<<"TRANSPOSE OF THE H_Matrix"<<endl;
		#endif
		obj.matTranspose(obj.H_matrow,obj.H_matcol,H_Matrix,transposematrix);
		#if DEBUGPRINT
		obj.matdisplay(obj.H_matcol,obj.H_matrow,transposematrix);

		cout<<"H * predicted ProcessCovMatrix"<<endl;	
		#endif
		obj.matmul(obj.H_matrow,obj.H_matcol,obj.A_matrow,obj.cov_col,H_Matrix,CovPredMatrix,resultA);
		#if DEBUGPRINT
		obj.matdisplay(obj.H_matrow,obj.cov_col,resultA);

		cout<<"H * predicted ProcessCovMatrix * H_transpose"<<endl;
		#endif
		obj.matmul(obj.H_matrow,obj.cov_col,obj.H_matcol,obj.H_matrow,resultA,H_Matrix,resultB);
		#if DEBUGPRINT
		obj.matdisplay(obj.H_matrow,obj.H_matrow,resultB);

		cout<<"resultB = H * predicted ProcessCovMatrix * H_transpose + R_Matrix"<<endl;
		#endif
		obj.matSum(obj.H_matrow,obj.H_matrow,resultB,R_Matrix,resultB);
		#if DEBUGPRINT
		obj.matdisplay(obj.H_matrow,obj.H_matrow,resultB);

		cout<<"resultB Inverse"<<endl;
		#endif
		d = obj.determinant(obj.H_matrow,resultB);
		if (d == 0)
		{
			cout<<"\nInverse of Entered Matrix is not possible"<<endl;
		}
		else
		{
			obj.cofactor(obj.H_matrow,resultB,fac);
			obj.inverse(obj.H_matrow,resultB,fac,InverseMat);
			#if DEBUGPRINT
			obj.matdisplay(obj.H_matrow,obj.H_matrow,InverseMat);
			#endif
		}
		#if DEBUGPRINT
		cout<<"predicted ProcessCovMatrix*H"<<endl;
		#endif
		obj.matmul(obj.A_matrow,obj.cov_col,obj.H_matrow,obj.H_matcol,CovPredMatrix,H_Matrix,resultA);
		#if DEBUGPRINT
		obj.matdisplay(obj.A_matrow,obj.H_matcol,resultA);

		cout<<"Kalman gain = predicted ProcessCovMatrix * H * InverseMat"<<endl;
		#endif

		cout<<endl;

		cout<<"KALMAN GAIN MATRIX"<<endl;

		cout<<endl;
		
		obj.matmul(obj.A_matrow,obj.H_matcol,obj.H_matrow,obj.H_matrow,resultA,InverseMat,KalmanGain);

		obj.matdisplay(obj.A_matrow,obj.H_matrow,KalmanGain);


		/************************************UPDATION**********************************************/

		/*===============================COVARIANCE MATRIX UPDATION=====================================*/


		/*Xk = Xkp + K * (Yk - HXkp).

		  Pk = (I - KH) * Pkp.

		  Yk = C * Ykm + Zk

		  Xk = EstimState (x_row,x_col) , Xkp = StatePredMatrix (x_row,x_col) , K = KalmanGain (A_matrow,H_matrow) , Yk = ObsMea (C_matrow,Meas_matcol) , H = H_matrix (H_matrow,H_matcol).

		  Pk = EstimCov (A_matrow,A_matrow) , I = IdentityMatrix (A_matrow,H_matcol) , Pkp = CovPredMatrix (A_matrow,A_matrow).

		  C = C_Matrix (C_matrow,C_matcol) , Ykm = MeasMatrix (Meas_matrow,Meas_matcol) , Zk = MeasNoise. */

		#if DEBUGPRINT
		cout<<"FINDING ObsMea MATRIX"<<endl;
		#endif
		obj.matmul(obj.C_matrow,obj.C_matcol,obj.Meas_matrow,obj.Meas_matcol,C_Matrix,MeasMatrix,ObsMea);
		#if DEBUGPRINT
		obj.matdisplay(obj.C_matrow,obj.Meas_matcol,ObsMea);

		/*Pk = (I - KH) * Pkp.*/

		cout<<"CREATE IdentityMatrix"<<endl;
		#endif
		obj.matIdentity(obj.A_matrow,obj.H_matcol,IdentityMatrix);
		#if DEBUGPRINT
		obj.matdisplay(obj.A_matrow,obj.H_matcol,IdentityMatrix);

		cout<<"FINDING K * H"<<endl;
		#endif
		obj.matmul(obj.A_matrow,obj.H_matrow,obj.H_matrow,obj.H_matcol,KalmanGain,H_Matrix,resultA);
		#if DEBUGPRINT
		obj.matdisplay(obj.A_matrow,obj.H_matcol,resultA);

		cout<<"FINDING (I - K*H)"<<endl;
		#endif
		obj.matSub(obj.A_matrow,obj.H_matcol,IdentityMatrix,resultA,resultB);
		#if DEBUGPRINT
		obj.matdisplay(obj.A_matrow,obj.H_matcol,resultB);

		cout<<"FINDING EstimCov MATRIX ie Pk"<<endl;
		#endif
		obj.matmul(obj.A_matrow,obj.H_matcol,obj.A_matrow,obj.A_matrow,resultB,CovPredMatrix,EstimCov);
		#if DEBUGPRINT
		obj.matdisplay(obj.A_matrow,obj.A_matrow,EstimCov);
		#endif
		EstimCov[0][1] = 0;
		EstimCov[1][0] = 0;

		
		/*===============================STATE MATRIX UPDATION=====================================*/


		/*Xk = Xkp + K * (Yk - HXkp).

		  Xk = EstimState (x_row,x_col) , Xkp = StatePredMatrix (x_row,x_col) , K = KalmanGain (A_matrow,H_matrow) , Yk = ObsMea (C_matrow,Meas_matcol) , H = H_matrix (H_matrow,H_matcol).*/
		#if DEBUGPRINT
		cout<<"H_matrix * StatePredMatrix"<<endl;
		#endif
		obj.matmul(obj.H_matrow,obj.H_matcol,obj.x_row,obj.x_col,H_Matrix,StatePredMatrix,resultA);
		#if DEBUGPRINT
		obj.matdisplay(obj.H_matrow,obj.x_col,resultA);

		cout<<"ObsMea - H*Xkp"<<endl;
		#endif
		obj.matSub(obj.C_matrow,obj.Meas_matcol,ObsMea,resultA,resultB);
		#if DEBUGPRINT
		obj.matdisplay(obj.C_matrow,obj.Meas_matcol,resultB);

		cout<<"K * (ObsMea - H*Xkp)"<<endl;
		#endif
		obj.matmul(obj.A_matrow,obj.H_matrow,obj.C_matrow,obj.Meas_matcol,KalmanGain,resultB,resultA);
		#if DEBUGPRINT
		obj.matdisplay(obj.A_matrow,obj.Meas_matcol,resultA);

		cout<<" FINDING EstimState MATRIX ie Xk"<<endl;
		#endif
		obj.matSum(obj.x_row,obj.x_col,StatePredMatrix,resultA,EstimState);
		#if DEBUGPRINT
		obj.matdisplay(obj.x_row,obj.x_col,EstimState);
		#endif
		cout<<endl;

		//cout<<"/*=========================================================================================================================================================================================*/"<<endl;
		
		cout<<endl;

		/************************************PREDICTION AND UPDATION RESULTS**********************************************/

		cout<<"*************Xkp PREDICTED STATE MATRIX*************"<<endl;

		cout<<endl;

		obj.matdisplay(obj.x_row,obj.x_col,StatePredMatrix);

		cout<<endl;		

		cout<<"*************Pkp PREDICTED COVARIANCE MATRIX*************"<<endl;

		cout<<endl;

		obj.matdisplay(obj.A_matrow,obj.A_matrow,CovPredMatrix);

		cout<<endl;

		cout<<"*************Xk ESTIMATED/UPDATED STATE MATRIX*************"<<endl;

		cout<<endl;

		obj.matdisplay(obj.x_row,obj.x_col,EstimState);

		cout<<"*************Pk ESTIMATED/UPDATED COVARIANCE MATRIX*************"<<endl;

		cout<<endl;

		obj.matdisplay(obj.A_matrow,obj.A_matrow,EstimCov);

		cout<<endl;	

		X_Matrix = EstimState;

		ProcessCovMatrix = EstimCov;

		cout<<"/*******************************************************************END************************************************************************************/"<<endl;

		cout<<endl;
		//cout<<"Do you want to continue:(y/n)";

		//cin>>ch;
		i++;

	}while(i<TestDataPosition.size());
	
}