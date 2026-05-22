class Solution {
public:

    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> level;

    void dfs(TreeNode* root, TreeNode* par, int lvl) {

        if (root == NULL) {
            return;
        }

        parent[root] = par;
        level[root] = lvl;

        dfs(root->left, root, lvl + 1);
        dfs(root->right, root, lvl + 1);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        dfs(root, NULL, 0);

        int lp = level[p];
        int lq = level[q];

        while (lp > lq) {
            p = parent[p];
            lp--;
        }

        while (lq > lp) {
            q = parent[q];
            lq--;
        }

        while (p != q) {
            p = parent[p];
            q = parent[q];
        }

        return p;
    }
};