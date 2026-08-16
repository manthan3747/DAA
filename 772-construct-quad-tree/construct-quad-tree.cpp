class Solution {
public:
    Node* make(vector<vector<int>>& grid, int r, int c, int n) {
        int x = grid[r][c];
        bool same = true;

        for (int i = r; i < r + n; i++) {
            for (int j = c; j < c + n; j++) {
                if (grid[i][j] != x) {
                    same = false;
                    break;
                }
            }
            if (!same)
                break;
        }

        if (same)
            return new Node(x == 1, true);

        int h = n / 2;

        Node* a = make(grid, r, c, h);
        Node* b = make(grid, r, c + h, h);
        Node* d = make(grid, r + h, c, h);
        Node* e = make(grid, r + h, c + h, h);

        return new Node(true, false, a, b, d, e);
    }

    Node* construct(vector<vector<int>>& grid) {
        return make(grid, 0, 0, grid.size());
    }
};