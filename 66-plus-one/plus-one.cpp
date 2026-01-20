class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int t = digits.size();
        for(int n = t- 1 ; n >= 0 ; n -- ){

            if (digits[n] != 9 ){
                digits[n] = digits[n] + 1  ;
                return digits ;
            }

            if (digits[n] == 9){
                digits[n] = 0 ;
            }
            
        }
        digits.insert(digits.begin(), 1);
        return digits;
        
    }
};