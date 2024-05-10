#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
    int top;
    char data[MAX];
} Stack;

void createEmptyStack(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack stack)
{
    return stack.top == -1;
}

int isFull(Stack stack)
{
    return stack.top == MAX - 1;
}

void push(Stack *stack, char value)
{
    if (isFull(*stack))
    {
        printf("Stack is Full\n");
    }
    else
    {
        stack->top++;
        stack->data[stack->top] = value;
    }
}

char pop(Stack *stack)
{
    if (isEmpty(*stack))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    else
    {
        char value = stack->data[stack->top];
        stack->top--;
        return value;
    }
}

int main()
{
    Stack stack;
    createEmptyStack(&stack);

    char str[] = "92847";
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        push(&stack, str[i]);
    }

    int num = 0;
    int multiplier = 1;

    while (!isEmpty(stack))
    {
        char c = pop(&stack);
        num += (c - '0') * multiplier;
        multiplier *= 10;
    }

    printf("angka konversi integer = %d\n", num);
    printf("========== Bukti bahwa string menjadi integer ==========\n");
    printf("angka(%s) + 1 = %d\n", str, num + 1);

    return 0;
}