# LeetCode 152 – Maximum Product Subarray

**Difficulty:** Medium  
**Topics:** Array, Prefix Product, Suffix Product  
**Approach:** Two-Directional Traversal  
**Time Complexity:** O(n)  
**Space Complexity:** O(1)

[**Problem Link – LeetCode 152**](https://leetcode.com/problems/maximum-product-subarray/)

## Problem Statement

Given an integer array `nums`, find a contiguous subarray that has the largest product and return that product.

A subarray must contain consecutive elements. A single element is also considered a subarray.

### Examples

**Example 1:**

```cpp
Input: nums = [2, 3, -2, 4]
Output: 6
Explanation: The subarray [2, 3] has the maximum product.
```

**Example 2:**

```cpp
Input: nums = [-2, 0, -1]
Output: 0
Explanation: The subarray [0] has the maximum product.
```

## Approach: Prefix and Suffix Product

The main challenge in this problem is handling negative numbers.

- Multiplying two negative numbers produces a positive product.
- An odd number of negative elements can make the overall product negative.
- Zero breaks a continuous product sequence.

To handle these cases, we calculate products in two directions:

1. **Prefix Product:** Traverse the array from left to right.
2. **Suffix Product:** Traverse the array from right to left.

At every iteration, we compare both products and update the maximum product.

### Algorithm

1. Initialize `prefix = 1` and `suffix = 1`.
2. Initialize `maxPro = INT_MIN`.
3. Traverse the array using a single loop.
4. If either prefix or suffix becomes zero, reset it to 1.
5. Update the prefix product using `nums[i]`.
6. Update the suffix product using `nums[n-1-i]`.
7. Compare both products with `maxPro` and update the maximum.
8. Return `maxPro`.

## C++ Solution

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1;
        int suffix = 1;
        int maxPro = INT_MIN;

        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n-1-i];

            maxPro = max(maxPro, max(suffix, prefix));
        }

        return maxPro;
    }
};
```

## Dry Run

**Input:**

```cpp
nums = {-1, -2, -3};
```

| i | nums[i] | nums[n-1-i] | Prefix | Suffix | maxPro |
|---|---:|---:|---:|---:|---:|
| 0 | -1 | -3 | -1 | -3 | -1 |
| 1 | -2 | -2 | 2 | 6 | 6 |
| 2 | -3 | -1 | -6 | -6 | 6 |

**Output:** `6`

The suffix traversal finds the maximum product from the subarray `[-2, -3]`.

## Why Both Prefix and Suffix?

Consider an array with an odd number of negative elements:

```cpp
nums = {-1, -2, -3};
```

The product of the entire array is negative:

```cpp
(-1) * (-2) * (-3) = -6
```

To obtain the maximum positive product, we need to exclude one negative element.

There are two possibilities:

- Exclude elements from the beginning up to the first negative.
- Exclude elements from the last negative to the end.

The prefix and suffix traversals help capture both possibilities.

## Handling Zero

Zero divides the array into independent product segments.

Whenever a running product becomes zero, we reset it to 1 to start calculating a new segment.

```cpp
if(prefix == 0) prefix = 1;
if(suffix == 0) suffix = 1;
```

The maximum is updated before the next iteration, so zero is also considered as a possible answer.

## Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(n) | Both prefix and suffix products are calculated in one traversal. |
| Space Complexity | O(1) | Only a constant number of variables are used. |

## Key Takeaways

- A negative number can change the maximum product into a minimum product and vice versa.
- Prefix and suffix products help handle negative-number combinations.
- Zero breaks the running product and requires a reset.
- A single traversal can calculate products in both directions.
- This approach achieves optimal O(n) time and O(1) auxiliary space.

## Related Concepts

- Maximum Subarray
- Prefix Sum and Prefix Product
- Suffix Product
- Dynamic Programming
- Kadane's Algorithm

---

**Repository:** [DSA-Journey – LeetCode](https://github.com/devKhanX/DSA-Journey/tree/main/LeetCode)

**Problem:** [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)
