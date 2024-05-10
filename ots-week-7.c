#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char name[50];
    char phone[20];
    struct Contact *next;
};

void pressToContinue()
{
    printf("Press ENTER key to continue...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    getchar();
}

void add_contact(struct Contact **head_ref, char name[], char phone[])
{
    struct Contact *new_contact = (struct Contact *)malloc(sizeof(struct Contact));
    if (new_contact == NULL)
    {
        printf("Memori tidak cukup.\n");
        return;
    }
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone, phone);
    new_contact->next = *head_ref;
    *head_ref = new_contact;
    printf("Kontak berhasil ditambahkan.\n");
}

struct Contact *find_contact(struct Contact *head, char name[])
{
    struct Contact *current = head;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void print_contacts(struct Contact *head)
{
    if (head == NULL)
    {
        printf("Daftar kontak kosong.\n");
    }
    else
    {
        printf("Daftar Kontak:\n");
        while (head != NULL)
        {
            printf("Nama: %s, Nomor Telepon: %s\n", head->name, head->phone);
            head = head->next;
        }
    }
}

void free_contacts(struct Contact *head)
{
    struct Contact *current = head;
    while (current != NULL)
    {
        struct Contact *next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
    struct Contact *contact_list = NULL;
    char choice;
    char name[50];
    char phone[20];

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Tambah Kontak\n");
        printf("2. Cari Kontak\n");
        printf("3. Cetak Daftar Kontak\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            printf("Masukkan nama kontak: ");
            scanf("%s", name);
            printf("Masukkan nomor telepon: ");
            scanf("%s", phone);
            add_contact(&contact_list, name, phone);
            pressToContinue();
            break;
        case '2':
            printf("Masukkan nama kontak yang ingin dicari: ");
            scanf("%s", name);
            struct Contact *contact = find_contact(contact_list, name);
            if (contact != NULL)
            {
                printf("Nama: %s, Nomor Telepon: %s\n", contact->name, contact->phone);
            }
            else
            {
                printf("Kontak tidak ditemukan.\n");
            }
            pressToContinue();
            break;
        case '3':
            print_contacts(contact_list);
            pressToContinue();
            break;
        case '4':
            free_contacts(contact_list);
            printf("Terima kasih!\n");
            return 0;
        default:
            printf("Pilihan tidak valid. Silakan masukkan pilihan yang benar.\n");
        }
    }
}