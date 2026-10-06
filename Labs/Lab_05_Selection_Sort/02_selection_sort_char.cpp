#include<iostream>
using namespace std;
void selectionSort(char arr[],int size)
{
	bool isSwapped=false;
	int count=0;
	for(int i=0;i<size-1;i++)
	{
		int min=i;
		for(int j=i+1;j<size;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
				isSwapped=true;
			}
		}
		if(min!=i)
		{
			swap(arr[i],arr[min]);
			count++;
		}
    }
	for (int i=0;i<size;i++)	
    {
        cout<<arr[i]<<" ";
    }
	cout<<"\nNumber of swaps are "<<count<<endl;
}
int main()
{
    int n=6;
    char arr[n]={'B','A','F','G','H','I'};
	selectionSort(arr,n);
	
}
