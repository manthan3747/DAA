class Solution {
public:
    TreeNode* makeTree(vector<int>& nums, int l, int r) {
        if (l > r)
            return NULL;

        int pos = l;

        for (int i = l + 1; i <= r; i++) {
            if (nums[i] > nums[pos])
                pos = i;
        }

        TreeNode* root = new TreeNode(nums[pos]);

        root->left = makeTree(nums, l, pos - 1);
        root->right = makeTree(nums, pos + 1, r);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return makeTree(nums, 0, nums.size() - 1);
    }
};