#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void stringPyramid()
{
    char input[100];
    printf("Masukkan String: ");
    scanf(" %[^\n]s", input);

    for (int i = 0; i < strlen(input); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%c", input[j]);
        }
        printf("\n");
    }
}

void countAinString()
{
    char input[100];
    printf("Masukkan String: ");
    scanf(" %[^\n]s", input);

    int count = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == 'a' || input[i] == 'A')
        {
            count++;
        }
    }
    printf("Jumlah huruf 'a' dalam string adalah: %d\n", count);
}

void mainMenu()
{
    bool sedangBerjalan = true;

    do
    {
        int pilihan;
        printf("1. Ulang\n");
        printf("2. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("\n");
            break;
        case 2:
            printf("Keluar dari program\n");
            sedangBerjalan = false;
            break;
        default:
            printf("Menu tidak tersedia\n");
            break;
        }
    } while (sedangBerjalan);
}

void starPyramid()
{
    int n;
    printf("Masukkan jumlah baris: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

int main()
{
    bool isRunning = true;
    int choice;

    do
    {
        printf("1. Piramida dari String\n");
        printf("2. Hitung huruf 'A' di suatu String\n");
        printf("3. Menu\n");
        printf("4. Piramida Bintang\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            stringPyramid();
            break;
        case 2:
            countAinString();
            break;
        case 3:
            mainMenu();
            break;
        case 4:
            starPyramid();
            break;
        case 5:
            printf("Keluar dari program\n");
            isRunning = false;
            break;
        default:
            printf("Menu tidak tersedia\n");
        }
    } while (isRunning);

    return 0;
}