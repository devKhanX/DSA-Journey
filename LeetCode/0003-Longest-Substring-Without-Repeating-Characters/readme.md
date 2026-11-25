# 3. Longest Substring Without Repeating Characters

**Difficulty:** Medium
**Topics:** Hash Table, String, Sliding Window
**Link:** [LeetCode 3](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

## Problem

Given a string `s`, find the length of the **longest substring** without duplicate characters.

A **substring** is a contiguous sequence of characters within a string.

### Example 1

```
Input:  s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

### Example 2

```
Input:  s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

### Example 3

```
Input:  s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

### Constraints

- `0 <= s.length <= 5 * 10^4`
- `s` consists of English letters, digits, symbols and spaces.

## Approach 1: Brute force

Check every substring and test whether it has all distinct characters.

| | |
|---|---|
| Time | O(n^2) with a running set per start index, O(n^3) if each substring is re-checked |
| Space | O(min(n, charset)) |

## Approach 2: Sliding window + set

Keep a window `[l, r]` with no duplicates. Move `r` right. If `s[r]` is already in the set, remove `s[l]` and move `l` right one step at a time until the duplicate is gone.

| | |
|---|---|
| Time | O(2n) = O(n), each index enters and leaves the window once |
| Space | O(min(n, charset)) |

## Approach 3: Sliding window + last-seen index (my solution)

Store the **last index** where each character appeared in an array `hash` of size 256 (all start at `-1`). When `s[r]` was seen before **inside the current window**, jump `l` straight to one position after that earlier occurrence. No inner loop is needed.

For each `r`:
1. If `hash[s[r]] >= l`, the earlier copy is inside the window, so set `l = hash[s[r]] + 1`.
2. Window length is `r - l + 1`. Update `maxLength`.
3. Record `hash[s[r]] = r`.

### Why the `hash[s[r]] >= l` check matters

An old occurrence may sit **before** `l`. It is already outside the window, so it is not a duplicate and `l` must not move backward.

`s = "abba"`:

| r | char | hash[char] before | Inside window? | l | length | maxLength |
|:-:|:----:|:-----------------:|:--------------:|:-:|:------:|:---------:|
| 0 | a | -1 | no | 0 | 1 | 1 |
| 1 | b | -1 | no | 0 | 2 | 2 |
| 2 | b | 1 | yes (1 >= 0) | 2 | 1 | 2 |
| 3 | a | 0 | **no** (0 < 2) | 2 | 2 | 2 |

At `r = 3`, `a` last appeared at index 0, but `l = 2`, so it is outside the window. Without the check, `l` would jump back to 1 and the window `"bba"` would give a wrong length of 3. Answer: **2**.

### Dry run

`s = "abcabcbb"`

| r | char | hash[char] before | l (after) | length | maxLength |
|:-:|:----:|:-----------------:|:---------:|:------:|:---------:|
| 0 | a | -1 | 0 | 1 | 1 |
| 1 | b | -1 | 0 | 2 | 2 |
| 2 | c | -1 | 0 | 3 | 3 |
| 3 | a | 0 (>= 0) | 1 | 3 | 3 |
| 4 | b | 1 (>= 1) | 2 | 3 | 3 |
| 5 | c | 2 (>= 2) | 3 | 3 | 3 |
| 6 | b | 4 (>= 3) | 5 | 2 | 3 |
| 7 | b | 6 (>= 5) | 7 | 1 | 3 |

Answer: **3**

## Solution (C++)

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> hash(256, -1);
        int l = 0, r = 0;
        int length = 0;
        int maxLength = 0;
        while (r < n) {
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }
            length = r - l + 1;
            maxLength = max(length, maxLength);
            hash[s[r]] = r;
            r++;
        }
        return maxLength;
    }
};
```

## Complexity

| | Complexity |
|---|---|
| Time | O(n), single pass |
| Space | O(1), the array has a fixed size of 256 |

## Notes

- The outer `hash[s[r]] != -1` check is optional. `-1` is always less than `l`, so `hash[s[r]] >= l` alone gives the same result.
- `s[r]` is used as an array index. This is safe here because the input is ASCII. For general input, cast with `(unsigned char)s[r]`.
- Edge cases: an empty string returns `0`, and a string of identical characters returns `1`.
- Related: 2461. Maximum Sum of Distinct Subarrays With Length K, 1695. Maximum Erasure Value, 159. Longest Substring with At Most Two Distinct Characters, 340. Longest Substring with At Most K Distinct Characters.
