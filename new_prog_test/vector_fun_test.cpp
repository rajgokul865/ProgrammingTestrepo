#include <iostream>
#include <vector>
using namespace std;


void fun(int n,int m,vector<vector<float>> & matrix)
{
    int i,j;
    float data;

/*    vector<int> myRow(0,n);
    matrix.push_back(myRow);
    for(i=0;i<m;i++)
        matrix[i].push_back(3);*/
 /*   for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            matrix[i][j] = j + i + 1;
        }
    }*/
    //matrix = {{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            cin>>data;
            matrix[i][j] = data;
        }
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows = 2;
    int columns = 2;
 
    /*
    Create a vector containing "n"
    vectors each of size "m".
    */
    vector < vector < float > > vec(rows, vector< float >(columns,0));
    //vector < vector < int > > vec;

    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            vec[i][j] = j + i + 1;
        }
    }*/

    fun(rows,columns,vec); 

     
   return 0;
}