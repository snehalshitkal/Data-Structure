/*
/////////////////////////////////////////////////////////////////////////////////////////////
            Program :  Doubly Linked List
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
    struct node * next;
    struct node * prev;                     
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


////////////////////////////////////////////////////////////////////////////////////////////
void Display (PNODE first)
{
    printf("NULL <=>");
    while(first!=NULL)
    {
        printf("| %d | <=>",first->data);
        first = first->next;
    }
    printf("NULL <=>");
}
////////////////////////////////////////////////////////////////////////////////////////////


int Count (PNODE first)
{
    int count = 0;
    while(first!=NULL)
    {
        count++;
        first = first->next;
    }
    return count;
}

////////////////////////////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next=NULL;
    newn->prev=NULL;        //$

    if(*first==NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;      //$
        *first = newn;
    }
}
    
////////////////////////////////////////////////////////////////////////////////////////////
void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next=NULL;
    newn->prev=NULL;        //$

    if(*first==NULL)
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
        newn->prev=temp;
        temp->next = newn;          //$
       
    }

}
////////////////////////////////////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE first)
{
    
    if(*first==NULL)
    {
        return;
    }
    else if((*first)->next==NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
       
        *first = (*first)->next;
        free((*first)->prev);
        (*first)->prev = NULL;      //$  without temp
    }

}

////////////////////////////////////////////////////////////////////////////////////////////
void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;
     if(*first==NULL)
    {
        return;
    }
    else if((*first)->next==NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        while(temp->next!=NULL)       //change 
        {
            temp=temp->next;

        }
        temp->prev->next=NULL;
        free(temp);
        
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE first, int no,int pos)
{
    int iCount = 0,icnt = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count(*first);

    if((pos<1)||(pos>iCount+1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(first,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *first;
        for(icnt = 1;icnt<pos-1;icnt++)
        {
            temp= temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev=temp;
    }

}
////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first,int pos)
{
    int iCount = 0, icnt= 0;
    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(*first);

    if((pos<1)||(pos>iCount))
    {
        printf("Invalid Position\n");
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
        for(icnt = 1;icnt<pos - 1;icnt++)
        {
            temp = temp->next;
        }
        target = temp->next;

        temp->next = target->next;
        target->next->prev=temp;
        free(target);
    }

}


////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    PNODE head = NULL;
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    printf("--------------------------------------------------------\n");
    printf("--------------Doubly Linear LinkedList------------------\n");
    printf("-----------------------------------------------------\n\n");
    while(1)                                //continue iterate
    {
        printf("-------------------------------------------------\n");
        printf("-------------please select the option------------\n");
        printf("--------------------------------------------------\n");
        printf("1: Insert new node at first position:\n");
        printf("2: Insert new node at last position:\n");
        printf("3: Insert new node at given position:\n");

        printf("4: Delete the node at first position:\n");
        printf("5: Delete the node at last position:\n");
        printf("6: Delete new node at given position:\n");
        printf("7: Display All element of Linked List:\n");
        printf("8: Count number of node:\n");
        printf("0: Terminate the application:\n");

        printf("-----------------------------------------------------\n");

    scanf("%d",&iChoice);
    if(iChoice == 1)
    {
        printf("Enter the data that you want insert:\n");
        scanf("%d",&iValue);
        InsertFirst(&head,iValue);
    }
    else if(iChoice == 2)
    {
        printf("Enter the data that you want insert:\n");
        scanf("%d",&iValue);
        InsertLast(&head,iValue);
    }
     
    else if(iChoice == 3)
    {
        printf("Enter the data that you want insert:\n");
        scanf("%d",&iValue);

        printf("Enter the position which you want to insert now");
        scanf("%d",&iPos);

        InsertAtPos(&head,iValue,iPos);
    }
    else if(iChoice == 4)
    {
        printf("Deleteing the first element from linked list:\n");

        DeleteFirst(&head);

    }
     else if(iChoice == 5)
    {
        printf("Deleteing the last element from linked list:\n");

        DeleteLast(&head);

    }
     else if(iChoice == 6)
    {
        printf("Deleteing the  element at position from linked list:\n");
        printf("Enter the position which you want to Delete the node\n");
        scanf("%d",&iPos);
        DeleteAtPos(&head,iPos);
    }

        else if(iChoice == 7)
    {
        printf("Elements of Linked list:\n");
       
        Display(head);

    }
    else if(iChoice == 8)
    {
        iRet = Count(head);
        printf("Number of element in the Linked list:\n");
    }
     else if(iChoice == 0)
    {
        
        printf("Thank you for using application:\n");
        break;
    }
    else
    {
        printf("Invalid choice");
    }
    printf("------------------------------------------------------\n");
    }
    return 0;

}