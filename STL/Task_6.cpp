#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main()
{
    vector<pair<string, int>> students= 
	{
        {"Ali", 85},
        {"Ahmed", 72},
        {"Usman", 91},
        {"Hamza", 67}
    };
    string name;
    int marks;
    int option;
    do
    {
        cout<<"\nOptions\n";
        cout<<"1. Add student\n";
        cout<<"2. Print all students\n";
        cout<<"3. Find student with highest marks\n";
        cout<<"4. Find a student by name\n";
        cout<<"5. Update a student's marks\n";
        cout<<"6. Exit\n";
        cout<<"Choose an option: ";
        cin>>option;
        if (option == 1)
        {
            cout<<"Enter student name: ";
            cin>>name;
            cout<<"Enter student's marks: ";
            cin>>marks;
            students.push_back({name, marks});
        }
        else if (option == 2)
        {
            for (int i = 0;i<students.size(); i++)
            {
                cout<<"Student "<<i + 1<< ": "<<students[i].first
                <<" - "<<students[i].second<<endl;
            }
        }
        else if (option == 3)
        {
            int highestMarks=students[0].second;
            int index = 0;
            for (int i=1;i<students.size();i++)
            {
                if (students[i].second>highestMarks)
                {
                    highestMarks=students[i].second;
                    index = i;
                }
            }
            cout<<"Student with highest marks: "<<students[index].first
            <<" - "<<highestMarks<<endl;
        }
        else if (option == 4)
        {
            cout<<"Enter student name to search: ";
            cin>>name;
            bool found=false;
            for (int i = 0; i<students.size();i++)
            {
                if (students[i].first == name)
                {
                    cout<<"Student found: "<<students[i].first
					<< " - " << students[i].second << endl;

                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout<<"Student not found"<<endl;
            }
        }
        else if (option == 5)
        {
            cout<<"Enter student name: ";
            cin>>name;
            bool found=false;

            for (int i=0;i<students.size();i++)
            {
                if (students[i].first == name)
                {
                    cout<<"Enter new marks: ";
                    cin>>marks;
                    students[i].second=marks;
                    cout<<"Marks updated successfully."<<endl;
                    found=true;
                    break;
                }
            }
            if (!found)
            {
                cout<<"Student not found"<<endl;
            }
        }
        else if (option==6)
        {
            cout<<"Exiting..."<<endl;
        }
		else
        {
            cout<<"Invalid option."<<endl;
   		}
    } while (option!=6);
    return 0;
}
