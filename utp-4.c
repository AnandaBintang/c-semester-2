#include <stdio.h>   // input output
#include <stdbool.h> // boolean

#define MAX 10 // 0 - 9

typedef struct
{
    char *name;
    int severity;
} Patient;

typedef struct
{
    Patient data[MAX];
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

void enqueue(Queue *queue, Patient *patient)
{
    if (!isFull(queue))
    {
        if (isEmpty(queue))
        {
            queue->front++;
            queue->data[++queue->rear] = *patient;
            return;
        }
        queue->data[++queue->rear] = *patient;
        return;
    }
    printf("Queue is full\n");
}

void sortQueueDescending(Queue *queue)
{
    for (int i = queue->front; i < queue->rear; i++)
    {
        for (int j = i + 1; j < queue->rear + 1; j++)
        {
            if (queue->data[i].severity < queue->data[j].severity)
            {
                Patient temp = queue->data[i];
                queue->data[i] = queue->data[j];
                queue->data[j] = temp;
            }
        }
    }
}

void printQueue(Queue *queue)
{
    for (int i = queue->front; i < queue->rear + 1; i++)
    {
        int antrian = i + 1;
        printf("Antrian %d: pasien bernama: %s, dengan tingkat keparahan penyakit: %d\n", antrian, queue->data[i].name, queue->data[i].severity);
    }
    printf("\n");
}

int main()
{
    Queue queue;
    Patient patient[10] = {
        {"A", 7},
        {"B", 4},
        {"C", 3},
        {"D", 6},
        {"E", 1},
        {"F", 9},
        {"G", 4},
        {"H", 8},
        {"I", 10},
        {"J", 2},
    };
    init(&queue);

    for (int i = 0; i < 10; i++)
    {
        enqueue(&queue, &patient[i]);
    }

    sortQueueDescending(&queue);
    printf("Antrian pasien berdasarkan tingkat keparahan penyakit: \n");
    printQueue(&queue);

    return 0;
}