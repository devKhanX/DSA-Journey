# 206. Reverse Linked List

**Difficulty:** Easy
**Topics:** Linked List, Recursion
**Link:** [LeetCode 206](https://leetcode.com/problems/reverse-linked-list/)

## Problem

Given the `head` of a singly linked list, reverse the list, and return the reversed list.

### Example 1

```
Input:  head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

### Example 2

```
Input:  head = [1,2]
Output: [2,1]
```

### Example 3

```
Input:  head = []
Output: []
```

### Constraints

- The number of nodes in the list is in the range `[0, 5000]`.
- `-5000 <= Node.val <= 5000`

**Follow up:** A linked list can be reversed either iteratively or recursively. Could you implement both?

## Approach 1: Iterative, three pointers (my solution)

Walk through the list once and flip each node's `next` pointer to point at the previous node.

- `p`: the current node (next one to process)
- `q`: the node being reversed, which becomes the new head at the end
- `r`: the node that comes before `q` in the reversed list

For each step:
1. `r = q`: remember the previous node.
2. `q = p`: move `q` to the current node.
3. `p = p->next`: advance `p` **before** changing links, so the rest of the list is not lost.
4. `q->next = r`: reverse the link.

When `p` becomes `nullptr`, `q` points at the last node, which is the new head.

### Dry run

`head = 1 -> 2 -> 3 -> null`

| Step | r | q | p (after advance) | Link made |
|:----:|:-:|:-:|:-----------------:|-----------|
| start | null | null | 1 | |
| 1 | null | 1 | 2 | 1 -> null |
| 2 | 1 | 2 | 3 | 2 -> 1 |
| 3 | 2 | 3 | null | 3 -> 2 |

`p` is null, so return `q = 3`. Result: `3 -> 2 -> 1 -> null`

## Solution (C++)

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* q = nullptr;
        ListNode* r = nullptr;

        while (p != nullptr) {
            r = q;
            q = p;
            p = p->next;
            q->next = r; // Reverse the link
        }

        return q; // New head of the reversed list
    }
};
```

## Complexity

| | Complexity |
|---|---|
| Time | O(n), one pass |
| Space | O(1) |

## Approach 2: Recursive

Reverse the rest of the list first, then attach the current node at the end of it.

1. Base case: if `head` is null or has no next node, return `head`.
2. Recursively reverse the list starting at `head->next`. It returns the new head.
3. Make the next node point back to the current one with `head->next->next = head`.
4. Set `head->next = nullptr` so the old head becomes the tail.

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
```

| | Complexity |
|---|---|
| Time | O(n) |
| Space | O(n) for the recursion stack |

## Notes

- Edge cases: an empty list returns `nullptr`, and a single node returns itself. Your loop handles both without special checks.
- Always save `p->next` before overwriting `q->next`, or the rest of the list is lost.
- Related: 92. Reverse Linked List II, 25. Reverse Nodes in k-Group, 234. Palindrome Linked List.
