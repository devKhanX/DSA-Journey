# Lab 05 – Selection Sort

Part of my [DSA Journey](https://github.com/devKhanX/DSA-Journey). This lab implements **Selection Sort** in C++ for three different data types and counts how many swaps each run performs.

## Files

| File | Data type | Input | Output | Swaps |
|------|-----------|-------|--------|-------|
| `01_selection_sort_int.cpp` | `vector<int>` | `27 21 30 25 8 3` | `3 8 21 25 27 30` | 4 |
| `02_selection_sort_char.cpp` | `char[]` | `B A F G H I` | `A B F G H I` | 1 |
| `03_selection_sort_string.cpp` | `string[]` | `Zakriya Owais Anwar Hamza Musawir Jibran` | `Anwar Hamza Jibran Musawir Owais Zakriya` | 4 |

## How Selection Sort Works

1. Start at index `i = 0`.
2. Scan the unsorted part (`i+1` to `size-1`) to find the smallest element.
3. If the smallest element is not already at position `i`, swap it into place and count the swap.
4. Move `i` forward by one and repeat until the array is sorted.

Each pass places exactly one element in its final position.

### Example trace (`01_selection_sort_int.cpp`)

| Pass | Array after pass | Swap? |
|------|------------------|-------|
| 1 | `3 21 30 25 8 27` | Yes |
| 2 | `3 8 30 25 21 27` | Yes |
| 3 | `3 8 21 25 30 27` | Yes |
| 4 | `3 8 21 25 30 27` | No (25 already in place) |
| 5 | `3 8 21 25 27 30` | Yes |

## Complexity

| Case | Time | Space |
|------|------|-------|
| Best | O(n²) | O(1) |
| Average | O(n²) | O(1) |
| Worst | O(n²) | O(1) |

- Number of comparisons is always n(n−1)/2.
- Number of swaps is at most n−1, which is fewer than Bubble Sort.
- Not stable by default.

## How to Compile and Run

```bash
g++ 01_selection_sort_int.cpp -o int_sort
./int_sort

g++ 02_selection_sort_char.cpp -o char_sort
./char_sort

g++ 03_selection_sort_string.cpp -o string_sort
./string_sort
```

## Sample Output

```
3 8 21 25 27 30 
Number of swaps are 4
```

## Notes

- Strings and chars are compared with `<`, so sorting is in alphabetical (ASCII) order. Uppercase letters come before lowercase.
- In `01_selection_sort_int.cpp` the vector is passed **by value**, so the original vector in `main` is not modified. Use `vector<int>& arr` to sort in place.
- The `isSwapped` variable is declared but not used; it can be removed.
- `char arr[n]` with a non-constant `n` is a compiler extension (VLA). Use `const int n = 6;` for standard C++.

## Concepts Practiced

- Selection sort algorithm
- Swap counting
- Sorting `int`, `char` and `string` data
- Working with arrays and `vector`
