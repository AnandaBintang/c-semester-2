#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct Stack
{
    int data[MAX_STACK_SIZE];
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
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack is full\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

char *isBalanced(char *bracket)
{
    Stack stack;
    createEmptyStack(&stack);
    for (int i = 0; bracket[i] != '\0'; i++)
    {
        // printf("Bracket: %c\n", bracket[i]);
        if (bracket[i] == '(' || bracket[i] == '{' || bracket[i] == '[')
        {
            push(&stack, bracket[i]);
            // printf("Push: %c\n", bracket[i]);
        }
        else
        {
            if (isEmpty(&stack))
            {
                return "NO";
            }
            else
            {
                char top = pop(&stack);
                // printf("Pop: %c\n", top);
                if ((top == '(' && bracket[i] != ')') || (top == '{' && bracket[i] != '}') || (top == '[' && bracket[i] != ']'))
                {
                    return "NO";
                }
            }
        }
    }
    return isEmpty(&stack) ? "YES" : "NO";
}

int main()
{
    char *bracket = "({[}])";

    printf("Bracket: %s\n", bracket);
    printf("%s\n", isBalanced(bracket));

    return 0;
}