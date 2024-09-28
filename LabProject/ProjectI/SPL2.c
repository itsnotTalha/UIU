#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int Arr[m][n];

    for (int i = 0; i < m; i++)
    {
        for(int j=0;j<n;j++)
        scanf("%d", &Arr[i][j]);
    }
//1st row
for (int j = 0; j < n; j++) {
        printf("%d", Arr[0][j]);
        if (j < n - 1) {
            printf(", ");
        }
    }
 //middle row   
    printf(", %d", Arr[1][n - 1]);
    //last row
    for (int j = n - 1; j >= 0; j--) {
        printf(", %d", Arr[2][j]);
    }
//mid again
    for (int j = 0; j < n - 1; j++) {
        printf(", %d", Arr[1][j]);
    }
    return 0;
}
