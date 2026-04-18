class Solution {
public:
    int mirrorDistance(int n) {
        int copy = n ;
        int rev = 0 ;
        while( n > 0 ){
            int j = n%10 ;
            rev = rev*10 + j;
            n/=10;
            
        }
        return abs( rev - copy );
    }
};