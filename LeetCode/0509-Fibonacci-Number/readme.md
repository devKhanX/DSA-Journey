# 509. Fibonacci Number

**Difficulty:** Easy
**LeetCode:** [Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)

## Problem

The Fibonacci numbers, commonly denoted `F(n)`, form a sequence called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is:

```
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```

Given `n`, calculate `F(n)`.

### Example 1
```
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
```

### Example 2
```
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
```

### Example 3
```
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
```

### Constraints
- `0 <= n <= 30`

## Approach

This is a direct recursive translation of the Fibonacci definition:

1. **Base case:** if `n <= 1`, return `n` directly (covers `F(0) = 0` and `F(1) = 1`).
2. **Recursive case:** otherwise, return `fib(n - 2) + fib(n - 1)`.

Because `n` is capped at `30` by the constraints, plain recursion works fine here without hitting performance issues — the tree only reaches a depth/breadth that's small enough to complete quickly.

## Solution

```cpp
class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        else
            return fib(n - 2) + fib(n - 1);
    }
};
```

## Complexity

- **Time complexity:** `O(2^n)` — naive recursion recomputes overlapping subproblems (e.g., `fib(n-2)` is recalculated many times across different branches). Acceptable here only because `n <= 30`.
- **Space complexity:** `O(n)` — due to the recursion call stack depth.

## Note on Optimization

For larger `n`, this approach would need to be optimized, since exponential time blows up quickly. Two common improvements:
- **Memoization** (top-down DP): cache already-computed `fib(k)` values to avoid recomputation → `O(n)` time, `O(n)` space.
- **Iterative bottom-up:** keep track of just the last two values → `O(n)` time, `O(1)` space.

Given the constraint `n <= 30`, this simple recursive solution is sufficient and passes without modification.

---

## Alternate Solution: Memoized Recursion (Top-Down DP)

This version fixes the exponential blowup of the naive approach by caching results in a global array `f[]`, so each `fib(k)` is computed only once instead of being recomputed across overlapping recursive branches.

```cpp
#include <iostream>
using namespace std;

int f[11];

int fib(int n)
{
    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n - 2] == -1)
            f[n - 2] = fib(n - 2);
        if (f[n - 1] == -1)
            f[n - 1] = fib(n - 1);
        return f[n - 2] + f[n - 1];
    }
}

int main()
{
    for (int i = 0; i <= 10; i++)
    {
        f[i] = -1;
    }
    int n = 10;
    cout << fib(10);
}
```

### How it works

1. `f[]` is initialized with `-1` to mark every value as "not yet computed."
2. Before recursing into `fib(n-2)` or `fib(n-1)`, the function first checks whether that value is already cached in `f[]`.
3. If it's still `-1`, it computes it recursively and stores the result; if it's already computed, it's reused directly — no redundant recalculation.
4. This turns the call tree from exponential branching into a linear chain of unique subproblem calls.

### Complexity

- **Time complexity:** `O(n)` — each `fib(k)` is computed exactly once.
- **Space complexity:** `O(n)` — for the memoization array `f[]` and the recursion call stack.

### Note

This version is written as a **standalone C++ program** (with `main()` and a fixed-size global array `f[11]`) rather than in LeetCode's `Solution` class format, since `f[]`'s size is hardcoded to fit `n <= 10` for demonstration. To submit this approach to LeetCode itself, `f[]` would need to be sized to at least `31` (for `n` up to `30`) and moved inside the `Solution` class (or passed via a helper), since LeetCode doesn't allow relying on a `main()` function or unscoped globals across test cases.
