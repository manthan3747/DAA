class Solution {
public:
    vector<int> nums;

    TreeNode* build(int left, int right) {
        if (left > right)
            return NULL;

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = build(left, mid - 1);
        root->right = build(mid + 1, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }

        return build(0, nums.size() - 1);
    }
};