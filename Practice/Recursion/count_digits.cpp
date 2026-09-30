#include<iostream>
using namespace std;
int countDigits(int n)
{
	if(n<10)
	return 1;
	else
	return 1+countDigits(n/10);
}
int main()
{
    int n=987654;
    cout<<countDigits(n);
}
