#include <stdio.h>
#include <string.h>
#define N 100

int checkPalindrome(char *string, int size)
{
    int i;
    for (i = 0; i < --size; i++)
        if (string[i] != string[size])
            return 0;
    return 1;
}

int main()
{
    char string[N];
    printf("Enter string: ");
    fgets(string, N, stdin);
    printf("%s", (checkPalindrome(strlwr(string), strlen(string) - 1)) ? "Palindrome" : "Not Palindrome");
    return 0;
}
