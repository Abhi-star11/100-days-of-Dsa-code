#include <stdio.h>

long long power(int a, int b)
{
    if (b == 0)
        return 1;
    return a * power(a, b - 1);
}

int main()
{
    int a, b;
    printf("The first number: ");
    scanf("%d", &a);
    printf("The second number: ");
    scanf("%d",&b);
    printf("%lld", power(a, b));
    return 0;
}

