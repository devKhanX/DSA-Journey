#include <iostream>
using namespace std;
int main() 
{
 	  const int size =8;
    int arr[size] = {4, 2, 7, 4, 9, 2, 2, 1};
    cout << "Array elements: ";
    for (int i=0;i<size;i++) 
	{
        cout<<*(arr + i)<<" ";
    }
    cout << "\nDuplicate values found: "<<endl;
    bool alreadyPrinted[8] = {false}; 
    for (int i = 0; i < size; i++) 
	{
        if (*(alreadyPrinted+i))
		{
            continue;
        }
        bool isDuplicate = false;
        for (int j=i+1; j<size; j++) 
		{
            if (*(arr + i) == *(arr + j)) 
			{
                isDuplicate = true;
                *(alreadyPrinted + j)=true; 
            }
        }
        if (isDuplicate) 
		{
            cout<< "-> "<<*(arr + i) << " is repeated"<<endl;
        }
    }
    return 0;
}
