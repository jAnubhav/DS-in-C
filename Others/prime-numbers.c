#include <stdio.h>
#define FIRST_PRIME 2

int main()
{
    int num, i, j, count;
    printf("Enter a number");
    scanf("%d", &num);
    if (num > 1)
    {
        printf("The prime numbers from 0 to %d are:\n", num);
        for (i = FIRST_PRIME; i <= num; i++)
        {
            count = 0;
            for (j = FIRST_PRIME; j * j <= i; j++)
                if (!(i % j))
                    count++;
            if (!count)
                printf("%-6d", i);
        }
    }
    else
        printf("No such Number.");
}
