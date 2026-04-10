class Solution {
public:
    double myPow(double x, int n) {
        long long  N = n ;
        double ans  = 1 ;
        
        if ( N < 0 ){
            N = -N;
            x = 1/x;
        };

        while ( N > 0 ){
            if ( N & 1 ){
                ans *= x ;
            }
            x *= x ;
            N >>= 1 ;
        }

        return ans ;
    }
};