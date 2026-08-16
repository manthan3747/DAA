class Solution {
public:
    unordered_map<int, int> mp;

    TreeNode* build(vector<int>& preorder, int ps, int pe,
                    int is, int ie) {
        if (ps > pe)
            return NULL;

        int rootValue = preorder[ps];
        TreeNode* root = new TreeNode(rootValue);

        int mid = mp[rootValue];
        int leftSize = mid - is;

        root->left = build(preorder, ps + 1, ps + leftSize,
                            is, mid - 1);

        root->right = build(preorder, ps + leftSize + 1, pe,
                             mid + 1, ie);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(preorder, 0, preorder.size() - 1,
                     0, inorder.size() - 1);
    }
};