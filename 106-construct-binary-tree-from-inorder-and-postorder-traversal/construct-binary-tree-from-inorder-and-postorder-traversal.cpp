class Solution {
public:
    unordered_map<int, int> mp;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int is, int ie, int ps, int pe) {
        if (is > ie)
            return NULL;

        int rootValue = postorder[pe];
        TreeNode* root = new TreeNode(rootValue);

        int mid = mp[rootValue];
        int leftSize = mid - is;

        root->left = build(inorder, postorder,
                           is, mid - 1,
                           ps, ps + leftSize - 1);

        root->right = build(inorder, postorder,
                            mid + 1, ie,
                            ps + leftSize, pe - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(inorder, postorder,
                     0, inorder.size() - 1,
                     0, postorder.size() - 1);
    }
};