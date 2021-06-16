// The following program works only if your compiler is C99 compatible.
#include <stdio.h>
  
// n must be passed before the 2D array
void print(int m, int n, int arr[][n])
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        printf("%d ", arr[i][j]);
}
  
int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arry[][2] = {{1,5},{3,4},{4,7}};
    int m = 3, n = 3;
    print(m, n, arr);
    printf("\n");
    print(3,2,arry);
    return 0;
}