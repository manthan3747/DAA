class Solution {
public:
    int dist(vector<int>& p) {
        return p[0] * p[0] + p[1] * p[1];
    }

    int partition(vector<vector<int>>& points, int l, int r) {
        int pivot = dist(points[r]);
        int i = l;

        for (int j = l; j < r; j++) {
            if (dist(points[j]) < pivot) {
                swap(points[i], points[j]);
                i++;
            }
        }

        swap(points[i], points[r]);
        return i;
    }

    void solve(vector<vector<int>>& points, int l, int r, int k) {
        if (l >= r)
            return;

        int p = partition(points, l, r);

        if (p == k)
            return;

        if (p > k)
            solve(points, l, p - 1, k);
        else
            solve(points, p + 1, r, k);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        solve(points, 0, points.size() - 1, k - 1);

        vector<vector<int>> ans;

        for (int i = 0; i < k; i++)
            ans.push_back(points[i]);

        return ans;
    }
};