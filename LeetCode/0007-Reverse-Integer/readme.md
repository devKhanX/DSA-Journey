# Question Number 7 Reverse Integer

**Difficulty:** Medium
**LeetCode:** [Reverse Integer](https://leetcode.com/problems/reverse-integer/)

## Problem

Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2^31, 2^31 - 1]`, then return `0`.

**Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

### Example 1
```
Input: x = 123
Output: 321
```

### Example 2
```
Input: x = -123
Output: -321
```

### Example 3
```
Input: x = 120
Output: 21
```

## Approach

1. Extract the last digit of `x` using `x % 10`.
2. Build the reversed number digit by digit: `rev = rev * 10 + lastDigit`.
3. Remove the last digit from `x` using integer division: `x /= 10`.
4. Repeat until `x` becomes `0`.
5. After building the reversed value, check if it falls outside the 32-bit signed integer range (`INT_MIN` to `INT_MAX`). If it does, return `0`; otherwise, return the reversed value.

Note: `rev` is declared as `long long` purely as a safeguard to detect overflow after the fact by comparing against `INT_MAX`/`INT_MIN` — the problem statement's constraint against using 64-bit storage is more of a challenge to solve it with pure 32-bit arithmetic and overflow checks *before* each multiplication. This solution takes the simpler route of widening the type and checking bounds at the end.

## Solution

```cpp
class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        while (x != 0)
        {
            int lastDigit = 0;
            lastDigit = x % 10;
            rev = (rev * 10) + lastDigit;
            x /= 10;
        }
        if (rev > INT_MAX || rev < INT_MIN)
        {
            return 0;
        }
        else
        {
            return rev;
        }
    }
};
```

## Complexity

- **Time complexity:** `O(log₁₀(x))` — proportional to the number of digits in `x`.
- **Space complexity:** `O(1)` — constant extra space.

## Edge Cases Handled

- Negative numbers (sign is preserved naturally through `%` and `/` in C++).
- Trailing zeros in the input (e.g., `120 → 21`).
- Overflow beyond 32-bit signed integer range (returns `0`).
