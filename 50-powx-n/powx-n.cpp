class Solution {
public:

    double helper(double x, long long n) {
        if (n == 0) return 1;

        if (n % 2 == 1) {
            return x * helper(x, n - 1);
        } 
        else {
            double half = helper(x, n / 2);
            return half * half;
        }
    }

    double myPow(double x, int n) {
        long long N = n;   // ✅ FIX

        if (N < 0) {
            x = 1 / x;
            N = -N;        // ✅ SAFE NOW
        }

        return helper(x, N);
    }
};