#include<iostream>
using namespace std;
int analyze(int A[],int n)
{
	if(n==0)
	{	
	return 0;
	}
	if(A[n-1]==5)
	{
		return analyze(A,n-2);
	}
	int result=analyze(A,n-1);
	if (A[n-1]%2==0)
	{
		return result+A[n-1];
	}
	else
	{
		return result-A[n-1];
	}
}
int main()
{
	int n=6;
	int A[n]={2,4,6,3,5,8};
	cout<<analyze(A,n);
}
