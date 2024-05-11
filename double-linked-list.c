#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

typedef struct Node node;

node *pHead = NULL;

void pressToContinue()
{
    printf("\nPress ENTER key to continue...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    getchar();
}

node *alokasiNodeBaru()
{
    node *pNew = NULL;
    pNew = (node *)malloc(sizeof(node));
    return (pNew);
}

void insertFirst(node *pNew)
{
    printf("Masukkan Bilangan: ");
    scanf("%d", &pNew->data);

    if (pHead == NULL)
    {
        pNew->prev = pHead;
        pNew->next = pHead;
        pHead = pNew;
    }
    else
    {
        pNew->prev = NULL;
        pNew->next = pHead;
        pHead->prev = pNew;
        pHead = pNew;
    }
}

void View()
{
    node *pWalker = pHead;
    int i = 1;

    if (pWalker == NULL)
    {
        printf("\n[DATA KOSONG]");
    }
    else
    {
        printf("\n");
        while (pWalker != NULL)
        {
            printf("%d ", pWalker->data);
            i++;
            pWalker = pWalker->next;
        }
    }
}

void ViewBackward()
{
    node *pWalker = pHead;
    int i = 1;

    if (pWalker == NULL)
    {
        printf("\n[DATA KOSONG]");
    }
    else
    {
        while (pWalker->next != NULL)
        {
            pWalker = pWalker->next;
        }

        printf("\n");
        while (pWalker != NULL)
        {
            printf("%d ", pWalker->data);
            i++;
            pWalker = pWalker->prev;
        }
    }
}

int main()
{
    node *pNew;

    for (int i = 0; i < 5; i++)
    {
        pNew = alokasiNodeBaru();
        insertFirst(pNew);
    }

    printf("\nData yang Dimasukkan (Secara berurutan): ");
    View();
    printf("\n");

    printf("\nData yang Dimasukkan (Secara terbalik): ");
    ViewBackward();
    printf("\n");
    printf("\n");

    return 0;
}