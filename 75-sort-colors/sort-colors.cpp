class Solution {
public:
    void sortColors(vector<int>& nums) {

        vector<int> count(3, 0);

        for (int num : nums)
            count[num]++;

        int index = 0;

        for (int color = 0; color < 3; color++) {
            for (int i = 0; i < count[color]; i++) {
                nums[index++] = color;
            }
        }
}
};