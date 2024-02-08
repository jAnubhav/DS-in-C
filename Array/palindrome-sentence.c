#include <stdio.h>
#include <string.h>
#define N 100

int palindrome(char string[], int size)
{
    int i;
    for (i = 0; i < --size; i++)
    {
        while ('a' > string[i] || string[i] > 'z')
            i++;
        while ('a' > string[size] || string[size] > 'z')
            size--;
        if (string[i] != string[size])
            return 0;
    }
    return 1;
}

int main()
{

    char string[N];
    printf("Enter string: ");
    fgets(string, N, stdin);
    printf("%s", (palindrome(strlwr(string), strlen(string))) ? "Palindrome" : "Not Palindrome");
}
