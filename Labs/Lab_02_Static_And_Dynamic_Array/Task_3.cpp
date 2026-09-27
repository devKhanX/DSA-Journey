#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    int size=5;
    int key;
    vector<int> foundIndex;
    bool isFound=false;
    int *arr=new int[size];
    for (int i = 0; i < size; i++) 
	{
        cout<<"Enter element "<<i+1<<": ";
        cin>>*(arr + i);
    }
    cout<<"Enter number to find: ";
    cin>>key;
    cout<<endl;
    for (int i = 0; i < size; i++) 
	{
        if (*(arr + i)==key) 
		{
            isFound = true;
            foundIndex.push_back(i); 
        }
    }
    if (isFound) 
	{
        for (int i = 0; i < foundIndex.size(); i++) 
		{
            cout<<"Key was found at index "<<foundIndex[i]<<endl;
        }
    } 
	else 
	{
        cout<<"Key not found"<<endl;
    }
    delete[] arr; 
    return 0;
}
