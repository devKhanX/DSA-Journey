class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currPro=1, maxPro=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            currPro*=nums[i];
            maxPro=max(currPro,maxPro);
            if(currPro<0)
            {
                currPro=0;
            }
        }
          return maxPro;
    }
};
