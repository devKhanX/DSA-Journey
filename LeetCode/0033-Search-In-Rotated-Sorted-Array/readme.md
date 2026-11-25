# 33. Search in Rotated Sorted Array

**Difficulty:** Medium
**Topics:** Array, Binary Search
**Link:** [LeetCode 33](https://leetcode.com/problems/search-in-rotated-sorted-array/)

## Problem

There is an integer array `nums` sorted in ascending order (with **distinct** values).

Prior to being passed to your function, `nums` is possibly **rotated** at an unknown pivot index `k` (`1 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (0-indexed). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` after the possible rotation and an integer `target`, return the index of `target` if it is in `nums`, or `-1` if it is not in `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

### Example 1

```
Input:  nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

### Example 2

```
Input:  nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

### Example 3

```
Input:  nums = [1], target = 0
Output: -1
```

### Constraints

- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i] <= 10^4`
- All values of `nums` are **unique**.
- `nums` is an ascending array that is possibly rotated.
- `-10^4 <= target <= 10^4`

## Approach 1: Linear search

Scan every element. Simple, but O(n), which does not meet the `O(log n)` requirement.

## Approach 2: Find the pivot, then binary search

1. Binary search for the pivot (the index of the smallest element).
2. Run a normal binary search on whichever sorted part can contain `target`.

Two binary searches, so still O(log n), but more code.

## Approach 3: One-pass modified binary search (my solution)

**Key idea:** after splitting at `mid`, **at least one half is always sorted**. Find the sorted half, check whether `target` lies inside its range, and keep that half or discard it.

At each step:
1. If `nums[mid] == target`, return `mid`.
2. If `nums[st] <= nums[mid]`, the **left half** `[st, mid]` is sorted.
   - If `nums[st] <= target < nums[mid]`, `target` is in the left half, so `end = mid - 1`.
   - Otherwise search the right half, so `st = mid + 1`.
3. Else the **right half** `[mid, end]` is sorted.
   - If `nums[mid] < target <= nums[end]`, `target` is in the right half, so `st = mid + 1`.
   - Otherwise search the left half, so `end = mid - 1`.

The `<=` in `nums[st] <= nums[mid]` matters when `st == mid` (a window of one or two elements). That single element counts as a sorted left half.

### Dry run

`nums = [4,5,6,7,0,1,2]`, `target = 0`

| Step | st | end | mid | nums[mid] | Sorted half | Decision | New range |
|:----:|:--:|:---:|:---:|:---------:|-------------|----------|-----------|
| 1 | 0 | 6 | 3 | 7 | Left (4 <= 7) | 4 <= 0 is false, so go right | st = 4 |
| 2 | 4 | 6 | 5 | 1 | Left (0 <= 1) | 0 <= 0 < 1 is true, so go left | end = 4 |
| 3 | 4 | 4 | 4 | 0 | | `nums[mid] == target` | return **4** |

### Dry run (target not present)

`nums = [4,5,6,7,0,1,2]`, `target = 3`

| Step | st | end | mid | nums[mid] | Sorted half | Decision | New range |
|:----:|:--:|:---:|:---:|:---------:|-------------|----------|-----------|
| 1 | 0 | 6 | 3 | 7 | Left | 4 <= 3 is false, go right | st = 4 |
| 2 | 4 | 6 | 5 | 1 | Left (0 <= 1) | 0 <= 3 < 1 is false, go right | st = 6 |
| 3 | 6 | 6 | 6 | 2 | Left | 2 <= 3 < 2 is false, go right | st = 7 |

`st > end`, so return **-1**.

## Solution (C++)

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[st] <= nums[mid]) {
                if (nums[st] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
```

## Complexity

| | Complexity |
|---|---|
| Time | O(log n), the range halves each step |
| Space | O(1) |

## Notes

- `mid = st + (end - st) / 2` avoids integer overflow compared with `(st + end) / 2`.
- Uniqueness of values is what makes the "which half is sorted" test reliable. With duplicates (problem 81), `nums[st] == nums[mid]` is ambiguous and the worst case becomes O(n).
- Edge cases: a single element, and an array that was not rotated at all (the left half is always sorted, so it behaves like normal binary search).
- Related: 153. Find Minimum in Rotated Sorted Array, 81. Search in Rotated Sorted Array II, 34. Find First and Last Position of Element in Sorted Array, 704. Binary Search.
