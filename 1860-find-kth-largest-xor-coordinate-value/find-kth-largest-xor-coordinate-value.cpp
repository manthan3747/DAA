class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> a;

        vector<int> pre(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int x = 0;

            for (int j = 0; j < n; j++) {
                x ^= matrix[i][j];
                pre[j + 1] ^= x;
                a.push_back(pre[j + 1]);
            }
        }

        nth_element(a.begin(), a.begin() + k - 1, a.end(), greater<int>());

        return a[k - 1];
    }
};