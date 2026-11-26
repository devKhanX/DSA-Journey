# Container With Most Water

A C++ solution to [LeetCode 11 – Container With Most Water](https://leetcode.com/problems/container-with-most-water/) using the **two-pointer technique** in O(N) time and O(1) space.

## Problem

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn so that the two endpoints of the `i`-th line are `(i, 0)` and `(i, height[i])`.

Find two lines that, together with the x-axis, form a container that holds the most water. Return the maximum amount of water the container can store.

> You may not slant the container.

### Examples

| Input | Output | Explanation |
|---|---|---|
| `height = [1,8,6,2,5,4,8,3,7]` | `49` | Lines at index 1 (height 8) and index 8 (height 7) give width 7 × height 7 = 49. |
| `height = [1,1]` | `1` | Width 1 × height 1 = 1. |

## Approach

The water held between two lines is:

```
area = (right - left) * min(height[left], height[right])
```

1. Place one pointer at each end of the array (`l = 0`, `r = n - 1`). This gives the widest possible container.
2. Calculate the area and update the maximum.
3. Move the pointer that points to the **shorter** line one step inward.
4. Repeat until the pointers meet.

### Why moving the shorter line is correct

The height of the container is limited by the shorter line. If the taller line were moved inward instead, the width would shrink and the height could not grow (it is still capped by the shorter line), so the area could never improve. Moving the shorter line is the only move that might find a taller wall, so no better pair is ever skipped.

## Solution

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxWater = 0;

        while (l < r) {
            int w = r - l;
            int ht = min(height[l], height[r]);
            int currentWater = w * ht;
            maxWater = max(maxWater, currentWater);

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxWater;
    }
};
```

## Complexity

| | Complexity | Reason |
|---|---|---|
| Time | O(N) | Each pointer moves at most N times in total. |
| Space | O(1) | Only a few integer variables are used. |

A brute-force solution that checks every pair of lines is O(N²).

## Walkthrough

For `height = [1,8,6,2,5,4,8,3,7]`:

| l | r | Width | Min height | Area | Max so far | Move |
|---|---|---|---|---|---|---|
| 0 | 8 | 8 | 1 | 8 | 8 | l++ (1 < 7) |
| 1 | 8 | 7 | 7 | 49 | 49 | r-- (8 ≥ 7) |
| 1 | 7 | 6 | 3 | 18 | 49 | r-- |
| 1 | 6 | 5 | 8 | 40 | 49 | r-- |
| 1 | 5 | 4 | 4 | 16 | 49 | r-- |
| 1 | 4 | 3 | 5 | 15 | 49 | r-- |
| 1 | 3 | 2 | 2 | 4 | 49 | r-- |
| 1 | 2 | 1 | 6 | 6 | 49 | r-- |

The pointers meet and the answer is **49**.

## Running Locally

The solution is written in LeetCode format. To run it on your machine, wrap it in a `main`:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// paste the Solution class here

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << s.maxArea(height) << endl;  // 49
    return 0;
}
```

Compile and run:

```bash
g++ -std=c++17 main.cpp -o main
./main
```

## Constraints

- `n == height.length`
- `2 <= n <= 10^5`
- `0 <= height[i] <= 10^4`

The largest possible area is 10^5 × 10^4 = 10^9, which fits in a 32-bit `int`.
