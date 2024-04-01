#include <stdio.h>
int main()
{
    // Init Variable
    int math, indo, eng, science, social;
    double avg;
    char grade, *opt;
    // Init Variable Value
    math = 0;
    indo = 0;
    eng = 0;
    science = 0;
    social = 0;
    avg = 0;
    grade = "E";
    opt = "";
    // Input from User
    printf("Masukkan nilai Math: ");
    scanf("%i", &math);
    printf("==============================\n");
    printf("Masukkan nilai Bahasa Indonesia: ");
    scanf("%i", &indo);
    printf("==============================\n");
    printf("Masukkan nilai Bahasa Inggris: ");
    scanf("%i", &eng);
    printf("==============================\n");
    printf("Masukkan nilai IPA: ");
    scanf("%i", &science);
    printf("==============================\n");
    printf("Masukkan nilai IPS: ");
    scanf("%i", &social);
    printf("==============================\n\n");
    // Count Average
    avg = (double)(math + indo + eng + science + social) / 5;
    if (avg >= 90)
    {
        grade = 'A';
        switch ((int)avg)
        {
        case 100:
            opt = "Sempurna!!!";
            break;
        default:
            opt = "Baik!!!";
            break;
        }
    }
    else if (avg >= 80)
    {
        grade = 'B';
    }
    else if (avg >= 70)
    {
        grade = 'C';
    }
    else if (avg >= 60)
    {
        grade = 'D';
    }
    else
    {
        grade = 'E';
    }
    printf("Karena rata-rata anda %.2lf, maka Grade anda adalah '%c'. %s\n", avg, grade, opt);
    printf("==============================\n");
    return 0;
}