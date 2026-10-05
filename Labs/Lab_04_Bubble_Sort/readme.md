# Lab_04_Bubble Sort

This lab contains three C++ programs that implement **Bubble Sort** in different ways.

Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order. After each pass, the largest (or smallest) remaining element "bubbles" to its final position. An optimization flag (`isSwapped`) stops the algorithm early if a pass makes no swaps.

## Folder Structure

```
Lab_04_Bubble Sort/
├── bubble_sort_vector.cpp
├── bubble_sort_pass_display.cpp
├── bubble_sort_char.cpp
└── README.md
```

## Files

| # | File Name | Description | Data Type | Order |
|---|-----------|-------------|-----------|-------|
| 1 | `bubble_sort_vector.cpp` | Basic bubble sort using `vector<int>` with early-exit optimization | `int` (vector) | Ascending |
| 2 | `bubble_sort_pass_display.cpp` | Bubble sort that prints the array after every pass and counts swaps | `int` (array) | Descending |
| 3 | `bubble_sort_char.cpp` | Bubble sort on a character array that counts swaps | `char` (array) | Descending |

## How to Compile and Run

```bash
g++ bubble_sort_vector.cpp -o bubble1
./bubble1
```

Repeat with the other file names. Use `g++ -std=c++17` if your compiler complains.

## Complexity

| Case | Time |
|------|------|
| Best (already sorted, with `isSwapped`) | O(n) |
| Average / Worst | O(n²) |
| Space | O(1) |

---

## Code Review

### 1. `bubble_sort_vector.cpp` — Correct

Output:
```
Sorted Array
1 2 3 4 5
```

Minor notes (not errors):
- `for (int i = 0; i < arr.size(); i++)` compares `int` with `size_t` and gives a warning. Use `size_t i` instead.
- No newline is printed at the end of the output.

### 2. `bubble_sort_pass_display.cpp` — Has bugs

| # | Problem | Why it matters |
|---|---------|----------------|
| 1 | **Missing braces `{ }` after the `if`** | Only `swap(...)` is inside the `if`. `swapCount++` and `isSwapped=true` run on *every comparison*. |
| 2 | `swapCount` is wrong | It counts comparisons (105 for n = 15), not swaps. The real number of swaps is 42. |
| 3 | `isSwapped` is always `true` | The early-exit optimization never works. |
| 4 | `return` on no swap | After fixing bug 1, the function would return before printing "Total number of swaps". Use `break` instead. |
| 5 | `arr[j] < arr[j+1]` | This sorts in **descending** order. Fine if intended; use `>` for ascending. |
| 6 | `int arr[n]` with a non-const `n` | Variable Length Array. It is not standard C++ (only a GCC extension). Use `const int n = 15;`. |
| 7 | No newline after "Total number of swaps" | Output ends on the same line. |

**Corrected version:**

```cpp
#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n)
{
    int swapCount = 0;
    int passCount = 0;

    for (int i = 0; i < n - 1; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])      // descending order
            {
                swap(arr[j], arr[j + 1]);
                swapCount++;
                isSwapped = true;
            }
        }
        if (!isSwapped)
            break;
        passCount++;
        cout << "Array after pass " << passCount << " - ";
        printArray(arr, n);
    }
    cout << "Total number of swaps are " << swapCount << endl;
}

int main()
{
    const int n = 15;
    int arr[n] = {15, 13, 11, 9, 7, 5, 3, 1, 2, 6, 4, 14, 12, 10, 8};
    bubbleSort(arr, n);
    return 0;
}
```

### 3. `bubble_sort_char.cpp` — Has bugs

| # | Problem | Why it matters |
|---|---------|----------------|
| 1 | **Missing braces `{ }` after the `if`** | Same bug as file 2. `swapCount++` and `isSwapped=true` run on every comparison. |
| 2 | `swapCount` is wrong | It prints 10 (all comparisons) instead of 8 (actual swaps). |
| 3 | `isSwapped` is set but never checked | There is no early exit. Add `if (!isSwapped) break;`. |
| 4 | Outer loop `i < n` | Should be `i < n - 1`. The last pass is unnecessary. |
| 5 | `char a[n]` with a non-const `n` | Variable Length Array, not standard C++. Use `const int n = 5;`. |
| 6 | Sorts in descending order | Use `>` for ascending. |

**Corrected version:**

```cpp
#include <iostream>
using namespace std;

void bubbleSort(char a[], int n)
{
    int swapCount = 0;
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])          // descending order
            {
                swap(a[j], a[j + 1]);
                swapCount++;
                isSwapped = true;
            }
        }
        if (!isSwapped)
            break;
    }
    cout << "Total swaps are " << swapCount;
}

int main()
{
    const int n = 5;
    char a[n] = {'A', 'C', 'E', 'B', 'F'};
    bubbleSort(a, n);
    cout << "\nSorted array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
```

Expected output:
```
Total swaps are 8
Sorted array
F E C B A
```

## Key Takeaway

Always use `{ }` around the body of an `if` that has more than one statement. Missing braces was the main bug in files 2 and 3.
