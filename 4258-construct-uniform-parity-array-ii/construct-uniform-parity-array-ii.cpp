class Solution {
public:

    bool try_even(vector<int>& nums1, int size, vector<int>& parity) {

        int min_odd = INT_MAX;

        for (int i = 0; i < size; i++) {
            if (nums1[i] % 2 == 1) {
                min_odd = min(min_odd, nums1[i]);
            }
        }

        if (min_odd == INT_MAX) {
            return true;
        }

        for (int i = 0; i < size; i++) {

            if (nums1[i] % 2 == 1) {

                if (nums1[i] == min_odd) {
                    return false;
                }
            }
        }

        return true;
    }

    bool try_odd(vector<int>& nums1, int size, vector<int>& parity) {

        int min_odd = INT_MAX;

        for (int i = 0; i < size; i++) {
            if (nums1[i] % 2 == 1) {
                min_odd = min(min_odd, nums1[i]);
            }
        }

        if (min_odd == INT_MAX) {
            return false;
        }

        for (int i = 0; i < size; i++) {

            if (nums1[i] % 2 == 0) {

                if (nums1[i] - min_odd < 1) {
                    return false;
                }
            }
        }

        return true;
    }

    bool uniformArray(vector<int>& nums1) {

        int s = nums1.size();

        vector<int> parity(s, 0);

        int odd = 0;
        int even = 0;

        for (int i = 0; i < s; i++) {

            if (nums1[i] % 2 == 1) {
                parity[i] = 1;
                odd++;
            }
            else {
                parity[i] = 0;
                even++;
            }
        }

        bool makeEven = try_even(nums1, s, parity);
        bool makeOdd = try_odd(nums1, s, parity);

        return makeEven || makeOdd;
    }
};