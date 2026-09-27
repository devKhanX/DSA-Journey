#include<iostream>
using namespace std;
int main()
{
	int size;
	cout<<"Enter number of products: ";
	cin>>size;
	float total=0;
	float *prices=new float[size];
	for (int i=0;i<size;i++)
	{
		cout<<"Enter product "<<i+1<<" price ";
		cin>>*(prices+i);
		total+=*(prices+i);
	}
	cout<<"Total is "<<total;
	delete [] prices;
	prices=nullptr;
	return 0;
}
