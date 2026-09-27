#include <iostream>
using namespace std;
int main()
{
    int sales[10];
    for (int i=0;i<10; i++)
    {
        cout<<"Enter day "<<i+1<<" sale: ";
        cin>>sales[i];
    }
    int largestSales=sales[0];
    int day=1;
    for (int i=1;i<10;i++)
    {
        if (sales[i]>largestSales)
        {
            largestSales=sales[i];
            day=i+1;
        }
    }
    cout<<"Largest sale was on day "<<day<<endl;
    cout<<"Sale = "<<largestSales<<endl;
    return 0;
}
