
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ll long long

void swap(long long *a, long long *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(long long arr[], long long n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{

    long long n;

    printf("Enter the size of the array \n");
    scanf("%lld", &n);
    printf("\n");
    clock_t begin;
    clock_t end;
    double time_spent;

    long long arr[n];
    long long x;
    printf("Press 1 for already sorted input and press 2 for randomly generated unsorted input\n");
    scanf("%d", &x);
    printf("\n");
    switch (x)
    {
    case 1:

        printf("Enter the sorted inputs\n\n");

        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        break;

    case 2:
        for (int i = 0; i < n; i++)
        {
            long long z = rand() % 1000000007;
            arr[i] = z;
        }
        break;
    }

    //Calculate the time taken by bubble sort

    begin = clock();
    bubbleSort(arr, n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Bubble sort = %f\n\n", time_spent);

    return 0;
}