class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];

        for ( int j = 0; j < (nums.size() -1); j ++){
             ans = ans ^ nums[ j  + 1 ] ;
        }
        
        return  ans ;
    }
};