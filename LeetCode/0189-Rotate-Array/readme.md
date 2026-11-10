189. Rotate Array

Problem: Rotate an array to the right by k steps, in O(n) time and O(1) extra space.

Approach (reversal algorithm):

Reduce k with k = k % n, since rotating by n gives the same array.
Reverse the whole array.
Reverse the first k elements.
Reverse the remaining n - k elements.

Dry run for nums = [1,2,3,4,5,6,7], k = 3:

Start:               1 2 3 4 5 6 7
Reverse all:         7 6 5 4 3 2 1
Reverse first 3:     5 6 7 4 3 2 1
Reverse last 4:      5 6 7 1 2 3 4
cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

Complexity: O(n) time, O(1) extra space.

Notes:

k % n handles k >= n. Without it, nums.begin() + k can go past the end.
For a left rotation by k, reverse the first k elements, then the rest, then the whole array.
Solution File Template

Use this header in every .cpp file so the repo stays consistent (templates/solution-template.cpp):

cpp
/*
 * Problem   : <LeetCode number>. <Title>
 * Link      : <URL>
 * Technique : <Technique name>
 * Difficulty: <Easy | Medium | Hard>
 *
 * Approach  :
 *   1. ...
 *   2. ...
 *
 * Time      : O(...)
 * Space     : O(...)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // solution here
};

int main() {
    // quick local test
    return 0;
}
How to Run Locally
bash
g++ -std=c++17 -O2 03-rotation-by-reversal/189-rotate-array.cpp -o out
./out
