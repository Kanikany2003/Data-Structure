#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct 
{
    int data[MAX];
    int f, r;
} QUEUE;

void init(QUEUE *q)
{
    q->f = -1;
    q->r = -1;
    printf("Queue Initialize...");
}

void qinsert(QUEUE *q, int val)
{
    if (q->r == MAX-1){
        printf("\nQUEUE OVERFLOW....");
    }
    else if (q->f == -1 && q->r == -1){
        q->f = 0;
        q->r = 0;
    }
    else{
        q->r++;
        q->data[q->r] = val;
        printf("Value %d inserted...\n", val);
    }
}

int qdelete(QUEUE *q)
{
    int val = -1;
    if ((q->f == -1 && q->r == -1) || (q->f > q->r))
    {
        printf("\nQUEUE UNDERFLOW....");
    }
    else
    {
        val = q->data[q->f];
        q->f++;
    }
    return val;
}

int qpeek(QUEUE *q)
{
    int val = -1;
    if ((q->f == -1 && q->r == -1) || (q->f > q->r))
    {
        printf("\nQUEUE UNDERFLOW....");
    }
    else
    {
        val = q->data[q->f];
    }
    return val;
}

int qchange(QUEUE *q, int pos, int val)
{
    int i = q->f + pos - 1;
    if (i >= q->f && i <= q->r){
        q->data[i] = val;
        return val;
    }
    else{
        printf("Invalid Position");
        return -1;
    }
}

void qdisplay(QUEUE *q)
{
    int i;
    if ((q->f == -1 && q->r == -1) || (q->f > q->r))
    {
        printf("\nQUEUE is Empty..");
    }
    else
    {
        for (i = q->f; i <= q->r; i++){
            printf("\t %d", q->data[i]);
        }
    }
}

int main()
{
    int val, pos, ch;
    QUEUE q;

    init(&q);

    do
    {
        printf("\nQUEUE OPERATIONS");
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Peek");
        printf("\n4.Change");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\nEnter Option: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1: 
            printf("\nPlease Enter the value: ");
            scanf("%d", &val);
            qinsert(&q, val);
            break;

        case 2: 
            val = qdelete(&q);
            if (val != -1)
                printf("\nThe number deleted is : %d", val);
            break;

        case 3:
            val = qpeek(&q);
            if (val != -1)
                printf("\nThe front value in queue is : %d", val);
            break;

        case 4: 
            printf("\nEnter the position: ");
            scanf("%d", &pos);
            printf("\nEnter the value: ");
            scanf("%d", &val);
            qchange(&q, pos, val);
            break;

        case 5: 
            qdisplay(&q);
            break;

        case 6: 
            printf("\nExiting...\n");
            break;

        default:
            printf("\nPlease enter the correct choice...");
        }

    } while (ch != 6);

    return 0;
}
