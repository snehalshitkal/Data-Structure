/*
///////////////////////////////////////////////////////////////
        Date      : 5/8/2025
        Program   : Binary Search Tree
        Algorithm : Insert node
                    Inorder,Preorder,PostOrder
                    Search Node
                    Count Nodes
                    CountLeafNodes
                   

///////////////////////////////////////////////////////////////
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node * lchild;
    struct node * rchild;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node** PPNODE;
//////////////////////////////////////////////////////////////

void Insert(PPNODE first,int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE) malloc(sizeof(NODE));

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while(1)
        {
            if(no == temp->data)
            {
                printf("Dublicate Element: unable to insert element");
                free(newn);
                break;
            }
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;

            }
            else if(no < temp->data)
            {
                if(temp->lchild == NULL)
                {
                   temp->lchild = newn;
                   break; 
                }
                temp = temp->lchild;
            }
            
        }
    }
}

/////////////////////////////////////////////////////////////////////
 void Inorder(PNODE first)
    {
        if(first != NULL)
        {
            Inorder(first->lchild);

            printf("| %d |\t",first->data);
            
            Inorder(first->rchild);
        } 
    }

    void Preorder(PNODE first)
    {
        printf("\n");
        if(first != NULL)
        {

            printf("%d\t",first->data);

            Preorder(first->lchild);

            Preorder(first->rchild);
        }
       
    }

    /////////////////////////////////////////////////////////////////////////
    void Postorder(PNODE first)
    {
        printf("\n");
        if(first != NULL)
        {
            Postorder(first->lchild);

            Postorder(first->rchild);

            printf("%d",first->data);
        }
       
    }

    ///////////////////////////////////////////////////////////////////

    bool Search(PNODE first , int no)
    {
        bool bFlag = false;
        int TimeComplexity = 0;

        while(first != NULL)
        {
            if(no == first->data)
            {
                bFlag = true;
                break;
            }
            else if(no > first->data)
            {
                first = first->rchild;
            }
            else if(no < first->data)
            {
                first = first->lchild;
            }
            TimeComplexity++;
        }
        printf("Time Complexity are:%d\n",TimeComplexity);
        return bFlag;
    }

    //////////////////////////////////////////////////////////////////////
    int Count(PNODE first)
    {
        static int iCount = 0;

        if(first != NULL)
        {
            iCount++;
            Count(first->lchild);
            Count(first->rchild);
        }
        return iCount;
    }

    /////////////////////////////////////////////////////////////////

    int CountLeafNode(PNODE first)
    {
        static int iCount = 0;
        if(first != NULL)
        {
            if(first->lchild == NULL && first->rchild == NULL)
            {
                iCount++;
            }
            CountLeafNode(first->lchild);
            CountLeafNode(first->rchild);
        }
        return iCount;
    }

    /////////////////////////////////////////////////////////////////////
int main()
{
    PNODE head = NULL;

    bool bRet = false;
    int  iRet = 0;
    Insert(&head,11);
    Insert(&head,21);
    Insert(&head,9);
    Insert(&head,23);
    Insert(&head,25);
    Insert(&head,35);

    Inorder(head);
    
    bRet = Search(head,35);
    if(bRet == true)
    {
        printf("elements are Present:\n");
    }
    else
    {
        printf("elements are not presents\n");
    }

    iRet = Count(head);
    printf("Number of Elemnts are :%d\n",iRet);

    iRet = CountLeafNode(head);
    printf("Number of Leaf Node: %d\n",iRet);

    return 0;
}