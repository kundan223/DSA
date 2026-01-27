class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for (int j = 0 ; j <= n-1 ; j ++ ){
            if ( nums[j] == target){
                return j;
            }

            
        }
        return -1;
        
    }
};