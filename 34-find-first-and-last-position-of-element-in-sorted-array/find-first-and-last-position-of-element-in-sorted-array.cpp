#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2, -1);  // initialize with [-1, -1]
        if (n == 0) return ans;

        // ---------- Find first (leftmost) position ----------
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        // check if target exists
        if (low >= n || nums[low] != target)
            return ans;

        ans[0] = low;

        // ---------- Find last (rightmost) position ----------
        high = n - 1;  // reset high
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        ans[1] = high;

        return ans;
    }
};
