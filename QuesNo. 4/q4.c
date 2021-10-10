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

void SelectionSort(long long arr[], long long n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(&arr[j], &arr[i]);
            }
        }
    }
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

    clock_t st, en;
    long long int tot;
    st = clock();

    //Calculate the time taken by bubble sort
    clock_t start, end;
    long int t;
    start = clock();

    SelectionSort(arr, n);
    end = clock();
    t = end - start;
    printf("Total time elapsed for selection sort: %f\n", (double)t / (double)CLOCKS_PER_SEC);
    clock_t start2, end2;
    long int t2;
    start2 = clock();
    bubbleSort(arr, n);
    end2 = clock();
    t2 = end2 - start2;
    printf("Total time elapsed for bubble sort: %f\n", (double)t2 / (double)CLOCKS_PER_SEC);

    en = clock();
    tot = en - st;

    printf("Total time elapsed is = %f\n", (double)tot / (double)CLOCKS_PER_SEC);
    return 0;
}