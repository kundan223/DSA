class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int badhta = 1;
        int ghatta = 1;
        int ans = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                badhta++;
                ghatta = 1;
            }
            else if (nums[i] < nums[i-1]) {
                ghatta++;
                badhta = 1;
            }
            else {
                badhta = 1;
                ghatta = 1;
            }

            ans = max(ans, max(badhta, ghatta));
        }

        return ans;
    }
};