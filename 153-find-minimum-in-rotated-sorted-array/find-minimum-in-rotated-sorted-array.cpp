#include <algorithm>

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = nums[0];

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] <= nums[high]) {
                ans = std::min(ans, nums[mid]);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
