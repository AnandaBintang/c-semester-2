#include <stdio.h>

char *oddEven(int num)
{
    char *response;
    if (num % 2 == 0)
    {
        response = "Bilangan ini genap";
    }
    else
    {
        response = "Bilangan ini ganjil";
    }

    return response;
}

void reverseString(char str[], int length)
{
    int start = 0, end = length - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

char *decimalToBinary(int decimal, char binaryStr[], int bufferSize)
{
    if (decimal == 0)
    {
        snprintf(binaryStr, bufferSize, "0");
        return binaryStr;
    }

    int i = 0;

    while (decimal > 0)
    {
        binaryStr[i] = (decimal % 2) + '0';
        decimal /= 2;
        i++;
    }

    reverseString(binaryStr, i);

    binaryStr[i] = '\0';

    return binaryStr;
}

int main()
{
    int numInput;
    int decimalNumber;
    char binaryRepresentation[33];

    printf("Nama : Ananda Bintang Saputra\nNIM : 1203230040\nKelas : IF 03-02\n");

    printf("=============== 1 ===============\n");
    printf("Masukkan bilangan yang ingin dicek: ");
    scanf("%d", &numInput);
    printf("\n%s", oddEven(numInput));

    printf("\n=============== 2 ===============\n");
    printf("Masukkan angka yang akan dikonversi jadi biner: ");
    scanf("%d", &decimalNumber);

    char *result = decimalToBinary(decimalNumber, binaryRepresentation, sizeof(binaryRepresentation));

    printf("Binary: %s\n", result);

    return 0;
}