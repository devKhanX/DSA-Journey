class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int maxWater=0;
        while(l<r)
        {
            int w=r-l;
            int ht=min(height[l],height[r]);
            int currentWater=w*ht;
            maxWater=max(maxWater,currentWater);
            if(height[l]<height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return maxWater;
    }
};
