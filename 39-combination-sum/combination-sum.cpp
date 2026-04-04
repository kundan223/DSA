class Solution {
public:

    void solve(vector<int>& candidates, int target, vector<int>& temp, 
               vector<vector<int>>& result, int i) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        if (target < 0 || i >= candidates.size()) {
            return;
        }

        temp.push_back(candidates[i]);
        solve(candidates, target - candidates[i], temp, result, i); 
        temp.pop_back(); 

        solve(candidates, target, temp, result, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;

        solve(candidates, target, temp, result, 0);

        return result;
    }
};