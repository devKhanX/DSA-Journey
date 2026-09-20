#include<iostream>
#include<utility>
#include<vector>
using namespace std;
int main()
{
    vector<pair<int,int>> points={{2,3},{5,1},{7,8},{1,4}};
    // 1. Print all points
    for(auto p:points)
    {
	cout<<"("<<p.first<<", "<<p.second<<")"<< endl;    
	}
	// 2. Find the point with the largest X coordinate
	int largestX=points[0].first;
	int largestIndex=0;
	for(int i=0; i<points.size(); i++)
    {
	if(points[i].first>largestX)
	{
	  largestX=points[i].first; 
	  largestIndex=i;
	}
	// 3. Swap two points using swap()
	cout<<"The point with largest X is ("<<points[largestIndex].first<<", " 
	<<points[largestIndex].second << ")"<<endl;
	"("<<points[0].first << ", " << points[0].second << ")"
    <<"with Point 2 "<<"("<<points[1].first <<", "<<points[1].second<<")..."<<endl;
    swap(points[0], points[1]);
    cout << "After swap, Point 1 is now: ("<<points[0].first << ", "<<points[0].second << ")"<<endl;
    cout << "After swap, Point 2 is now: ("<<points[1].first << ", "<<points[1].second << ")"<<endl;
    return 0;
}
