#include <iostream>
#include <list>
#include <string>
using namespace std;
int main() 
{
    list<string> train = {"A", "B", "C", "D", "E"};
    train.push_front("X");
    train.push_back("Y");
    list<string>::iterator it; 
    for(it=train.begin();it!=train.end();++it) 
	{
        if (*it=="C") 
		{
            break; 
        }
    }
    train.insert(it, "Z");
    train.remove("D");
    for (string coach : train) 
	{
        cout<<coach<<" ";
    }
    cout<<endl;
    return 0;
}
