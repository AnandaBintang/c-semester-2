#include <stdio.h>

typedef struct Date
{
    int day;
    int month;
    int year;
} Time;

int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

Time predictTomorrow(Time today)
{
    Time tomorrow;

    tomorrow.day = today.day + 1;
    tomorrow.month = today.month;
    tomorrow.year = today.year;

    if (tomorrow.day > 31 && tomorrow.month % 2 != 0 ||
        (tomorrow.day > 30 && tomorrow.month != 2 && tomorrow.month % 2 == 0) ||
        (tomorrow.day > 29 && tomorrow.month == 2 && isLeapYear(tomorrow.year)) ||
        (tomorrow.day > 28 && tomorrow.month == 2 && !isLeapYear(tomorrow.year)))
    {
        tomorrow.day = 1;
        tomorrow.month++;

        if (tomorrow.month > 12)
        {
            tomorrow.month = 1;
            tomorrow.year++;
        }
    }

    return tomorrow;
}

int main()
{
    Time today;
    printf("Masukkan tanggal hari ini (dd mm yyyy): ");
    scanf("%d %d %d", &today.day, &today.month, &today.year);

    if (today.day != 0 && today.day <= 31 && today.month != 0 && today.month <= 12)
    {
        Time tomorrow = predictTomorrow(today);
        printf("Ramalan untuk hari esok:\n");
        printf("Tanggal: %02d/%02d/%04d\n", tomorrow.day, tomorrow.month, tomorrow.year);
    }
    else
    {
        printf("Invalid!\n");
    }

    return 0;
}