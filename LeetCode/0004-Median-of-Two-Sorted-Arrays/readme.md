# 4. Median of Two Sorted Arrays

**Difficulty:** Hard
**Link:** [LeetCode](https://leetcode.com/problems/median-of-two-sorted-arrays/)

## Problem Statement

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the median of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

### Examples

**Example 1**
```
Input:  nums1 = [1,3], nums2 = [2]
Output: 2.00000
```
Merged array = `[1,2,3]` and the median is `2`.

**Example 2**
```
Input:  nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
```
Merged array = `[1,2,3,4]` and the median is `(2 + 3) / 2 = 2.5`.

### Constraints

- `nums1.length == m`
- `nums2.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-10^6 <= nums1[i], nums2[i] <= 10^6`

## Approach: Merge Two Sorted Arrays

Both arrays are already sorted, so they can be merged into one sorted array (the same merge step used in merge sort). The median is then the middle element, or the average of the two middle elements.

### Steps

1. Create two pointers `i` and `j` (one per array) and an empty vector `nums3`.
2. While both pointers are in range, compare `nums1[i]` and `nums2[j]`, push the smaller one into `nums3`, and move that pointer forward.
3. Copy the remaining elements of `nums1`, if any.
4. Copy the remaining elements of `nums2`, if any.
5. Let `size = nums3.size()` and `mid = size / 2`.
   - **Odd size:** median = `nums3[mid]`
   - **Even size:** median = `(nums3[mid-1] + nums3[mid]) / 2.0`

### Dry Run

**`nums1 = [1,3]`, `nums2 = [2]`**

| i | j | Comparison | nums3 |
|---|---|------------|-------|
| 0 | 0 | 1 <= 2, take from `nums1` | `[1]` |
| 1 | 0 | 3 <= 2? no, take from `nums2` | `[1,2]` |
| 1 | 1 | `nums2` done, copy rest of `nums1` | `[1,2,3]` |

`size = 3`, `mid = 1`, odd, so median = `nums3[1] = 2`

**`nums1 = [1,2]`, `nums2 = [3,4]`**

| i | j | Comparison | nums3 |
|---|---|------------|-------|
| 0 | 0 | 1 <= 3, take from `nums1` | `[1]` |
| 1 | 0 | 2 <= 3, take from `nums1` | `[1,2]` |
| 2 | 0 | `nums1` done, copy rest of `nums2` | `[1,2,3,4]` |

`size = 4`, `mid = 2`, even, so median = `(nums3[1] + nums3[2]) / 2.0 = (2 + 3) / 2.0 = 2.5`

## Solution (C++)

```cpp
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
```

## Complexity

| | Complexity | Reason |
|---|---|---|
| Time | O(m + n) | Every element of both arrays is visited once while merging |
| Space | O(m + n) | The merged vector `nums3` stores all elements |

## Notes

- Works for edge cases such as one empty array (for example `nums1 = []`, `nums2 = [1]`), since the leftover loops copy the other array.
- Using `<=` when comparing keeps the merge stable for equal values.
- This approach is O(m + n). The problem statement asks for O(log (m+n)), which can be achieved with a binary search on the partition of the smaller array.
