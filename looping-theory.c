#include <stdio.h>

void numLoop()
{
    for (int i = 1; i <= 15; i++)
    {
        printf("%d ", i);
        if (i % 5 == 0)
        {
            printf("\n");
        }
    }
}

void numPower()
{
    int num, numInput, power;

    printf("Masukkan angka yang mau dipangkatkan: ");
    scanf("%d", &num);
    printf("Masukkan pangkat sampai berapa: ");
    scanf("%d", &power);

    numInput = num;
    for (int i = 1; i <= power; i++)
    {
        printf("%d ", num);
        num *= numInput;
    }
}

int main()
{
    numLoop();
    printf("\n");
    numPower();
    printf("\n");

    return 0;
}