/*
////////////////////////////////////////////////////////////////////////////////////////////

                Program: Singly Linked List
                Date   : 26 / 6 / 2025
                Insertion : InsertFirst,InsertLast,InsertAtPos 
                Deletion  : DeleteFirst,DeleteLast,DeleteAtPos
                Display   : DiaplayNodes
                Count     : Count Node

///////////////////////////////////////////////////////////////////////////////////////
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

///////////////////////////////////////////////////////////////////////////////

void InserFirst(PPNODE first,int no)
{
    PNODE newn = NULL;      
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
   
    newn->next = *first;
    *first = newn;
}
////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first,int no)
{
    PNODE temp = NULL;
    PNODE newn = NULL; 
                             // pointer
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while(temp->next !=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;

    }
}

/////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ",first->data);
        first = first->next;
    }
    printf("NULL\n");

}

//////////////////////////////////////////////////////////////////////////////
int Count(PNODE first)
{
    int iCount = 0;
     while(first!= NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;
    if(*first == NULL)                      //Empty LL
    {
        return;

    }
    else if((*first)->next == NULL)         //Single Node
    {
        free(*first);
        *first = NULL;
    }
    else                                    //More than one
    {
        temp = *first;
        *first = (*first)->next;
        free(temp);
    }
}

//////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;
    if(*first == NULL)                      //Empty LL
    {
        return;
    }
    else if((*first)->next == NULL)      //Single Node
    {
        free(*first);
        *first = NULL;
    }
    else                                //More than one
    {
        temp = *first;
        while(temp->next->next != NULL)
        {
            temp = temp->next; 
        }
      free(temp->next);
      temp->next = NULL;
    }
}
///////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first,int no,int pos)
{
    int iCount = 0,i = 0;

    PNODE temp = NULL;
    PNODE newn = NULL;

    iCount = Count(*first);
    
    if((pos<1)||(pos>iCount+1))
    {
        printf("Invalid Position:\n");
        return;
    }

    if(pos == 1)
    {
        InserFirst(first,no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(first,no);
    }
    else
    {
        temp = *first;

        for(i = 1 ;i<pos - 2;i++)
        {
            temp = temp->next;
        }

        newn = (PNODE)malloc(NODE);
        newn->data=no;
        newn->next=NULL;

        newn->next = temp->next;
        temp->next = newn; 
    }
}
///////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first,int pos)
{
    int iCount = 0;
    int i = 0;
    PNODE temp = NULL;
    PNODE target = NULL;
   
    iCount = Count(*first);
    if((pos<1)||(pos>iCount))
    {
        printf("Invalid Position:\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(i = 1; i<pos - 2; i++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;  //temp->next = temp->next->next
        free(target);
    }
}

//////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iRet = 0;
    PNODE head = NULL;
    InserFirst(&head,11);
    InserFirst(&head,21);
    InserFirst(&head,51);
   
    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);
    InsertLast(&head,151);

    Display(head);

    iRet = Count(head);
    printf("Number of element are: %d\n",iRet );

    InsertAtPos(&head,105,5);

    Display(head);
    iRet = Count(head);
    printf("Number of element are: %d\n",iRet );

    DeleteAtPos(&head,5);
    Display(head);
    iRet = Count(head);
    printf("Number of element are: %d\n",iRet );
    return 0;
}