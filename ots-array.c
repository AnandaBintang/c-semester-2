#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void removeSpaces(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] != ' ')
        {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
}

int compare(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

void sortString(char *str)
{
    qsort(str, strlen(str), sizeof(char), compare);
}

int main()
{
    char input[1000];

    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    removeSpaces(input);

    sortString(input);

    printf("%s\n", input);

    return 0;
}