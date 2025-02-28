NODE* deleteLast(NODE *head)
{
    NODE *temp=head, *pre=NULL;

    if(head==NULL)
    printf("Link List is empty...\nLast node does not exist..");
    else if(head->nxt==NULL)
    {
        free(head);
        head=NULL;
        printf("First/Last Node Delete...");
    }
    else
    {
        while(tmp->nxt!=NULL)
        {
            pre=tmp;
            tmp=tmp->next;
        }
        pre->nxt=NULL;
        free(tmp);
        printf("Last NODE is Delete");
    }
    return head;
}