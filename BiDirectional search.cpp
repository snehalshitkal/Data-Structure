/////////////////////////////////////////////////////////////////////////////////////////

//          Program : BiDireectional Search
//          Author  : snehal rohit shitkal
//          Date    :  16/8/2025
//
////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////////////

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


///////////////////////////////////////////////////////////////////////////////////////////


        bool BiDirectionalSearch(int no)    // N/2
        {
            int iStrat = 0;
            int iEnd = 0;

            bool bFlag = false;

            for(iStrat = 0, iEnd = iSize-1 ; iStrat <= iEnd; iStrat++, iEnd--)
            {
                if(Arr[iStrat] == no || Arr[iEnd] == no)
                {
                    bFlag = true;
                    break;
                }
            }

            return bFlag;
        }
};

////////////////////////////////////////////////////////////////////////////////////////
// Entry point function
////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    int iLength = 0;

    cout<<"Enter the size of array : \n";
    cin>>iLength;

    ArrayX *aobj = new ArrayX(iLength);

    bool bRet = false;

    aobj->Accept();

    aobj->Display();

    delete aobj;
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////