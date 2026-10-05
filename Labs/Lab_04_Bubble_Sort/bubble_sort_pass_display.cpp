#include<iostream>
using namespace std;
void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";

	}
	cout<<endl;
}
void bubbleSort(int arr[],int n)
{
	int swapCount=0;
	int passCount=0;
	
	for(int i=0;i<n-1;i++)
	{
		bool isSwapped=false;
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				swap(arr[j+1],arr[j]);
				swapCount++;
				isSwapped=true;
			}
		}
		if(isSwapped==false)
		break;
		passCount++;
		cout<<"Array after pass "<<passCount<<"-";
		printArray(arr,n);
	}
	cout<<"Total number of swaps are "<<swapCount<<endl;
}
int main()
{
	const int n=15;
	int arr[n]={15,13,11,9,7,5,3,1,2,6,4,14,12,10,8};
	bubbleSort(arr,n);
}
