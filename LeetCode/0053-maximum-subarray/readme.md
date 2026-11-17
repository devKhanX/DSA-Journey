# 53. Maximum Subarray

**Difficulty:** Medium

**Link:** [LeetCode 53](https://leetcode.com/problems/maximum-subarray/)

## Problem

Given an integer array `nums`, find the subarray with the largest sum, and return its sum.

A **subarray** is a contiguous, non-empty part of an array.

### Example 1

```
Input:  nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
```

### Example 2

```
Input:  nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
```

### Example 3

```
Input:  nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```

### Constraints

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

**Follow up:** If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

## Approach: Kadane's Algorithm

1. Keep a running sum `currSum` of the subarray ending at the current index.
2. After adding each element, update `maxSum = max(maxSum, currSum)`.
3. If `currSum` drops below 0, reset it to 0. A negative prefix can only reduce the sum of any subarray that extends it, so it is better to start fresh from the next element.

`maxSum` starts at `INT_MIN` and is updated **before** the reset. This makes the solution work when every element is negative: the answer is then the largest single element.

### Dry run

`nums = [-2,1,-3,4,-1,2,1,-5,4]`

| i | nums[i] | currSum (after add) | maxSum | currSum (after reset) |
|---|:-------:|:-------------------:|:------:|:---------------------:|
| 0 | -2 | -2 | -2 | 0 |
| 1 | 1 | 1 | 1 | 1 |
| 2 | -3 | -2 | 1 | 0 |
| 3 | 4 | 4 | 4 | 4 |
| 4 | -1 | 3 | 4 | 3 |
| 5 | 2 | 5 | 5 | 5 |
| 6 | 1 | 6 | 6 | 6 |
| 7 | -5 | 1 | 6 | 1 |
| 8 | 4 | 5 | 6 | 5 |

Answer: **6**

## Solution (C++)

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            maxSum = max(currSum, maxSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};
```

## Complexity

| | Complexity |
|---|---|
| Time | O(n), single pass |
| Space | O(1) |

## Notes

- Brute force checks all `n(n+1)/2` subarrays, which is O(n^2) with a running sum.
- Edge case: all negative numbers, e.g. `[-3,-1,-2]` returns `-1`.
- Related: 152. Maximum Product Subarray, 918. Maximum Sum Circular Subarray.
