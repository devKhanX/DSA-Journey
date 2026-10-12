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

Since both arrays are already sorted, merge them into a third array (as in merge sort), then read the median from the merged array.

### Steps

1. Use two pointers `i` and `j`, one for each array, and an empty vector `nums3`.
2. While both pointers are in range, push the smaller of `nums1[i]` and `nums2[j]` into `nums3` and move that pointer forward.
3. Push any remaining elements of `nums1`, then of `nums2`.
4. Let `size = nums3.size()` and `mid = size / 2`.
   - If `size` is **odd**, the median is `nums3[mid]`.
   - If `size` is **even**, the median is `(nums3[mid-1] + nums3[mid]) / 2.0`.

### Dry Run (`nums1 = [1,2]`, `nums2 = [3,4]`)

| i | j | Compare | nums3 |
|---|---|---------|-------|
| 0 | 0 | 1 <= 3 | `[1]` |
| 1 | 0 | 2 <= 3 | `[1,2]` |
| 2 | 0 | `nums1` done, copy rest of `nums2` | `[1,2,3,4]` |

`size = 4`, `mid = 2`, median = `(nums3[1] + nums3[2]) / 2.0 = (2 + 3) / 2.0 = 2.5`

## Complexity

| | Complexity |
|---|---|
| Time | O(m + n) |
| Space | O(m + n) |

## Notes

- This solution is accepted, but it does **not** meet the required `O(log(m+n))` time, because it visits every element.
- The median is stored in a `float`. It works for the given constraints, but `double` (the function's return type) is safer and more precise.
- **Optimal approach:** binary search on the partition of the smaller array, which runs in `O(log(min(m, n)))` time and `O(1)` space. The idea is to find a split of both arrays so that the left half has `(m + n + 1) / 2` elements and every element on the left is `<=` every element on the right. The median then comes from the largest value on the left and, for an even total, the smallest value on the right.

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size();
        int low = 0, high = m;
        while (low <= high)
        {
            int cut1 = (low + high) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];
            if (l1 <= r2 && l2 <= r1)
            {
                if ((m + n) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                return max(l1, l2);
            }
            else if (l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        return 0.0;
    }
};
```
