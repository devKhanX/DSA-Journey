#include <climits>
class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        while (x != 0)
        {
            int lastDigit = 0;
            lastDigit = x % 10;
            rev = (rev * 10) + lastDigit;
            x /= 10;
        }
        if (rev > INT_MAX || rev < INT_MIN)
        {
            return 0;
        }
        else
        {
            return rev;
        }
    }
};
