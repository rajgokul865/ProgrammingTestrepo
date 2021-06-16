#include <iostream>
#include <vector>
using namespace std;


void fun(int n,int m,vector<vector<int>> & matrix)
{
    int i,j;

 /*   for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            vec[i][j] = j + i + 1;
        }
    }*/
 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 4;
    int m = 5;
 
    /*
    Create a vector containing "n"
    vectors each of size "m".
    */
    vector<vector<int>> vec( n , vector<int> (m));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            vec[i][j] = j + i + 1;
        }
    }

    fun(n,m,vec); 

     
   return 0;
}