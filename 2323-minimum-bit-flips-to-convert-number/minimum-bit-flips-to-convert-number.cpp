class Solution {
public:
    int minBitFlips(int start, int goal) {

        int diff = start ^ goal ;
        int count = 0 ;
        int temp = 1 ;

        for ( int i = 0 ; i < 32  ; i++){

            if ( diff & temp ){
                count ++ ;
            }

            temp = temp << 1 ;
        }

        return count ;
        
    }
};