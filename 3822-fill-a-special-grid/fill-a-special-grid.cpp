class Solution {
public:
    vector<vector<int>> ans;

    void solve(int r, int c, int size, int start) {
        if (size == 1) {
            ans[r][c] = start;
            return;
        }

        int half = size / 2;
        int cnt = half * half;

        solve(r, c + half, half, start);
        solve(r + half, c + half, half, start + cnt);
        solve(r + half, c, half, start + 2 * cnt);
        solve(r, c, half, start + 3 * cnt);
    }

    vector<vector<int>> specialGrid(int n) {
        int size = 1 << n;
        ans.resize(size, vector<int>(size));

        solve(0, 0, size, 0);

        return ans;
    }
};