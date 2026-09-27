#include<iostream>
using namespace std;
int main()
{
	int size=5;
	int *arr=new int [size];
	for(int i=0;i<size;i++)
	{
		cout<<"Enter value "<<i+1<<" ";
		cin>>*(arr+i);
	}
	int *low=arr;
	int *high=arr+(size-1);
	while(low<high)
	{
		swap(*low,*high);
		low++;
		high--;
	}
	cout<<"Reversed array: ";
    for (int i=0;i<size;i++) 
	{
        cout<<*(arr + i)<<" ";
    }
    delete []arr;
    arr=nullptr;
}
