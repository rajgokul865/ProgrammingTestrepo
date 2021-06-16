#include <iostream>
using namespace std;  
// n must be passed before the 2D array
void fun(int m, int n, int arr[][n])
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        cout<<arr[i][j]<<endl;
}
  
int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arry[][2] = {{1,5},{3,4},{4,7}};
    int m = 3, n = 3;
    fun(m, n, arr);
    cout<<endl;
    fun(3,2,arry);
    return 0;
}