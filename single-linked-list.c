#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Address;

struct Node
{
    int isi;
    Address next;
};

Address createNode(int nilai) // 5
{
    Address p;
    p = (Address)malloc(sizeof(struct Node));
    p->isi = nilai; // 5
    p->next = NULL;
    return (p);
}

Address insertFirst(Address head, int nilai) // 2, 5
{
    Address new_node = createNode(nilai); // 5
    // new_node->isi = 5
    // new_node->next = NULL
    new_node->next = head; // 2
    head = new_node;       // 5
    return (head);
}

void view(Address head)
{
    Address n = head;
    printf("Daftar nilai linked list : ");

    while (n != NULL)
    {
        printf("[%d] ", n->isi);
        n = n->next;
    };
    printf("\n");
}

int count(Address head)
{
    int count = 0;
    struct Node *p;
    p = head;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return (count);
}

void reverseList(Address *head)
{
    Address prev = NULL;
    Address current = *head;
    Address next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void sortDescList(Address head)
{
    Address current = head, index = NULL;
    int temp;

    if (head == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            index = current->next;

            while (index != NULL)
            {
                if (current->isi < index->isi)
                {
                    temp = current->isi;
                    current->isi = index->isi;
                    index->isi = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

int main()
{
    Address head = NULL;

    head = insertFirst(head, 2);
    head = insertFirst(head, 5);
    head = insertFirst(head, 1);
    head = insertFirst(head, 9);
    head = insertFirst(head, 7);
    head = insertFirst(head, 6);
    head = insertFirst(head, 10);
    head = insertFirst(head, 75);
    head = insertFirst(head, 21);
    head = insertFirst(head, 54);

    printf("Jumlah data : %d\n", count(head));
    printf("====================================\n");
    printf("Data sebelum dibalik : \n");
    view(head);
    printf("====================================\n");
    reverseList(&head);
    printf("Data setelah dibalik : \n");
    view(head);
    printf("====================================\n");
    printf("Data sebelum diurutkan : \n");
    view(head);
    printf("====================================\n");
    sortDescList(head);
    printf("Data setelah diurutkan : \n");
    view(head);

    printf("\n");

    return 0;
}