#include<iostream>
using namespace std;
void bubbleSort(char a[],int n)
{
	int swapCount=0;
	for (int i=0;i<n-1;i++)
	{
		bool isSwapped=false;
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
				swapCount++;
				isSwapped=true;
			}
		}
		if(isSwapped==false)
		break;
	}
	cout<<"Total swaps are "<<swapCount;

}
int main()
{
	const int n=5;
	char a[n]={'A','C','E','B','F'};
	bubbleSort(a,n);
	cout<<"\nSorted array"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
