// double linked list circular

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

typedef struct Node node;

node *pHead = NULL;
node *pTail = NULL;

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

void insertFirst(int data)
{
    node *pNew = alokasiNodeBaru();

    if (pNew == NULL)
    {
        printf("\n[ALOKASI GAGAL]");
    }
    else
    {
        pNew->data = data;
        pNew->prev = NULL;
        pNew->next = NULL;

        if (pHead == NULL)
        {
            pHead = pNew;
            pTail = pNew;
            pHead->next = pHead;
            pHead->prev = pHead;
        }
        else
        {
            pNew->next = pHead;
            pNew->prev = pTail;
            pHead->prev = pNew;
            pTail->next = pNew;
            pHead = pNew;
        }
    }
}

void insertLast(int data)
{
    node *pNew = alokasiNodeBaru();

    if (pNew == NULL)
    {
        printf("\n[ALOKASI GAGAL]");
    }
    else
    {
        pNew->data = data;
        pNew->prev = NULL;
        pNew->next = NULL;

        if (pHead == NULL)
        {
            pHead = pNew;
            pTail = pNew;
            pHead->next = pHead;
            pHead->prev = pHead;
        }
        else
        {
            pNew->prev = pTail;
            pNew->next = pHead;
            pTail->next = pNew;
            pHead->prev = pNew;
            pTail = pNew;
        }
    }
}

void insertAfter(int key, int data)
{
    node *pNew = alokasiNodeBaru();
    node *pWalker = pHead;

    if (key == pTail->data)
    {
        insertLast(data);
    }
    else if (pNew == NULL)
    {
        printf("\n[ALOKASI GAGAL]");
    }
    else
    {
        pNew->data = data;
        pNew->prev = NULL;
        pNew->next = NULL;

        if (pHead == NULL)
        {
            pHead = pNew;
            pTail = pNew;
            pHead->next = pHead;
            pHead->prev = pHead;
        }
        else
        {
            while (pWalker->data != key)
            {
                pWalker = pWalker->next;
            }

            pNew->next = pWalker->next;
            pNew->prev = pWalker;
            pWalker->next->prev = pNew;
            pWalker->next = pNew;
        }
    }
}

void deleteFirst()
{
    node *pDel = pHead;

    if (pHead == NULL)
    {
        printf("\n[DATA KOSONG]");
    }
    else if (pHead == pTail)
    {
        pHead = NULL;
        pTail = NULL;
        free(pDel);
    }
    else
    {
        pHead = pHead->next;
        pHead->prev = pTail;
        pTail->next = pHead;
        free(pDel);
    }
}

void deleteLast()
{
    node *pDel = pTail;

    if (pHead == NULL)
    {
        printf("\n[DATA KOSONG]");
    }
    else if (pHead == pTail)
    {
        pHead = NULL;
        pTail = NULL;
        free(pDel);
    }
    else
    {
        pTail = pTail->prev;
        pTail->next = pHead;
        pHead->prev = pTail;
        free(pDel);
    }
}

void view()
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
        while (pWalker != pTail)
        {
            printf("%d ", pWalker->data);
            i++;
            pWalker = pWalker->next;
        }
        printf("%d ", pWalker->data);
    }
    printf("\n");
}

int main()
{
    node *pNew = NULL;

    insertLast(90);
    view();
    insertLast(75);
    view();
    insertFirst(21);
    view();
    deleteLast();
    view();
    insertFirst(91);
    view();
    deleteFirst();
    view();
    insertFirst(110);
    view();
    insertAfter(90, 63);
    view();

    return 0;
}