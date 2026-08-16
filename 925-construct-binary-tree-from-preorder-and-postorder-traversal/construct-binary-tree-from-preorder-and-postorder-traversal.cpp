class Solution {
public:
    unordered_map<int, int> pos;

    TreeNode* solve(vector<int>& pre, vector<int>& post, int ps, int pe, int qs, int qe) {
        if (ps > pe)
            return NULL;

        TreeNode* root = new TreeNode(pre[ps]);

        if (ps == pe)
            return root;

        int x = pos[pre[ps + 1]];
        int left = x - qs + 1;

        root->left = solve(pre, post, ps + 1, ps + left, qs, x);
        root->right = solve(pre, post, ps + left + 1, pe, x + 1, qe - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++)
            pos[postorder[i]] = i;

        return solve(preorder, postorder, 0, preorder.size() - 1,
                     0, postorder.size() - 1);
    }
};