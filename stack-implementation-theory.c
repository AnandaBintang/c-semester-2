#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 // 0 - 99

typedef struct Identity
{
    char *name; // string
    int age;    // integer
} Identity;

typedef struct Stack
{
    Identity data[MAX_STACK_SIZE]; // array of Identity
    int top;
} Stack;

void createEmptyStack(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX_STACK_SIZE - 1; // 99
}

void push(Stack *stack, Identity identity)
{
    if (isFull(stack))
    {
        printf("Stack is full\n");
    }
    else
    {
        stack->top++;                       // 0
        stack->data[stack->top] = identity; // stack->data[0]
    }
}

Identity pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    else
    {
        Identity identity = stack->data[stack->top];
        stack->top--;
        return identity;
    }
}

Identity peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    else
    {
        return stack->data[stack->top];
    }
}

int main()
{
    Stack stack;
    createEmptyStack(&stack);

    Identity identity1 = {"Ananda Bintang Saputra", 19}; // Data KTP 1
    Identity identity2 = {"Vivi Intan Sari", 18};        // Data KTP 2

    push(&stack, identity1); // Ananda Bintang
    push(&stack, identity2); // Vivi Intan

    // Vivi Intan -> Peek
    // Ananda Bintang

    Identity topIdentity = peek(&stack); // Vivi Intan
    printf("Top identity: %s, %d\n", topIdentity.name, topIdentity.age);

    // Ananda Bintang

    Identity poppedIdentity = pop(&stack); // Vivi Intan
    printf("Popped identity: %s, %d\n", poppedIdentity.name, poppedIdentity.age);

    Identity newTopIdentity = peek(&stack); // Ananda Bintang
    printf("New top identity: %s, %d\n", newTopIdentity.name, newTopIdentity.age);

    return 0;
}