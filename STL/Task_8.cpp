#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() 
{
    stack<string> textHistory;
    string currentText = "";
    int choice;
   string input;
    while (true) 
    {
        cout << "\n--- Text Editor Menu ---" <<endl;
        cout << "1. Type something" <<endl;
        cout << "2. Undo" <<endl;
        cout << "3. Show current text" <<endl;
        cout << "4. Exit" <<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        if (choice == 1) 
        {
            cout << "Type something to append: ";
            getline(cin, input);
            textHistory.push(currentText);
            if (currentText.empty()) 
            {
                currentText = input;
            } else 
            {
                currentText += " " + input;
            }
            cout << "Added!" << std::endl;

        } 
        else if (choice == 2) 
        {
            if (!textHistory.empty()) 
            {
                currentText=textHistory.top(); 
                textHistory.pop();             
                cout<<"Undo successful!"<<endl;
            } 
            else 
            {
                cout<<"Nothing to undo!"<<endl;
            }

        } 
        else if (choice == 3) 
        {
            cout<<"\nCurrent Text: [" <<currentText<< "]"<<endl;

        } 
        else if (choice == 4) 
        {
            cout<<"Exiting editor."<<endl;
            break;

        } 
        else 
        {
            cout<<"Invalid choice! Please try again."<<endl;
        }
    }
    return 0;
}
