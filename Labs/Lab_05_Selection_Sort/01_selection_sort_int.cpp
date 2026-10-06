#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int> arr,int size)
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
    for(auto val: arr)
	{
		cout<<val<<" ";
	}
	cout<<"\nNumber of swaps are "<<count<<endl;
}
int main()
{
	vector<int> arr={27,21,30,25,8,3};
	selectionSort(arr,arr.size());
	
}
