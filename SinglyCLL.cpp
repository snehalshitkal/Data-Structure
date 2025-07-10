#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyCLL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;
    public:
        SinglyCLL();
        void Display();
        int Count();

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
       
};
 SinglyCLL :: SinglyCLL()
{
    cout<<"Inside Constructor:"<<"\n";
    first = NULL;
    last = NULL;
    iCount = 0;
}
void SinglyCLL :: InsertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        last->next= first;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }
    iCount++;
}

void SinglyCLL :: InsertLast(int no)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last =newn;
        last->next = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
        newn->next = first;
    }
    iCount++;
}
void SinglyCLL :: Display()
{
    PNODE temp = NULL;
    temp = first;
    
    if(first == NULL && last == NULL)
    {
        cout<<"Node not Inserted:";
        return;
    }
    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }while(temp != last->next);
    cout<<"\n";
    
}
int SinglyCLL:: Count()
{
    return iCount;
}

void SinglyCLL::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }
    iCount--;
}
void SinglyCLL ::DeleteLast()
{
    PNODE temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
       temp = first;

       while(temp->next != last)
       {
            temp = temp->next;
       }

       delete last;
       last = temp;
       last->next = first;
    }
    iCount--;
}
void SinglyCLL :: InsertAtPos(int no,int pos)
{
    int icnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position:"<<"\n";
        return;
    }
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        temp = first;
        for(icnt = 1;icnt < pos - 1; icnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    iCount++;

}
void SinglyCLL :: DeleteAtPos(int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    int icnt = 0;
    if(pos<1 || pos >iCount)
    {
        cout<<"Invalid position:"<<"\n";
        return;
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
        for(icnt = 1; icnt<pos - 1;icnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
    }
    iCount--;
}
int main()
{
    SinglyCLL sobj;
    int iRet = 0; 
    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Nodes are:"<<iRet<<"\n";

    sobj.DeleteAtPos(3);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Nodes are:"<<iRet<<"\n";
    return 0;
}