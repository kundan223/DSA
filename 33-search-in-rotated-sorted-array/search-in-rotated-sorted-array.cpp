class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // if the mid element is equal to the target
            if (nums[mid] == target) {
                return mid;
            }

            // if the right side is sorted
            if (nums[mid] <= nums[high]) {
                // if target lies in the right half
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            // if the left side is sorted
            else {
                // if target lies in the left half
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        return -1;  // target not found
    }
};
