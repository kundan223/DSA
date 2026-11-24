
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = min(n, 2);

        for (int i = 0; i < n; i++) {
            for (int j = i + 2; j < n; j++) {

                bool valid = true;

                // Check every pair in the subarray
                for (int a = i; a <= j; a++) {
                    for (int b = a + 1; b <= j; b++) {
                        if (gcd(nums[a], nums[b]) != 1) {
                            valid = false;
                            break;
                        }
                    }

                    if (!valid) break;
                }

                if (!valid) break;

                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
