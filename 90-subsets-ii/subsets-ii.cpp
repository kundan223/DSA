class Solution {
public:

    void kundan(vector<int>& nums, vector<vector<int>>& ans, int i, vector<int> temp, int n) {

        if (i >= n) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        

        kundan(nums, ans, i + 1, temp, n);
        temp.pop_back();
        

        while (i+1  < n && nums[i] == nums[i + 1])
        {
            i++;
        }
        kundan(nums, ans, i + 1 , temp, n );
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();

        vector<vector<int>> ans;


        kundan(nums, ans, i, temp, n);

        return ans;
    }
};