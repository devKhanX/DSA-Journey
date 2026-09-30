#include<iostream>
using namespace std;
int countDigit(int n,int exDigit)
{
	if(n<10)
	{
		if(n==exDigit)
		return 0;
		else
		return 1;
	}
	int rem=n%10;
	if(rem==exDigit)
	return countDigit(n/10,exDigit);
	else
	return 1+countDigit(n/10,exDigit);
}
int main()
{
	int n=1002003;
	int exDigit=0;
	cout<<countDigit(n,exDigit);
}
