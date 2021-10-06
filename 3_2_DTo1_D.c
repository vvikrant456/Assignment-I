#include <stdio.h>
#define ll long long

int main()
{

    int n, m;
    printf("Enter no. of rows and no. of columns\n");
    scanf("%d %d", &n, &m);
    int arr[m][n];
    printf("Taking input of elements for the 2D array\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n \n");
    printf("Printing elements of the 2D array\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int sizeOf1D = m * n;
    int OneDArr[sizeOf1D];
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            OneDArr[k++] = arr[i][j];
        }
    }

    printf("Printing 1D array after converting from 2D to 1D\n");

    for (int i = 0; i < sizeOf1D; i++)
    {
        printf("%d ", OneDArr[i]);
    }

    return 0;
}