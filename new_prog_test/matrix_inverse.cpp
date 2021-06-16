#include<iostream>
#include<math.h>
#include<vector>
#define ROW 50
#define COLUMN 50
using namespace std;

//float determinant(float,vector<vector<float>>);
//void cofactor(float,vector<vector<float>>);
//void transpose(float,vector<vector<float>>);
//void insertmatrixdata(int,int,vector<vector<float>>);
//void matdisplay(int,int,vector<vector<float>>);



float determinant(float k,vector<vector<float>> & mat)
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

void inverse(float r,vector<vector<float>> & num,vector<vector<float>> & fac,vector<vector<float>> & inverse)

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

   //printf("\n\n\nThe inverse of matrix is : \n");

 

   /*for (i = 0;i < r; i++)

    {

     for (j = 0;j < r; j++)

       {

         printf("\t%f", inverse[i][j]);

        }

    printf("\n");

     }*/

}

void cofactor(float f,vector<vector<float>> & num,vector<vector<float>> & fac)

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



void insertmatrixdata(int row,int col,vector<vector<float>> & data_mat)
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
void matdisplay(int in_row,int multiplier_col,vector<vector<float>> & result)
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
int main()
{
	int x_row = 3,x_col = 3;

	float d;

	vector < vector < float > > X_Matrix(ROW, vector<float>(COLUMN,0));
	vector < vector < float > > fac(ROW, vector<float>(COLUMN,0));
	vector < vector < float > > InverseMat(ROW, vector<float>(COLUMN,0));

	insertmatrixdata(x_row,x_col,X_Matrix);

	matdisplay(x_row,x_col,X_Matrix);

	d = determinant(x_row,X_Matrix);

	cout<<"determinant is "<<d<<endl;

	if (d == 0)
	{
		cout<<"\nInverse of Entered Matrix is not possible"<<endl;
	}
	else
	{
		cofactor(x_row,X_Matrix,fac);
		inverse(x_row,X_Matrix,fac,InverseMat);
		matdisplay(x_row,x_col,InverseMat);
	}
}