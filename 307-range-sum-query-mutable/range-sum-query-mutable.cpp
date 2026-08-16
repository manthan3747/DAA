class NumArray {
public:
    vector<int> tree;
    int n;

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            tree[node] = nums[l];
            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void change(int node, int l, int r, int index, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid)
            change(node * 2, l, mid, index, val);
        else
            change(node * 2 + 1, mid + 1, r, index, val);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int query(int node, int l, int r, int left, int right) {
        if (left <= l && r <= right)
            return tree[node];

        int mid = (l + r) / 2;
        int ans = 0;

        if (left <= mid)
            ans += query(node * 2, l, mid, left, right);

        if (right > mid)
            ans += query(node * 2 + 1, mid + 1, r, left, right);

        return ans;
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 1, 0, n - 1);
    }

    void update(int index, int val) {
        change(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};