/*
/////////////////////////////////////////////////////////////////////////////////////////////
            Program :  Singly Circular Linked  List
            Date    : 27/6/2025
            Insertion : InsertFirst,InsertLast,InsertAtPos 
            Deletion  : DeleteFirst,DeleteLast,DeleteAtPos
            Display   : DiaplayNodes
            Count     : Count Node


////////////////////////////////////////////////////////////////////////////////////////////
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;

};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int Count(PNODE first,PNODE last)
{
    int icount=0;
    if(first==NULL && last == NULL)
    {
        return icount;
    }
    do
    {
        icount++;
        first = first->next;
    }while(first !=last->next);

    printf("\n");
    return icount;
}
void InsertFirst(PPNODE first,PPNODE last,int no)
{
    
    PNODE newn = NULL;
    newn = (PNODE) malloc (sizeof(NODE));
    newn ->data = no;
    newn->next =NULL;   

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;

        (*last)->next = *first;
    }
    
    else
    {
        newn->next = *first;
        *first = newn;
        (*last)->next = *first;

    }
}

////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;
    newn = (PNODE) malloc (sizeof(NODE));
    newn ->data = no;
    newn->next =NULL;   

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;

        (*last)->next = *first;
    }
    
    else
    {
        (*last)->next = newn;
        *last = newn;
        (*last)->next = *first;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first,PPNODE last,int no,int pos)
{
    int icount = 0,icnt=0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    icount = Count(*first,*last);
    if(pos<1 || pos>icount+1)
    {
        printf("Invalid position:\n");
        return;
    }
    if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos ==icount+1)
    {
        InsertLast(first,last,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        temp = *first;
        for(icnt =1; icnt<pos-1;icnt++)
        {
            temp = temp->next;
        }
        newn->next =temp->next;
        temp->next = newn;
    }

}

////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first,PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*last)->next);

        (*last)->next = *first;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////


void DeleteLast(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;
        while(temp->next!=*last)
        {
            temp = temp->next;
        }
        free(*last);
        *last = temp;

        (*last)->next =*first;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////


void DeleteAtPos(PPNODE first,PPNODE last,int pos)
{
     int icount = 0,icnt=0;
    PNODE temp = NULL;
    PNODE target = NULL;

    icount = Count(*first,*last);
    if(pos<1 || pos>icount)
    {
        printf("Invalid position:\n");
        return;
    }
    if(pos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(pos ==icount)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;

        for(icnt =1;icnt<pos-1;icnt++)
        {
            temp=temp->next;
        }
        target = temp->next;
        temp->next =target->next;
        free(target);
    }

}

////////////////////////////////////////////////////////////////////////////////////////////


void Display(PNODE first,PNODE last)
{
if(first==NULL && last == NULL)
{
    return;
}
    do
    {
        printf("| %d | ->",first->data);
        first = first->next;
    }while(first !=last->next);
    printf("\n");
}

////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    int iRet = 0;
    PNODE head = NULL;
    PNODE tail = NULL;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);

    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of elements are:%d \n",iRet);

    InsertAtPos(head,tail,105,5);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of elements are:%d \n",iRet);

    DeleteAtPos(head,tail,4);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of elements are:%d \n",iRet);

    return 0;
}