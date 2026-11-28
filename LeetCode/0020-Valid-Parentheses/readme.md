# Valid Parentheses

A C++ solution to [LeetCode 20 – Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) using a **stack** in O(N) time and O(N) space.

## Problem

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

A string is valid if:

1. Open brackets are closed by the same type of bracket.
2. Open brackets are closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

### Examples

| Input | Output | Explanation |
|---|---|---|
| `s = "()"` | `true` | The bracket is opened and closed. |
| `s = "()[]{}"` | `true` | Each pair is closed correctly. |
| `s = "(]"` | `false` | `(` is closed by the wrong type, `]`. |
| `s = "([)]"` | `false` | The brackets close in the wrong order. |
| `s = "{[]}"` | `true` | Properly nested. |

## Approach

The most recently opened bracket must be the first one closed (last in, first out), which is exactly how a stack behaves.

1. Go through the string from left to right.
2. If the character is an **opening** bracket, push it onto the stack.
3. If it is a **closing** bracket:
   - If the stack is empty, there is nothing to match, so return `false`.
   - If the top of the stack is the matching opening bracket, pop it.
   - Otherwise the types or the order are wrong, so return `false`.
4. After the loop, the string is valid only if the stack is **empty** (no unclosed brackets are left).

## Solution

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {
                if (st.empty())
                    return false;
                if ((st.top() == '(' && s[i] == ')') ||
                    (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '[' && s[i] == ']')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
```

## Complexity

| | Complexity | Reason |
|---|---|---|
| Time | O(N) | Each character is processed once, and each push or pop is O(1). |
| Space | O(N) | In the worst case (for example `"((((("`) every character is pushed onto the stack. |

## Walkthrough

For `s = "{[]}"`:

| Character | Action | Stack (bottom to top) |
|---|---|---|
| `{` | push | `{` |
| `[` | push | `{ [` |
| `]` | top is `[`, so pop | `{` |
| `}` | top is `{`, so pop | empty |

The stack is empty at the end, so the answer is `true`.

For `s = "([)]"`, the `)` meets `[` on top of the stack, which is not its match, so the answer is `false`.

## Edge Cases

- **Only closing brackets** (`")"`): the stack is empty when a close bracket arrives, so `false`.
- **Only opening brackets** (`"(("`): the stack is not empty at the end, so `false`.
- **Odd length strings** can never be valid, since brackets come in pairs.

## Running Locally

The solution is written in LeetCode format. To run it on your machine, wrap it in a `main`:

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// paste the Solution class here

int main() {
    Solution sol;
    cout << boolalpha;
    cout << sol.isValid("()[]{}") << endl;   // true
    cout << sol.isValid("([)]") << endl;     // false
    return 0;
}
```

Compile and run:

```bash
g++ -std=c++17 main.cpp -o main
./main
```

## Constraints

- `1 <= s.length <= 10^4`
- `s` consists of parentheses only: `'()[]{}'`.
