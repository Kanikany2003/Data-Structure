#include <stdio.h>
#define MAX 5

typedef struct
{
    int data[MAX];
    int top;
} STACK;

void init(STACK *s)
{
    s->top = -1; // Added a semicolon
    printf("\nStack initialized");
}

void push(STACK *s, int val)
{
    if (s->top == MAX - 1)
    {
        printf("STACK OVERFLOW\n");
    }
    else
    {
        s->top++;
        s->data[s->top] = val;
        printf("Value %d pushed\n", val);
    }
}

int pop(STACK *s)
{
    int val = -1; // Initialize 'val' to -1
    if (s->top == -1)
    {
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        val = s->data[s->top];
        s->top--;
    }
    return val;
}

int peek(STACK *s)
{
    int val = -1; // Initialize 'val' to -1
    if (s->top == -1)
    {
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        val = s->data[s->top];
    }
    return val;
}

void change(STACK *s, int newVal)
{
    if (s->top == -1)
    {
        printf("STACK IS EMPTY\n");
    }
    else
    {
        s->data[s->top] = newVal;
        printf("Value at the top of the stack changed to %d\n", newVal);
    }
}

void display(STACK *s)
{
    int i;
    if (s->top == -1) // Change 'top' to 's->top'
    {
        printf("STACK IS EMPTY\n");
    }
    else
    {
        for (i = s->top; i >= 0; i--) // Change 'top' to 's->top'
        {
            printf("\n %d", s->data[i]);
        }
    }
}

int main()
{
    int choice, val, newVal;
    STACK s1;

    init(&s1);

    do
    {
        printf("\nSTACK OPERATION");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.PEEK");
        printf("\n4.CHANGE");
        printf("\n5.DISPLAY");
        printf("\n6.EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &val);
            push(&s1, val);
            break;

        case 2:
            val = pop(&s1);
            if (val != -1)
                printf("The value %d popped\n", val);
            break;

        case 3:
            val = peek(&s1);
            if (val != -1)
                printf("The value at the top of stack is %d\n", val);
            break;

        case 4:
            printf("Enter the new value: ");
            scanf("%d", &newVal);
            change(&s1, newVal);
            break;

        case 5:
            display(&s1); // Change 's' to '&s1'
            break;
        }
    } while (choice != 6);

    return 0;
}
