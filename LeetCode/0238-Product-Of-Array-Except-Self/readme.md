# Product of Array Except Self

A C++ solution to [LeetCode 238 – Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) using **prefix and suffix products** in O(N) time and O(1) extra space, without division.

## Problem

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

- The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.
- You must write an algorithm that runs in O(N) time and **without using the division operation**.

### Examples

| Input | Output | Explanation |
|---|---|---|
| `nums = [1,2,3,4]` | `[24,12,8,6]` | For index 0: 2 × 3 × 4 = 24, and so on. |
| `nums = [-1,1,0,-3,3]` | `[0,0,9,0,0]` | The zero makes every product 0 except the one at the zero's index: (-1) × 1 × (-3) × 3 = 9. |

## Approach

For each index `i`, the answer is:

```
answer[i] = (product of all elements to the left of i) * (product of all elements to the right of i)
```

1. **Prefix pass (left to right):** Store in `ans[i]` the product of every element before index `i`. `ans[0]` is `1` because nothing is to its left.
2. **Suffix pass (right to left):** Keep a running `suffix` variable holding the product of every element after index `i`, and multiply it into `ans[i]`.

The result array is used to hold the prefix products, so no extra arrays are needed.

### Why not use division?

Dividing the total product by `nums[i]` fails when the array contains zeros (division by zero, and the total product becomes 0). The prefix and suffix method handles zeros naturally.

## Solution

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int suffix = 1;

        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }
        return ans;
    }
};
```

## Complexity

| | Complexity | Reason |
|---|---|---|
| Time | O(N) | Two passes over the array. |
| Space | O(1) extra | Only the `suffix` variable is used. The output array is not counted as extra space. |

A brute-force solution that multiplies everything for each index is O(N²).

## Walkthrough

For `nums = [1,2,3,4]`:

**Prefix pass** (`ans[i]` = product of everything to the left):

| i | ans[i] |
|---|---|
| 0 | 1 |
| 1 | 1 |
| 2 | 2 |
| 3 | 6 |

After this pass: `ans = [1, 1, 2, 6]`.

**Suffix pass** (right to left):

| i | suffix (product to the right) | ans[i] after |
|---|---|---|
| 2 | 4 | 2 × 4 = 8 |
| 1 | 4 × 3 = 12 | 1 × 12 = 12 |
| 0 | 12 × 2 = 24 | 1 × 24 = 24 |

Final answer: `[24, 12, 8, 6]`.

## Running Locally

The solution is written in LeetCode format. To run it on your machine, wrap it in a `main`:

```cpp
#include <iostream>
#include <vector>
using namespace std;

// paste the Solution class here

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution s;
    vector<int> result = s.productExceptSelf(nums);
    for (int x : result) cout << x << " ";   // 24 12 8 6
    cout << endl;
    return 0;
}
```

Compile and run:

```bash
g++ -std=c++17 main.cpp -o main
./main
```

## Constraints

- `2 <= nums.length <= 10^5`
- `-30 <= nums[i] <= 30`
- The product of any prefix or suffix of `nums` fits in a 32-bit integer.
