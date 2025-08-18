/////////////////////////////////////////////////////////////////////////////
//          Program : Selection Sort
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
/////////////////////////////////////////////////////////////////////////////////
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
        //End of Accept fun

//////////////////////////////////////////////////////////////////////////////////////
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
        //End of Display

/////////////////////////////////////////////////////////////////////////////////
        void SelectionSort()
        {
            int i = 0, j = 0, min_index = 0, temp = 0;

            for(i = 0 ; i < iSize-1; i++)
            {
                min_index = i;

                for(j = i + 1; j < iSize; j++)
                {
                    if(Arr[j] < Arr[min_index])
                    {
                        min_index = j;
                    }
                }

                temp = Arr[i];
                Arr[i] = Arr[min_index];
                Arr[min_index] = temp;
            }
        }

///////////////////////////////////////////////////////////////////////////////////
};//End of class


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

    aobj->SelectionSort();

    cout<<"Data after sorting : \n";

    aobj->Display();
   
    delete aobj;
    
    return 0;
}//End of main

//////////////////////////////////////////////////////////////////////////////////////