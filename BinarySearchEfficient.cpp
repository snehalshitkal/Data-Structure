/////////////////////////////////////////////////////////////////////////////////////////
//          Program : Binary search Efficient
//          Author  : snehal rohit shitkal
//          Date    :  16/8/2025
//
//////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;

        ArrayX(int no)
        {
            iSize = no;
            Arr = new int[iSize];
        }

        ~ArrayX()
        {
            delete []Arr;
        }

//////////////////////////////////////////////////////////////////////////////////////////

        void Accept()
        {
            cout<<"Enter "<<iSize<<" elements : \n";
            
            int i =0;

            for(i = 0; i < iSize;i++)
            {
                cout<<"Enter the element no : "<<i+1<<"\n";

                cin>>Arr[i];
            }
        }

    //////////////////////////////////////////////////////////////////////////////////////////

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

      //////////////////////////////////////////////////////////////////////////////////////////

        bool BinarySearchEfficient(int no)
        {
            int iStart = 0, iEnd = 0, iMid = 0;
            bool bFlag = false;


            iStart = 0;
            iEnd = iSize - 1;

            while(iStart <= iEnd)
            {
                iMid = iStart + ((iEnd - iStart) / 2);

                if((Arr[iMid] == no) || (Arr[iStart] == no) || (Arr[iEnd] == no))    
                {
                    bFlag = true;
                    break;
                }
                else if(no < Arr[iMid])                             // First half (Left window)
                {
                    iEnd = iMid - 1;
                }
                else if(no > Arr[iMid])                             // Second half (Right window)
                {
                    iStart = iMid + 1;
                }
            }   // End of while

            return bFlag;
        }
};//End of class

//////////////////////////////////////////////////////////////////////////////////////////
//Entry point  function
//////////////////////////////////////////////////////////////////////////////////////////

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

    cout<<"Enter the value that you want to search : \n";
    cin>>iValue;

    bRet = aobj->BinarySearchEfficient(iValue);

    if(bRet == true)
    {
        cout<<iValue<<" is present in the data\n";
    }
    else 
    {
        cout<<iValue<<" is not present in the data\n";
    }

    delete aobj;
    
    return 0;
}