// STL TASK 1
#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    // 1. Stores them in a vector
    vector<int> v;
    cout<<"Enter "<<n<<" student marks:\n";
    for (int i = 0; i < n; i++) 
	{
        int mark;
        cin >> mark;
        v.push_back(mark);
    }
    // 2. Prints all marks using normal indexing
    cout<<"\n---Printing marks using Normal Indexing---\n";
    for (int i=0; i<v.size(); i++) 
	{
        cout<<"Marks of student "<<i+1<<" are "<<v[i]<<endl;
    }
    // 2. Prints all marks using iterator
    cout<<"\n--- Printing marks using Iterator ---\n";
    for (auto it=v.begin(); it!=v.end();++it) 
	{
        cout << *it << endl;
    }
    // 2. Prints all marks using range-based loop
    cout << "\n---Printing marks using Range-Based Loop---\n";
    for (int num : v) 
	{
        cout<<"Marks: "<<num<<endl; 
    }
    // 3. Adds 3 more marks using push_back()
    cout<<"\nAdding 3 more marks (85, 92, 78)\n";
    v.push_back(85);
    v.push_back(92);
    v.push_back(78);
    // 4. Removes the last mark
    cout << "Removing the last mark "<<endl;
    v.pop_back();
    // 5. Prints size, capacity, first element, last element
    cout<<"\n---Vector Properties---\n";
    cout<<"Size of vector is "<<v.size()<<endl;
    cout<<"Capacity of vector is " <<v.capacity()<<endl;
    cout<<"First element: "<<v.front()<< endl;
    cout<<"Last element: "<<v.back()<< endl;
    // 6. Find the highest and lowest marks without using sort()
    if (!v.empty()) 
	{ 
        int highest = v[0];
        int lowest = v[0];
        for (int num : v) 
		{
            if (num > highest) 
			{
                highest = num;
            }
            if (num < lowest) 
			{
                lowest = num;
            }
        }
        cout<<"\n--- Min/Max Stats ---\n";
        cout<<"Highest mark: "<<highest<<endl;
        cout<<"Lowest mark: "<<lowest<<endl;
    }
    return 0;
}
