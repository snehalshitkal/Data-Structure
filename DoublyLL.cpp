#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyLL
{
    private:
        PNODE first;
        int iCount;

    public:
        DoublyLL();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

    DoublyLL :: DoublyLL()
    {
        cout<<"Inside Constructor:\n";
        first = NULL;
        iCount = 0;
    }
   
    void DoublyLL :: InsertFirst(int no)
    {
        PNODE newn = NULL;
        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first->prev = newn;
            first = newn;
        }
        iCount++;
    }
    void DoublyLL :: InsertLast(int no)
    {
        PNODE temp = NULL;
        PNODE newn = NULL;
        newn= new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev= NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            temp = first;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
            newn->prev = temp;
        }
        iCount++;
    }
    
    void DoublyLL :: DeleteFirst()
    {
        PNODE temp = NULL;
        if(first == NULL)
        {
            return;
        }
        else if(first->next == NULL)
        {
            delete first;
            first = NULL;
        }
        else
        {
            temp = first;
            first = first->next;
            delete temp;
        }
        iCount--;
    }
    void DoublyLL :: DeleteLast()
    {
        PNODE temp = NULL;
       
       if(first == NULL)
        {
            return;
        }
       else if(first->next == NULL)
        {
           delete first;
            first = NULL;
        }
        else
        {
            temp = first;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
           temp->next->prev = NULL;
           delete temp;
            
        }
        iCount--;
    }
     void DoublyLL :: Display()
    {
        PNODE temp = NULL;
        temp = first;
        while(temp != NULL)
        {
            cout<<"<=| "<<temp->data<<" |=>";
            temp = temp->next;
        }
        cout<<" NULL=>"<<"\n";

    }
    int DoublyLL :: Count()
    {
        return iCount;
    }
    void DoublyLL :: InsertAtPos(int no,int pos)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;
        int icnt = 0;
        

        if(pos< 1|| pos >iCount+1)
        {
            cout<<"Invalid Position:";
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
            temp = first;
            newn = new NODE;
        
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;
            for(icnt = 1;icnt<pos - 1;icnt++)
            {
                temp =temp->next;
            }
            newn->next = temp->next;
            temp->next->prev = newn;
            temp->next = newn;
            newn->prev = temp;
        }
    }
    void DoublyLL :: DeleteAtPos(int pos)
    {
        PNODE temp = NULL;
        PNODE target = NULL;
        int icnt = 0;
        if(pos<1 || pos>iCount)
        {
            cout<<"Invalid Position:";
            return;
        }
        if(pos == 1)
        {
            DeleteFirst();
        }
        else if (pos == iCount)
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
            target->next->prev = temp;
            delete target;

        }
        
    }
int main()
{
    DoublyLL dobj;
    int iRet = 0,iValue = 0,iChoice = 0,iPos = 0;
    
    while(1)
    {
    cout<<"------------------------------------------"<<"\n";
    cout<<"---------DOUBLY LINKED LIST---------------"<<"\n";
    cout<<"------------------------------------------"<<"\n";
    cout<<"1: Insert First node in Singly CLL "<<"\n";
    cout<<"2: Insert Last node in SinglyCLL:"<<"\n";
    cout<<"3: Insert at Position  of Node "<<"\n";
    cout<<"4: Delete First node in Singly CLL "<<"\n";
    cout<<"5: Delete Last node in SinglyCLL:"<<"\n";
    cout<<"6: Delete at Position  of Node "<<"\n";
    cout<<"7: Display All Nodes"<<"\n";
    cout<<"8: Count All Node in Singly CLLL"<<"\n";
    cout<<"------------------------------------------"<<"\n";
    cin>>iChoice;
     if(iChoice == 1)
        {
            cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;
            dobj.InsertFirst(iValue);
        }
        else if(iChoice == 2)
        {
           cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;
            dobj.InsertLast(iValue);
        }
        else if(iChoice == 3)
        {
            cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;

            cout<<"Enter the position:"<<"\n";
            cin>>iPos;

            dobj.InsertAtPos(iValue,iPos);

        }

        else if(iChoice == 4)
        {
            cout<<"Deleting the first node in Linked List:"<<"\n";
            dobj.DeleteFirst();
        }
        
         else if(iChoice == 5)
        {
            cout<<"Deleting the Last node in Linked List:"<<"\n";
            dobj.DeleteLast();
        }

        else if(iChoice == 6)
        {
            cout<<"Enter the position that you want to delete node:"<<"\n";
            cin>>iPos;
            dobj.DeleteAtPos(iPos);
        }
        else if(iChoice == 7)
        {
            cout<<"Nodes of Linked List:"<<"\n";
            dobj.Display();
        }

        else if(iChoice == 8)
        {
            cout<<"Count All Nodes Nodes of Linked List:"<<"\n";
            iRet = dobj.Count();
            cout<<"Total numbers of node in Linked List:"<<iRet<<"\n";
        }
        else if(iChoice == 0 )
        {
            cout<<"Thank yoy for using Application:"<<"\n";
            break;
        }
        else
        {
            cout<<"Invalid Choice"<<"\n";
        }

    }
     

    return 0;
}