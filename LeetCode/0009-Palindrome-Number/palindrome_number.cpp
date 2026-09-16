#include <climits>
class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0;
        int ogNum = x;
        while (x > 0)
        {
            int lastDigit = 0;
            lastDigit = x % 10;
            rev = (rev * 10) + lastDigit;
            x /= 10;
        }
        if (rev == ogNum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
