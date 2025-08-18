/////////////////////////////////////////////////////////////////////////////
//          Program : Bubble Sort of Efficient
//          Author  : snehal rohit shitkal
//          Date    :  16/8/2025
//
/////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

class ArrayX        
{
    public:
        int *Arr;
        int iSize;
        bool Sorted;

        ArrayX(int no)
        {
            iSize = no;
            Arr = new int[iSize];
            Sorted = true;
        }

        ~ArrayX()
        {
            delete []Arr;
        }

///////////////////////////////////////////////////////////////////////////////////

        void Accept()
        {
            cout<<"Enter "<<iSize<<" elements : \n";
            
            int i =0;                   // 11       

            for(i = 0; i < iSize;i++)
            {
                cout<<"Enter the element no : "<<i+1<<"\n";
                cin>>Arr[i];

                if((i > 0) && (Sorted == true))     // IMP
                {
                    if(Arr[i] < Arr[i-1])
                    {
                        Sorted = false;
                    }
                }
            }
        }

///////////////////////////////////////////////////////////////////////////////////

        void Display()
        {
            cout<<"Elements of the array are : \n";
            
            int i = 0;

            for(i = 0; i < iSize; i++)
            {
                cout<<Arr[i]<<"\t";
            }
            cout<<"\n";
        }
       
///////////////////////////////////////////////////////////////////////////////////

        void BubbleSortEfficient()
        {
            int i = 0, j = 0, temp = 0;
            bool bFlag = true;

            if(Sorted == true)
            {
                return;
            }
            
            for(i = 0; (i < iSize && bFlag == true) ; i++)        
            {
                bFlag = false;

                for(j = 0; j < iSize - 1 - i; j++)      
                {
                    if(Arr[j] > Arr[j + 1])
                    {
                        temp = Arr[j];
                        Arr[j] = Arr[j + 1];
                        Arr[j + 1] = temp;

                        bFlag = true;
                    }
                }

                cout<<"Data after Pass : "<<i+1<<"\n";

                Display();
            }
        }
}; //End of Class 

///////////////////////////////////////////////////////////////////////////////////
//      Entry Point Function
///////////////////////////////////////////////////////////////////////////////////


int main()
{
    int iLength = 0;
    int iValue = 0;

    bool bRet = false;

    cout<<"Enter the size of array : \n";
    cin>>iLength;

    ArrayX *aobj = new ArrayX(iLength);

    aobj->Accept();

    aobj->Display();

    aobj->BubbleSortEfficient();

    cout<<"Data after sorting : \n";

    aobj->Display();
   
    delete aobj;
    
    return 0;
}