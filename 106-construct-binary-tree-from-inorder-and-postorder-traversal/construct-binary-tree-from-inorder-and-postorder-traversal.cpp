
class Solution {
public:
    int index;
    unordered_map<int, int> mp;

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        index = postorder.size() - 1;

        // Store inorder values and their indices
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return helper(inorder, postorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& inorder,
                     vector<int>& postorder,
                     int start, int end) {

        if (start > end)
            return nullptr;

        // Last element in postorder is the root
        int rootVal = postorder[index--];

        TreeNode* root = new TreeNode(rootVal);

        // Find root position in inorder
        int mid = mp[rootVal];

        // Build RIGHT subtree first
        root->right = helper(inorder, postorder, mid + 1, end);

        // Build LEFT subtree
        root->left = helper(inorder, postorder, start, mid - 1);

        return root;
    }
};
