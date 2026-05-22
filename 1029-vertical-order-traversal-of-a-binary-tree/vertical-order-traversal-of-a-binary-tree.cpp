

class Solution {
public:

    map<int, vector<pair<int,int>>> mp;

    void dfs(TreeNode* root, int row, int col){

        if(root == NULL){
            return;
        }

        mp[col].push_back({row, root->val});

        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        dfs(root, 0, 0);

        vector<vector<int>> ans;

        for(auto &it : mp){

            auto vec = it.second;

            sort(vec.begin(), vec.end());

            vector<int> temp;

            for(auto &p : vec){
                temp.push_back(p.second);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};