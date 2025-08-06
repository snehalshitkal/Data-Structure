/*
///////////////////////////////////////////////////////////////////////////////////////////
            Program : STACK PUSH POP DISPLAY ELEMNTS AND COUNTELEMNTS OPERATIONS
            Date    : 5/8/2025 
            ALGORITHM:
                PUSH OPERATION - LIFO
                POP OPERATION  - DELETE FIRST ELEMENTS
                
//////////////////////////////////////////////////////////////////////////////////////////////

*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node** PPNODE;

void Push(PPNODE first,int no)
{
    PNODE newn = NULL;

    newn =(PNODE) malloc (sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    newn->next = *first;
    *first = newn;
}

int Pop(PPNODE first)
{
    PNODE temp = NULL;
    int iValue = 0;
  
    if(*first == NULL)
    {
        printf("Stack is Empty:");
        return -1;
    }
        temp = *first;

        iValue = temp->data;
        *first = (*first)->next;
       
        free(temp);

      
        return iValue;
    
}

void Display(PNODE first)
{
    PNODE temp = NULL;
    temp = first;

    while(first != NULL )
    {
        printf("| %d |\n",first->data);
        first = first->next;
    } 
   printf("\n");

}

int Count(PNODE first)    
{
    int iCount = 0;
    PNODE temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        iCount++;
        temp = temp->next;
    }
    return iCount;

}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    Push(&head,11);
    Push(&head,21);
    Push(&head,31);
    Display(head);

    iRet = Count(head);
    printf("Total Number of Elements in Stack are: %d\n",iRet);

    iRet = Pop(&head);
    printf("Pop Element are:%d\n",iRet);

    

    return 0;
}