class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int ans = 0;

        unordered_map<int, int> count;

        for (int right = 0; right < n; right++) {
            count[nums[right]]++;

            while (count[nums[right]] > k) {
                count[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};