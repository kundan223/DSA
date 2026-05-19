class Solution {
public:

    vector<vector<int>> ans;

    void solve(TreeNode* root, int level) {

        if(root == NULL)
            return;

        if(ans.size() == level)
            ans.push_back({});

        if(level % 2 == 0)
            ans[level].push_back(root->val);

        else
            ans[level].insert(ans[level].begin(), root->val);

        solve(root->left, level + 1);
        solve(root->right, level + 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        solve(root, 0);

        return ans;
    }
};