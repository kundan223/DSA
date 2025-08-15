class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int currentcount =0;

        for (int i =0; i< nums.size(); i++){
            if(nums[i] == 1){
                currentcount++;
                maxCount = max(maxCount , currentcount);
            }else{
                currentcount = 0;
            }
        }

        return maxCount;
    }
};