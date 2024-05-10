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
        printf("Stack is full\n");
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

    char str[] = "123456789";
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        push(&stack, str[i]);
    }

    Stack stack1, stack2, stack3;
    createEmptyStack(&stack1);
    createEmptyStack(&stack2);
    createEmptyStack(&stack3);

    for (int i = 0; i < len; i++)
    {
        if (i < len / 3)
        {
            push(&stack1, pop(&stack));
        }
        else if (i < 2 * len / 3)
        {
            push(&stack2, pop(&stack));
        }
        else
        {
            push(&stack3, pop(&stack));
        }
    }

    printf("Stack 1\n");
    while (!isEmpty(stack1))
    {
        printf("%c\n", pop(&stack1));
    }

    printf("Stack 2\n");
    while (!isEmpty(stack2))
    {
        printf("%c\n", pop(&stack2));
    }

    printf("Stack 3\n");
    while (!isEmpty(stack3))
    {
        printf("%c\n", pop(&stack3));
    }

    return 0;
}