#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main()
{
    deque<string> backHistory;
    deque<string> forwardHistory;
    int option;
    string newWebPage;
    string currentWebsite = "Home";
    do
    {
        cout << "\nOPTIONS" << endl;
        cout << "1. Visit new website" << endl;
        cout << "2. Go back" << endl;
        cout << "3. Go forward" << endl;
        cout << "4. Show current history" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter a name of webpage to visit: ";
            cin >> newWebPage;
            backHistory.push_back(currentWebsite);
            currentWebsite = newWebPage;
            forwardHistory.clear();
            cout << "Current website: " << currentWebsite << endl;
            break;
        case 2:
            if (backHistory.empty())
            {
                cout << "No previous website available." << endl;
            }
            else
            {
                forwardHistory.push_back(currentWebsite);
                currentWebsite = backHistory.back();
                backHistory.pop_back();
                cout << "Current website: "<< currentWebsite << endl;
            }
            break;
        case 3:
            if (forwardHistory.empty())
            {
                cout << "No forward website available." << endl;
            }
            else
            {
                backHistory.push_back(currentWebsite);
                currentWebsite = forwardHistory.back();
                forwardHistory.pop_back();
                cout << "Current website: "<< currentWebsite << endl;
            }
            break;
        case 4:
            cout << "Back History: ";
            for (string site : backHistory)
            {
                cout << site << " ";
            }
            cout << "\nCurrent Website: "<< currentWebsite;

            cout << "\nForward History: ";
            for (string site : forwardHistory)
            {
                cout << site << " ";
            }
            cout << endl;
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (option != 5);
    return 0;
}
