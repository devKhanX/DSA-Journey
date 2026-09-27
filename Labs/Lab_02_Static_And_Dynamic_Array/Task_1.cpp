#include<iostream>
using namespace std;
int main()
{
	int sales[10];
	int largestSales=sales[0];
	int day=-1;
	for (int i=0;i<10;i++)
	{
		cout<<"Enter day "<<i+1<<" ";
		cin>>sales[i];
		if(sales[i]>largestSales)
		{
			largestSales=sales[i];
			day=i+1;
		}
	}
	cout<<"Largest Sales was on day "<<day;
}
