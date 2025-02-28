#include<stdio.h>
#define MAXLEN 50
#define MAX 10

typedef struct
{
    int data[MAX];
    int top;
}STACK;

int isOperator(char ch)
{
    if(ch=='-' || ch=='+' || ch=='*' || ch=='/' || ch=='%' || ch=='^')
        return 1;
    else
        return 0;
}

int getPrec(char ch)
{
    switch(ch)
    {
        case ')' : return 4;

        case '^' : return 3;

        case '*' :
        case '/' :
        case '%' : return 2;

        case '+' :
        case '-' : return 1;

        case '(' : return 0; 
        default : return -1;
    }
}

void infix2postfix(char *in, char *post)
{
    STACK s;
    char ch, op[MAXLEN] = " ";
    int i=0;
    init(&s);

    printf("\n\n================================================\n");
    printf("Input\t\tStack\t\tOutput");
    printf("\n================================================\n");

    while(*in!='\0')
    {
        printf("%c\t\t", *in);
        if(*in=='(')
        {
            push(&s,*in);
        }
        else if(*in==')')
        {
            while((ch==pop(&s))!='(')
            {
                *post = ch;
                op[i] = ch;
                post++;
                i++;
            }
        }
        else if(isOperator(*in))
        {
            while(getPrec(*in) <= getPrec(peep(&s)))
            {
                *post = pop(&s);
                op[i] = *post;
                post++;
                i++;
            }
            push(&s,*in);
        }
        else
        {
            *post=*in;
            op[i]=*in;
            post++;
            i++;
        }
        in++;

        display(&s);
        printf("\t\t%s\n", op);
        getch();
    }
    while(!isStackEmpty(&s))
    {
        *post=pop(&s);
        op[i] = *post;
        post++;
        i++;
    }
    *post='\0';
    display(&s);
    printf("\t\t\t\t%s", op);
    printf("\n================================================\n");
    getch();

}