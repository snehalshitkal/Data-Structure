#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
    typedef struct node NODE;
    typedef struct node * PNODE;

class SinglyLL
{
    private:
        PNODE first;
        int iCount;

    public:
        SinglyLL()
        {
            cout<<"Inside Constructor:\n";
            this->first = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if(first == NULL)               //Empty
            {
                first = newn;
            }
            else                            //multiple
            {
                newn->next = first;
                first = newn; 
            }
        iCount++;
    }

    void InsertLast(int no)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;

        newn = new NODE;

        newn->data = no;
        newn->next = NULL;

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

            newn->next = temp->next;
            temp->next = newn;
        }
        iCount++;  
    }
    void Display()
    {
        PNODE temp = NULL;
        temp = first;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<"|->";
            temp = temp->next;
        }
        cout<<"\n";
    }
    int Count()
    {
        return iCount;
    }
    
    void DeleteFirst()
    {
        PNODE temp = NULL;

        if(first == NULL)           //empty
        {
            return;
        }
        else if(first->next == NULL)        //only 1 node
        {
            delete(first);
            first = NULL;
        }
        else                //multiple node 
        {
            temp = first;
            first = first->next;
            delete temp;
        }
        iCount--;  
    }
    void DeleteLast()
    {
        PNODE temp = NULL;
        if(first == NULL)
        {
            return;
        }
        else if(first->next == NULL)
        {
            delete first;
        }
        else
        {
            temp = first;
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete(temp->next);
            temp->next = NULL;
        }
        iCount--;
        
    }
    
    
    void InsertAtPos(int no,int pos)
    {
      PNODE temp = NULL;
      PNODE newn = NULL;

      if(pos<1 || pos>iCount+1)
      {
        cout<<"Invalid Position:\n";
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
        PNODE temp = NULL;
    
        temp = first;
        int icnt = 0;
        for (icnt = 1; icnt<pos-2; icnt++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next = newn;
      }
    }

    void DeleteAtPos(int pos)
    {
        PNODE temp = NULL;
        PNODE target = NULL;
        int icnt = 0;
        if(pos < 1 || pos > iCount)
        {
            cout<<"Invalid Position:";
            
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
            for(icnt = 1; icnt<pos-2; icnt++)
            {
                temp = temp->next;
            }
            target = temp->next;
            temp->next = target->next;
            delete(target);
        }
        iCount--;
        
    }
};
int main()
{
    SinglyLL sobj;
    int iRet = 0,iValue = 0,iChoice = 0,iPos = 0;
    
    while(1)
    {
    cout<<"------------------------------------------"<<"\n";
    cout<<"---------SINGLY LINKED LIST---------------"<<"\n";
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
            sobj.InsertFirst(iValue);
        }
        else if(iChoice == 2)
        {
           cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;
            sobj.InsertLast(iValue);
        }
        else if(iChoice == 3)
        {
            cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;

            cout<<"Enter the position:"<<"\n";
            cin>>iPos;

            sobj.InsertAtPos(iValue,iPos);

        }

        else if(iChoice == 4)
        {
            cout<<"Deleting the first node in Linked List:"<<"\n";
            sobj.DeleteFirst();
        }
        
         else if(iChoice == 5)
        {
            cout<<"Deleting the Last node in Linked List:"<<"\n";
            sobj.DeleteLast();
        }

        else if(iChoice == 6)
        {
            cout<<"Enter the position that you want to delete node:"<<"\n";
            cin>>iPos;
            sobj.DeleteAtPos(iPos);
        }
        else if(iChoice == 7)
        {
            cout<<"Nodes of Linked List:"<<"\n";
            sobj.Display();
        }

        else if(iChoice == 8)
        {
            cout<<"Count All Nodes Nodes of Linked List:"<<"\n";
            iRet = sobj.Count();
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