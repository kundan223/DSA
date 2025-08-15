class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        int index = 0;
        for (int color = 0; color <= 2; color++) { 
            for (int count = 0; count < mp[color]; count++) {
                nums[index++] = color;
            }
        }
    }
};
