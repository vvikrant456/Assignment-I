

#include <stdio.h>
#include <string.h>
#define ll long long
int main()
{
    // int t;
    // scanf("%d", &t);
    // while (t--)
    // {
    char email[200] = {'\0'};
    scanf("%s", email);

    char domain_part[100];
    int n = strlen(email);
    int breakPoint;
    int mark = 0;
    int atTheRateCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (email[i] == '@')
        {
            breakPoint = i;
            mark = 1;
            // printf("Initial check fail\n");
            atTheRateCount++;
        }
    }

    if ((breakPoint < n && breakPoint <= 64) && (mark == 1) && (atTheRateCount == 1))
    {

        int sizeOfLocal = breakPoint;
        char localPart[sizeOfLocal];
        int sizeOfDomain = n - breakPoint - 1;
        char domainPart[sizeOfDomain];
        // printf("%d   %d   %d  %d  %c\n", n, sizeOfLocal, sizeOfDomain, breakPoint, email[sizeOfLocal]);

        //Now Check local Part
        int check = 1;

        if ((localPart[0] == '_' || localPart[sizeOfLocal - 1] == '_' || localPart[0] == '-' || localPart[sizeOfLocal - 1] == '-' || localPart[0] == '.' || localPart[sizeOfLocal - 1] == '.') && check == 1)
        {
            // printf("Fail check1\n");
            check = 0;
        }

        for (int i = 1; i < sizeOfLocal && check == 1; i++)
        {
            if ((localPart[i] == '_' || localPart[i - 1] == '_') || (localPart[i] == '.' || localPart[i - 1] == '.') || (localPart[i] == '-' || localPart[i - 1] == '-') || (localPart[i] == '@' || localPart[i - 1] == '@'))
            {
                check = 0;
                // printf("Fail check 2\n");
                break;
            }
        }

        for (int i = 0; i < sizeOfLocal && check == 1; i++)
        {

            if ((localPart[i] < '0' && localPart[i] > '9') || (localPart[i] < 'A' && localPart[i] > 'Z') || (localPart[i] < 'a' && localPart[i] > 'z'))
            {
                // printf("Local Fail\n");
                // printf("%c\n", localPart[i]);
                check = 0;
                break;
            }
        }

        int dotmark = 0, dotindx = 0;

        for (int i = breakPoint + 1; i < n; i++)
        {
            if ((domainPart[i] < '0' && domainPart[i] > '9') || (domainPart[i] < 'A' && domainPart[i] > 'Z') || (domainPart[i] < 'a') && domainPart[i] > 'z')
            {
                // printf("Domain Fail\n");
                // printf("%c\n", domainPart[i]);
                check = 0;
                break;
            }

            if (domainPart[i] == '.')
            {
                dotmark = 1;
                dotindx = i;
            }
        }
        if (n - dotindx < 2)
        {
            mark = 0;
        }
        if (mark == 1 && check == 1)
        {
            printf("valid email address\n");
        }
        else
        {
            printf("InValid email address\n");
        }
    }
    else
    {
        printf("Invalid email address\n");
    }
    // }

    return 0;
}