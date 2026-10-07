# 75. Sort Colors


## Problem Statement

You are given an array `nums` with `n` objects colored red, white, or blue. Sort them **in-place** so that objects of the same color are adjacent, in the order red, white, blue.

The integers `0`, `1`, and `2` represent red, white, and blue respectively.

You must solve this **without using the library's sort function**.

### Examples

**Example 1**
```
Input:  nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```
The array has two 0s, two 1s, and two 2s. Sorting in-place puts all 0s first, then all 1s, then all 2s.

**Example 2**
```
Input:  nums = [2,0,1]
Output: [0,1,2]
```

### Constraints

- `n == nums.length`
- `1 <= n <= 300`
- `nums[i]` is `0`, `1`, or `2`

## Approach: Bubble Sort

Repeatedly compare adjacent elements and swap them if the left one is greater than the right one. After each pass, the largest remaining value moves to its final position at the end. Since only the values 0, 1 and 2 exist, this puts all 0s first, then 1s, then 2s.

### Steps

1. Outer loop `i` runs `n - 1` passes.
2. Inner loop `j` compares `nums[j]` and `nums[j+1]` up to `n - i - 1` (the last `i` elements are already in place).
3. If `nums[j] > nums[j+1]`, swap them.

### Dry Run (`[2,0,1]`)

| Pass | Comparison | Array after |
|------|------------|-------------|
| 1 | 2 > 0, swap | `[0,2,1]` |
| 1 | 2 > 1, swap | `[0,1,2]` |
| 2 | 0 > 1? no | `[0,1,2]` |

## Complexity

| | Complexity |
|---|---|
| Time | O(n²) |
| Space | O(1), in-place |

Since `n <= 300`, O(n²) is fast enough to be accepted.

## Notes

- `i` and `j` are `int` while `nums.size()` is unsigned, which can give a compiler warning (it does not affect the result).
- Adding an `isSwapped` flag and breaking when a pass makes no swaps gives an early exit on already sorted input.
- **Faster alternative:** the Dutch National Flag algorithm (three pointers `low`, `mid`, `high`) sorts in a single pass, O(n) time and O(1) space. This is the optimal solution and the usual follow-up question for this problem.
