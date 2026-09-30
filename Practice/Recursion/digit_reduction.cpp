#include<iostream>
using namespace std;
int reduce (int n)
{
	int rem=0;
	if(n>=0 && n<=9)
	{
		return n;
	}
	rem=n%10;
	n/=10;
	int result=reduce(n)+rem;
	if (result>9)
	{
		return reduce(result);
	}
	else
	return result;
	
}
int main()
{
	int n=9875;
	cout<<reduce(n);
}
