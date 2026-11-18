# LeetCode 152 – Maximum Product Subarray

**Difficulty:** Medium  
**Topic:** Arrays, 
**Platform:** [LeetCode](https://leetcode.com/problems/maximum-product-subarray/)

## Problem Statement

Given an integer array `nums`, find a contiguous subarray that has the largest product and return that product.

A subarray must contain consecutive elements, and a single element is also considered a subarray.

### Examples

**Example 1**

```cpp
Input: nums = [2, 3, -2, 4]
Output: 6
Explanation: [2, 3] has the maximum product (2 × 3 = 6).
```

**Example 2**

```cpp
Input: nums = [-2, 0, -1]
Output: 0
Explanation: [0] has the maximum product.
```

## Approach: Dynamic Programming (Maximum and Minimum Product)

Unlike the Maximum Subarray Sum problem, negative numbers make this problem interesting.

A negative number can turn the smallest (most negative) product into the largest positive product when multiplied by another negative number.

Therefore, we maintain two values:

- `maxProduct`: Maximum product ending at the current index.
- `minProduct`: Minimum product ending at the current index.

### Algorithm

1. Initialize `maxProduct`, `minProduct`, and `result` with the first element.
2. Traverse the array starting from the second element.
3. If the current element is negative, swap `maxProduct` and `minProduct`.
4. Update both values:
   - `maxProduct = max(nums[i], maxProduct * nums[i])`
   - `minProduct = min(nums[i], minProduct * nums[i])`
5. Update the global maximum result.
6. Return `result`.

## C++ Solution

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxProduct = nums[0];
        int minProduct = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] < 0) {
                swap(maxProduct, minProduct);
            }

            maxProduct = max(nums[i], maxProduct * nums[i]);
            minProduct = min(nums[i], minProduct * nums[i]);

            result = max(result, maxProduct);
        }

        return result;
    }
};
```

## Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time | O(n) | Each array element is visited once. |
| Space | O(1) | Only three variables are maintained. |

## Key Takeaways

- Negative numbers can change the maximum product into the minimum product and vice versa.
- Track both maximum and minimum products at every index.
- A zero resets the running product naturally through the `max` and `min` updates.
- Always maintain a global maximum because the best subarray may end before the last element.

## Related Concepts

- Maximum Subarray
- Kadane's Algorithm


---

**Repository:** [DSA-Journey – LeetCode](https://github.com/devKhanX/DSA-Journey/tree/main/LeetCode)

**Problem Link:** [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)
