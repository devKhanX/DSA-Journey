# Recursion — Practice Tasks

A collection of recursion practice problems covering base cases, digit manipulation, and array processing.

---

## 1. `digit_reduction.cpp` — Recursive Digit Reduction

### Problem

Write a recursive function `int reduce(int n)` that repeatedly reduces a number to a single digit by summing its digits, and re-summing the result if it's still more than one digit.

**Rules:**
1. **Base case:** if `n` is a single-digit number (`0 <= n <= 9`), return `n`.
2. **Otherwise:**
   - Remove the last digit of `n` using integer division.
   - Recursively calculate the result for the remaining number.
   - Add the last digit of the original number to the recursive result.
   - If the resulting sum is greater than 9, recursively apply the same process to that sum.

### Example

```
reduce(9875)

9 + 8 + 7 + 5 = 29   (more than one digit, reduce again)
2 + 9 = 11            (still more than one digit, reduce again)
1 + 1 = 2

reduce(9875) = 2
```

### Code

```cpp
#include<iostream>
using namespace std;
int reduce (int n)
{
	int rem=0;
	if(n>=0 && n<=9)
	{
		return n;
	}
	rem=n%10;
	n/=10;
	int result=reduce(n)+rem;
	if (result>9)
	{
		return reduce(result);
	}
	else
	return result;
	
}
int main()
{
	int n=9875;
	cout<<reduce(n);
}
```

### Complexity
- **Time:** `O(log₁₀(n))` per reduction pass; since the digit sum shrinks quickly each pass, the total work across all passes stays small.
- **Space:** `O(log₁₀(n))` for the recursion call stack per pass.

---

## 2. `count_digits.cpp` — Count Total Digits

### Problem

Write a recursive function that takes an integer as input and returns the total number of digits present in the integer.

**Example:**
```
Input: 987654
Expected Output: 6
```

### Code

```cpp
#include<iostream>
using namespace std;
int countDigits(int n)
{
	if(n<10)
	return 1;
	else
	return 1+countDigits(n/10);
}
int main()
{
    int n=987654;
    cout<<countDigits(n);
}
```

### Approach
- **Base case:** if `n < 10`, it's a single digit — return `1`.
- **Recursive case:** strip the last digit (`n / 10`) and add `1` for the digit just removed.

### Complexity
- **Time:** `O(log₁₀(n))` — one recursive call per digit.
- **Space:** `O(log₁₀(n))` — recursion call stack depth equals the number of digits.

---

## 3. `count_digits_excluding.cpp` — Count Digits Excluding a Given Digit

### Problem

Write a recursive function that takes an integer and a specific digit as input. The function should return the number of digits in the integer, excluding all occurrences of the specified digit.

**Example:**
```
Input: 1002003
Digit to Exclude: 0
```

### Code

```cpp
#include<iostream>
using namespace std;
int countDigit(int n,int exDigit)
{
	if(n<10)
	{
		if(n==exDigit)
		return 0;
		else
		return 1;
	}
	int rem=n%10;
	if(rem==exDigit)
	return countDigit(n/10,exDigit);
	else
	return 1+countDigit(n/10,exDigit);
}
int main()
{
	int n=1002003;
	int exDigit=0;
	cout<<countDigit(n,exDigit);
}
```

### Approach
- **Base case:** if `n < 10` (single digit left), return `0` if it matches `exDigit`, otherwise `1`.
- **Recursive case:** check the last digit (`n % 10`). If it matches `exDigit`, skip counting it and recurse on the rest. Otherwise, count it (`+1`) and recurse on the rest.

### Complexity
- **Time:** `O(log₁₀(n))` — one recursive call per digit.
- **Space:** `O(log₁₀(n))` — recursion call stack depth.

---

## 4. `array_analyze.cpp` — Recursive Array Analysis

### Problem

Given `A = {2, 4, 6, 3, 5, 8}`, write a recursive function:
```cpp
int analyze(int A[], int n)
```
that processes the array according to these rules:
- If `n == 0`, return `0`.
- Recursively process the first `n-1` elements.
- If the current element `A[n-1]` is even, add it to the result.
- If the current element is odd, subtract it from the result.
- However, if the current element is `5`, instead of adding/subtracting it normally, recursively call `analyze(A, n-2)` and add that result (skipping the element before it entirely).

### Code

```cpp
#include<iostream>
using namespace std;
int analyze(int A[],int n)
{
	if(n==0)
	{	
	return 0;
	}
	if(A[n-1]==5)
	{
		return analyze(A,n-2);
	}
	int result=analyze(A,n-1);
	if (A[n-1]%2==0)
	{
		return result+A[n-1];
	}
	else
	{
		return result-A[n-1];
	}
}
int main()
{
	int n=6;
	int A[n]={2,4,6,3,5,8};
	cout<<analyze(A,n);
}
```

### Approach
- **Base case:** if `n == 0` (no elements left), return `0`.
- **Special case:** if the last element is `5`, skip it *and* the element before it entirely, jumping straight to `analyze(A, n-2)`.
- **Recursive case:** otherwise, recurse on the first `n-1` elements, then add or subtract the current element based on whether it's even or odd.

### Complexity
- **Time:** `O(n)` — each call processes one element (or two, when skipping past a `5`), so the total work is linear in the array size.
- **Space:** `O(n)` — recursion call stack depth proportional to array size.

---

## Summary

| File | Concept | Time | Space |
|---|---|---|---|
| `digit_reduction.cpp` | Digit sum, repeated reduction | O(log₁₀ n) per pass | O(log₁₀ n) |
| `count_digits.cpp` | Digit counting | O(log₁₀ n) | O(log₁₀ n) |
| `count_digits_excluding.cpp` | Conditional digit counting | O(log₁₀ n) | O(log₁₀ n) |
| `array_analyze.cpp` | Recursive array traversal with conditional skip | O(n) | O(n) |
