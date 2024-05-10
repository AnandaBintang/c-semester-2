#include <stdio.h>   // input output
#include <stdbool.h> // boolean

#define MAX 10 // 0 - 9

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
    return queue->rear == MAX - 1; // 10 - 1
}

char *checkPatientSeverity(int patient)
{
    if (patient >= 1 && patient <= 5)
    {
        return "ditangani dokter umum";
    }
    else
    {
        return "ditangani dokter spesialis";
    }
    return "unknown";
}

void enqueue(Queue *queue, int patient)
{
    if (!isFull(queue)) // Jika queue tidak penuh
    {
        printf("Pasien dengan tingkat keparahan %d %s\n", patient, checkPatientSeverity(patient));
        if (isEmpty(queue)) // Jika queue kosong
        {
            queue->front++;                       // front di increment (ditambah 1) karena queue kosong (front = -1, rear = -1)
            queue->data[++queue->rear] = patient; // rear di increment (ditambah 1) dan data di rear diisi dengan patient
            return;
        }
        queue->data[++queue->rear] = patient; // rear di increment (ditambah 1) dan data di rear diisi dengan patient
        return;
    }
    printf("Queue is full\n");
}

int main()
{
    Queue queue;     // queue
    int patient[10]; // array pasien
    init(&queue);    // inisialisasi queue

    scanf("%d %d %d %d %d %d %d %d %d %d", &patient[0], &patient[1], &patient[2], &patient[3], &patient[4], &patient[5], &patient[6], &patient[7], &patient[8], &patient[9]);

    for (int i = 0; i < 10; i++)
    {
        enqueue(&queue, patient[i]);
    }

    return 0;
}