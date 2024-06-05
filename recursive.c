#include <stdio.h>

int sumDigits(int n)
{
    if (n < 10)
    {
        return n;
    }
    // printf("n split = %d\n", n % 10);
    // printf("n/10 = %d\n", n / 10);
    return (n % 10 + sumDigits(n / 10)); // 5 + 4 + 3 + 2 + 1
}

long factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    // printf("n = %d\n", n);
    return n * factorial(n - 1); // 15 * 14 * 13 * 12 * 11...* 2 * 1 * 1
}

int main()
{
    int n = 12345;
    int sum = sumDigits(n);
    long fact = factorial(sum);

    printf("Hasil penjumlahan digit dari %d = %d\n", n, sum);
    printf("Hasil faktorial dari %d = %llu\n", sum, fact);

    return 0;
}