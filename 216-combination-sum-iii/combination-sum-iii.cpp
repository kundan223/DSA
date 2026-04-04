class Solution {
public:

    void kundan(int n, int k, vector<vector<int>>& ans, vector<int>& temp, int q) {
        

        if (k == 0 && n == 0) {
            ans.push_back(temp);
            return;
        }

    
        if (k == 0 || n < 0) {
            return;
        }

        for (int i = q; i <= 9; i++) {

            if (i > n) break;   

            temp.push_back(i);
            kundan(n - i, k - 1, ans, temp, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        kundan(n, k, ans, temp, 1);

        return ans;
    }
};