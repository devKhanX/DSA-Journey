class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        vector <int> nums3;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<=nums2[j])
            {
                nums3.push_back(nums1[i]);
                i++;
            }
            else 
            {
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        while (i<nums1.size())
        {
            nums3.push_back(nums1[i]);
            i++;
        }
        while (j<nums2.size())
        {
            nums3.push_back(nums2[j]);
            j++;
        }
    float median;
    int size=nums3.size();
    int mid=size/2;
    if(size%2==0)
    {
        median=(nums3[mid-1]+nums3[mid])/2.0;
    }
    else
    {
        median=nums3[mid];
    }
    return median;
    }
    
};
