
class Solution {
public:

    TreeNode* helper(vector<int>& nums, int start, int end) {

        // Base condition
        if (start > end)
            return nullptr;

        // Find middle element
        int mid = start + (end - start) / 2;

        // Create root node
        TreeNode* root = new TreeNode(nums[mid]);

        // Construct left subtree
        root->left = helper(nums, start, mid - 1);

        // Construct right subtree
        root->right = helper(nums, mid + 1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return helper(nums, 0, nums.size() - 1);
    }
};
