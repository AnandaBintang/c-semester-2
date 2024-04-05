#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct
{
    int data[MAX];
    int front;
    int rear;
} Queue;

void init(Queue *queue)
{
    queue->front = queue->rear = -1;
}

bool isEmpty(Queue *queue)
{
    return queue->front == -1 && queue->rear == -1;
}

bool isFull(Queue *queue)
{
    return queue->rear == MAX - 1;
}

void enqueue(Queue *queue, int newValue)
{
    if (!isFull(queue)) // Jika queue tidak penuh
    {
        if (isEmpty(queue)) // Jika queue kosong
        {
            queue->front++;                        // front di increment (ditambah 1) karena queue kosong (front = -1, rear = -1)
            queue->data[++queue->rear] = newValue; // rear di increment (ditambah 1) dan data di rear diisi dengan newValue
            return;
        }
        queue->data[++queue->rear] = newValue; // rear di increment (ditambah 1) dan data di rear diisi dengan newValue
        return;
    }
    printf("Queue is full\n");
}

void dequeue(Queue *queue)
{
    if (!isEmpty(queue)) // Jika queue tidak kosong
    {
        if (queue->front == 0 && queue->rear == 0) // Jika queue hanya memiliki 1 elemen
        {
            queue->front--; // front di decrement (dikurangi 1) agar front = -1
            queue->rear--;  // rear di decrement (dikurangi 1) agar rear = -1
            return;
        }
        for (int i = queue->front + 1; i < queue->rear + 1; i++) // Looping dari front + 1 sampai rear
        {
            queue->data[i - 1] = queue->data[i]; // Data di index i diisi dengan data di index i + 1
        }
        queue->rear--; // rear di decrement (dikurangi 1)
        return;
    }
    printf("Queue is empty\n");
}

int front(Queue *queue)
{
    return !isEmpty(queue) ? queue->data[queue->front] : -1; // Jika queue tidak kosong, kembalikan data di front, jika kosong kembalikan -1
}

int rear(Queue *queue)
{
    return !isEmpty(queue) ? queue->data[queue->rear] : -1; // Jika queue tidak kosong, kembalikan data di rear, jika kosong kembalikan -1
}

int size(Queue *queue)
{
    return queue->rear + 1; // Jumlah elemen dalam queue adalah rear + 1
}

void printQueue(Queue *queue)
{
    if (!isEmpty(queue)) // Jika queue tidak kosong
    {
        for (int i = queue->front; i < queue->rear + 1; i++) // Looping dari front sampai rear
        {
            printf("%d ", queue->data[i]); // Print data di index i
        }
        printf("\n");
        return;
    }
    printf("Queue is empty\n");
}

int main()
{
    Queue queue;
    init(&queue);

    int option;

    while (1)
    {
        printf("---------------------------------------------------------------\n");
        printf("Queue: ");
        printQueue(&queue);
        printf("\t|\tFront: %d", front(&queue));
        printf("\t|\tRear: %d\n", rear(&queue));
        printf("\t|\tSize: %d\n", size(&queue));
        printf("---------------------------------------------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("---------------------------------------------------------------\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &option);
        if (option == 1)
        {
            int value;
            printf("Masukkan nilai baru: ");
            scanf("%d", &value);
            enqueue(&queue, value);
        }
        else if (option == 2)
        {
            dequeue(&queue);
        }
        else if (option == 3)
        {
            break;
        }
        else
        {
            printf("Opsi tidak valid!\n");
        }

        system("clear"); // gunakan system("cls") pada sistem operasi Windows
    }
    return 0;
}