# 121. Best Time to Buy and Sell Stock

**Difficulty:** Easy
**Topics:** Array, Dynamic Programming
**Link:** [LeetCode 121](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

## Problem

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

### Example 1

```
Input:  prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

### Example 2

```
Input:  prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

### Constraints

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

## Approach: Single pass, track the lowest price so far

1. Keep `bestBuy`, the lowest price seen up to the current day. Start with `prices[0]`.
2. For each later day, if `prices[i]` is higher than `bestBuy`, selling today would give profit `prices[i] - bestBuy`. Update `maxProfit` if it is larger.
3. Update `bestBuy = min(bestBuy, prices[i])` so the next day sees the cheapest earlier price.

Because `bestBuy` only holds prices from earlier days, the "buy before sell" rule is always respected. If prices only fall, `maxProfit` stays `0`.

### Dry run

`prices = [7,1,5,3,6,4]`

| i | prices[i] | bestBuy (before) | profit if sold | maxProfit | bestBuy (after) |
|---|:---------:|:----------------:|:--------------:|:---------:|:---------------:|
| 0 | 7 | 7 | start | 0 | 7 |
| 1 | 1 | 7 | none | 0 | 1 |
| 2 | 5 | 1 | 4 | 4 | 1 |
| 3 | 3 | 1 | 2 | 4 | 1 |
| 4 | 6 | 1 | 5 | 5 | 1 |
| 5 | 4 | 1 | 3 | 5 | 1 |

Answer: **5**

## Solution (C++)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, bestBuy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxProfit;
    }
};
```

## Complexity

| | Complexity |
|---|---|
| Time | O(n), single pass |
| Space | O(1) |

## Notes

- Brute force tries every buy/sell pair, which is O(n^2).
- Edge cases: a single price returns `0`, and a strictly decreasing array returns `0`.
- Related: 122. Best Time to Buy and Sell Stock II, 53. Maximum Subarray (same running-minimum idea as Kadane's).
