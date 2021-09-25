#include <stdio.h>
#define ll long long
int main()
{
    char num[100];
    printf("Enter a real number\n");
    scanf("%s", num);
    int mark = 0;
    for (ll i = 0; i < 100; i++)
    {
        if (num[i] == '.')
        {
            mark = 1;
            break;
        }
    }

    if (mark == 1)
    {
        printf("%s is a float value\n", num);
    }
    else
    {
        printf("%s is a whole number\n", num);
    }

    return 0;
}