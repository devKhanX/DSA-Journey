# 88. Merge Sorted Array

**Difficulty:** Easy
**Topics:** Array, Two Pointers, Sorting
**Link:** [LeetCode 88](https://leetcode.com/problems/merge-sorted-array/)

## Problem

You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

Merge `nums1` and `nums2` into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`.

### Example 1

```
Input:  nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6].
```

### Example 2

```
Input:  nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
```

### Example 3

```
Input:  nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: nums1 has no real elements (m = 0), so the 0 is only a placeholder.
```

### Constraints

- `nums1.length == m + n`
- `nums2.length == n`
- `0 <= m, n <= 200`
- `1 <= m + n <= 200`
- `-10^9 <= nums1[i], nums2[j] <= 10^9`

**Follow up:** Can you come up with an algorithm that runs in O(m + n) time?

## Approach 1: Two-pointer merge with a temp array (my solution)

This is the merge step of merge sort.

1. Create a temp array `nums3` of size `m + n`.
2. Use pointer `i` on `nums1`, `j` on `nums2`, and `k` on `nums3`.
3. While both arrays have elements left, copy the smaller one into `nums3` and advance its pointer.
4. Copy whatever remains from `nums1` or `nums2`.
5. Copy `nums3` back into `nums1`.

### Dry run

`nums1 = [1,2,3]` (m = 3), `nums2 = [2,5,6]` (n = 3)

| Step | i | j | Compare | nums3 |
|:----:|:-:|:-:|---------|-------|
| 1 | 0 | 0 | 1 < 2 | [1] |
| 2 | 1 | 0 | 2 < 2 is false, take nums2 | [1,2] |
| 3 | 1 | 1 | 2 < 5 | [1,2,2] |
| 4 | 2 | 1 | 3 < 5 | [1,2,2,3] |
| 5 | 3 | 1 | `nums1` finished, copy rest of `nums2` | [1,2,2,3,5,6] |

Copy back: `nums1 = [1,2,2,3,5,6]`

## Solution (C++)

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(m + n);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                nums3[k] = nums1[i];
                i++;
            } else {
                nums3[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < m) {
            nums3[k] = nums1[i];
            i++;
            k++;
        }
        while (j < n) {
            nums3[k] = nums2[j];
            j++;
            k++;
        }
        for (int l = 0; l < m + n; l++) {
            nums1[l] = nums3[l];
        }
    }
};
```

## Complexity

| | Complexity |
|---|---|
| Time | O(m + n) |
| Space | O(m + n) for the temp array |

## Approach 2: Merge from the back (O(1) space)

Merging from the front overwrites unread elements of `nums1`. The free space is at the **end** of `nums1`, so fill from the back instead.

1. Set `i = m - 1`, `j = n - 1`, `k = m + n - 1`.
2. While `j >= 0`, put the larger of `nums1[i]` and `nums2[j]` at `nums1[k]`, then move that pointer and `k` back.
3. If `i` runs out first, the rest of `nums2` is copied in. If `j` runs out first, the remaining `nums1` elements are already in place.

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};
```

| | Complexity |
|---|---|
| Time | O(m + n) |
| Space | O(1) |

## Notes

- Edge cases: `n = 0` (nothing to merge) and `m = 0` (copy all of `nums2`).
- Using `<=` or `<` in the comparison does not affect correctness, only which equal element is taken first.
- Related: 21. Merge Two Sorted Lists, 977. Squares of a Sorted Array, 350. Intersection of Two Arrays II.
