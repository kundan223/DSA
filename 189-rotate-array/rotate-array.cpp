#include <vector>
#include <algorithm> // for reverse
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // normalize k

        // reverse the entire array
        reverse(nums.begin(), nums.end());
        // reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        // reverse the remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};
