class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x; // base cases

        int start = 1, end = x, ans = 0;
        while (start <= end) {
            long long mid = start + (end - start) / 2;

            if (mid * mid == x) {
                return mid; // perfect square
            }
            else if (mid * mid < x) {
                ans = mid;      // store possible answer
                start = mid + 1; // move right
            }
            else {
                end = mid - 1; // move left
            }
        }
        return ans; // floor of sqrt(x)
    }
};
