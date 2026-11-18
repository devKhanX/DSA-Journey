# LeetCode 169 – Majority Element

**Difficulty:** Easy  
**Topics:** Array, Hash Table, Boyer-Moore Voting Algorithm  
**Approach:** Boyer-Moore Voting Algorithm (Two Passes)  
**Time Complexity:** O(n)  
**Space Complexity:** O(1)

[**Problem Link – LeetCode 169**](https://leetcode.com/problems/majority-element/)

## Problem Statement

Given an array `nums` of size `n`, return the majority element.

The majority element is the element that appears more than `n/2` times.

The problem guarantees that a majority element always exists.

### Examples

**Example 1:**

```cpp
Input: nums = [3, 2, 3]
Output: 3
```

**Example 2:**

```cpp
Input: nums = [2, 2, 1, 1, 1, 2, 2]
Output: 2
```

## Approach: Boyer-Moore Voting Algorithm

The Boyer-Moore Voting Algorithm finds the majority element using a candidate and a counter.

The main idea is cancellation:

- If the current element matches the candidate, increment the counter.
- If it is different, decrement the counter.
- If the counter becomes zero, select a new candidate.

Since the majority element appears more than all other elements combined, it remains the final candidate.

### Algorithm

**Phase 1: Find the Candidate**

1. Initialize `count = 0`.
2. Traverse the array.
3. If `count == 0`, select the current element as the candidate.
4. If the current element matches the candidate, increment `count`.
5. Otherwise, decrement `count`.

**Phase 2: Verify the Candidate**

1. Initialize `count1 = 0`.
2. Traverse the array again.
3. Count the occurrences of the candidate.
4. If its frequency is greater than `n/2`, return the candidate.

## C++ Solution

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int el;

        // Phase 1: Find potential majority element
        for(int i = 0; i < nums.size(); i++)
        {
            if(count == 0)
            {
                count = 1;
                el = nums[i];
            }
            else if(nums[i] == el)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        // Phase 2: Verify the candidate
        int count1 = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == el)
            {
                count1++;
            }
        }

        if(count1 > nums.size()/2)
        {
            return el;
        }

        return -1;
    }
};
```

## Dry Run

**Input:**

```cpp
nums = [2, 2, 1, 1, 1, 2, 2]
```

| i | nums[i] | Candidate (el) | Count |
|---|---:|---:|---:|
| 0 | 2 | 2 | 1 |
| 1 | 2 | 2 | 2 |
| 2 | 1 | 2 | 1 |
| 3 | 1 | 2 | 0 |
| 4 | 1 | 1 | 1 |
| 5 | 2 | 1 | 0 |
| 6 | 2 | 2 | 1 |

Final candidate: `2`

**Verification:**

- Frequency of 2 = 4
- Array size = 7
- Majority threshold = 7/2 = 3

Since 4 > 3, the answer is `2`.

## Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(n) | Two traversals of the array. |
| Space Complexity | O(1) | Only a constant number of variables are used. |

## Key Takeaways

- Boyer-Moore Voting Algorithm uses the cancellation technique.
- A majority element appears more than half the array size.
- The candidate is not necessarily verified unless we perform a second traversal.
- The algorithm achieves linear time and constant auxiliary space.
- The verification step is useful when a majority element is not guaranteed to exist.

## Related Concepts

- Array Traversal
- Frequency Counting
- Hash Map
- Boyer-Moore Voting Algorithm

---

**Problem:** [169. Majority Element](https://leetcode.com/problems/majority-element/)

**Repository:** [DSA-Journey – LeetCode](https://github.com/devKhanX/DSA-Journey/tree/main/LeetCode)
