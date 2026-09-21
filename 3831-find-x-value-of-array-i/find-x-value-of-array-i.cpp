class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        // ans[r] = total number of subarrays
        // whose product % k is r
        vector<long long> ans(k, 0);

        // dp[r] = number of subarrays ending at
        // the previous position with remainder r
        vector<long long> dp(k, 0);

        for (int num : nums) {

            // Stores subarrays ending at the current number
            vector<long long> temp(k, 0);

            // Start a new subarray containing only num
            temp[num % k]++;

            // Extend every old subarray by num
            for (int r = 0; r < k; r++) {

                if (dp[r] == 0)
                    continue;

                // Use long long for multiplication
                int newRemainder = (1LL * r * num) % k;

                temp[newRemainder] += dp[r];
            }

            // Add current subarrays to final answer
            for (int r = 0; r < k; r++) {
                ans[r] += temp[r];
            }

            // Current subarrays become old subarrays
            dp = temp;
        }

        return ans;
    }
};