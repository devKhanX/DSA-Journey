# Question #9 Palindrome Number

**Difficulty:** Easy
**LeetCode:** [Palindrome Number](https://leetcode.com/problems/palindrome-number/)

## Problem

Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise.

### Example 1
```
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
```

### Example 2
```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

### Example 3
```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

### Constraints
- `-2^31 <= x <= 2^31 - 1`

## Approach

1. Negative numbers can never be palindromes (the `-` sign breaks symmetry), and since the loop only runs `while (x > 0)`, negative inputs skip straight to the comparison with `rev` still `0` — correctly returning `false`.
2. Store the original number in `ogNum` before modifying `x`.
3. Reverse the digits of `x` the same way as in [Reverse Integer](../0007-Reverse-Integer): extract the last digit with `% 10`, build up `rev`, and strip the digit with `/= 10`.
4. Compare the fully reversed value `rev` with the original `ogNum`. If they match, the number is a palindrome.

Note: `rev` is declared as `long long` as a safeguard, though since the input is bounded to a 32-bit signed range and only positive values are reversed, overflow isn't actually a practical concern here (unlike in Reverse Integer, where explicit overflow checking against `INT_MAX`/`INT_MIN` is required).

## Solution

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0;
        int ogNum = x;
        while (x > 0)
        {
            int lastDigit = 0;
            lastDigit = x % 10;
            rev = (rev * 10) + lastDigit;
            x /= 10;
        }
        if (rev == ogNum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
```

## Complexity

- **Time complexity:** `O(log₁₀(x))` — proportional to the number of digits in `x`.
- **Space complexity:** `O(1)` — constant extra space.

## Edge Cases Handled

- Negative numbers (automatically `false`, since the loop never runs and `rev` stays `0` ≠ `ogNum`).
- Single-digit numbers (trivially palindromes, e.g., `x = 5 → rev = 5`).
- Numbers ending in zero, like `10` (correctly `false`, since reversing gives `1`, not `10`).
