#include<iostream>
#include<utility>
#include<vector>
using namespace std;
int main()
{
    vector <pair<string,int>> inventory_push;
    inventory_push.push_back({"Laptop",120000});
    inventory_push.push_back({"Mouse", 2500});
    inventory_push.push_back({"Keyboard", 5000});
    // 2. Implementation using emplace_back
    vector <pair<string,int>> inventory_emplace;
    inventory_emplace.emplace_back("Laptop", 120000);
    inventory_emplace.emplace_back("Mouse", 2500);
    inventory_emplace.emplace_back("Keyboard", 5000);
    cout << "--- Product Inventory ---"<<endl;
    for ( auto product : inventory_emplace) 
    {
        cout<<product.first<<": "<<product.second<<endl;
    }
    return 0;
}
