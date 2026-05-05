#include <stdio.h>

void reverse(char str[], int start, int end)
{
    if (start >= end)
        return;

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverse(str, start + 1, end - 1);
}

int length(char str[])
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int main()
{
    char str[1000];
    printf("Enter the string: ");
    scanf("%s", str);

    int len = length(str);
    reverse(str, 0, len - 1);

    printf("%s", str);
    return 0;
}

