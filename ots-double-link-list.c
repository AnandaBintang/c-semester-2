#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

typedef struct node node;

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

void inserLast(node *pNew)
{
    node *pEnd;
    pEnd = pHead;

    printf("Masukkan Nilai yang Ingin Ditambahkan: ");
    scanf("%d", &pNew->data);

    while (pEnd->next != NULL)
    {
        pEnd = pEnd->next;
    }

    pEnd->next = pNew;
    pNew->prev = pEnd;
    pNew->next = NULL;
}

void insertAfter(node *pNew)
{
    node *pWalker;
    pWalker = pHead;

    int nilai, sisip;

    printf("Masukkan Nilai yang Ingin Ditambahkan: ");
    scanf("%d", &pNew->data);

    printf("Data Disisipkan Setelah Nilai: ");
    scanf("%d", &sisip);

    while (pWalker != NULL && pWalker->data != sisip)
    {
        pWalker = pWalker->next;
    }

    if (pWalker == NULL)
    {
        printf("\nData Tidak Ditemukan");
        pressToContinue();
    }
    else if (pWalker->data == sisip)
    {
        pNew->next = pWalker->next;
        pWalker->next->prev = pNew;
        pWalker->next = pNew;
        pNew->prev = pWalker;
    }
    else
    {
        while (pWalker->next != NULL)
        {
            pWalker = pWalker->next;
        }
        pWalker->next = pNew;
        pNew->prev = pWalker;
        pNew->next = NULL;
    }
}

void deleteFirst()
{
    node *pHapus;

    if (pHead->next == NULL)
    {
        pHead = NULL;
    }
    else
    {
        pHapus = pHead;
        pHead = pHead->next;
        pHead->prev = NULL;

        free(pHapus);
    }
}

void deleteLast()
{
    node *pEnd;
    pEnd = pHead;

    if (pHead->next == NULL)
    {
        pHead = NULL;
    }
    else
    {
        while (pEnd->next != NULL)
        {
            pEnd = pEnd->next;
        }
        pEnd->prev->next = NULL;
        free(pEnd);
    }
}

void deleteAfter()
{
    node *pCari;
    int hapus;

    pCari = pHead;

    printf("head: %d", pHead->data);

    printf("Masukkan Bilangan yang Ingin Dihapus: ");
    scanf("%d", &hapus);

    while (pCari != NULL && pCari->data != hapus)
    {
        pCari = pCari->next;
        printf("%d", pCari->data);
    }
    system("pause");
    if (pCari == NULL)
    {
        printf("\nData Tidak Ditemukan");
        pressToContinue();
    }
    else if (pHead->next == NULL)
    {
        pHead = NULL;
    }
    else if (pCari == pHead)
    {
        pCari = pHead;
        pHead = pHead->next;
        pHead->prev = NULL;

        free(pCari);
    }
    else if (pCari->next == NULL)
    {
        pCari->prev->next = NULL;
        free(pCari);
    }
    else
    {
        pCari->prev->next = pCari->next;
        pCari->next->prev = pCari->prev;

        free(pCari);
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
            printf("[%d] ", pWalker->data);
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
            printf("[%d] ", pWalker->data);
            i++;
            pWalker = pWalker->prev;
        }
    }
}

int main()
{
    node *pNew;
    int pilih, bil;

    do
    {
        printf("\e[1;1H\e[2J");
        if (pHead != NULL)
        {
            printf("pHead: %d", pHead->data);
            if (pHead->next != NULL)
            {
                printf("\npHead->next: %d", pHead->next->data);
            }
            if (pHead->prev != NULL)
            {
                printf("\npHead->prev: %d", pHead->prev->data);
            }
        }

        printf("\n\n");
        printf("------------ MENU ------------");
        printf("\n1. Insert First");
        printf("\n2. Insert Last");
        printf("\n3. Insert After");
        printf("\n4. Delete First");
        printf("\n5. Delete Last");
        printf("\n6. Delete After");
        printf("\n7. View Data");
        printf("\n8. View Data Backward");
        printf("\n9. Exit");

        printf("\nPilihan: ");
        scanf("%d", &pilih);

        if (pilih == 1)
        {
            pNew = alokasiNodeBaru();
            insertFirst(pNew);
        }
        else if (pilih == 2)
        {
            pNew = alokasiNodeBaru();
            inserLast(pNew);
        }
        else if (pilih == 3)
        {
            pNew = alokasiNodeBaru();
            insertAfter(pNew);
        }
        else if (pilih == 4)
        {
            deleteFirst();
        }
        else if (pilih == 5)
        {
            deleteLast();
        }
        else if (pilih == 6)
        {
            deleteAfter();
        }
        else if (pilih == 7)
        {
            View();
            pressToContinue();
        }
        else if (pilih == 8)
        {
            ViewBackward();
            pressToContinue();
        }
    } while (pilih != 9);

    printf("\n");
    return 0;
}