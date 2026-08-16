class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1)
            return {1};

        vector<int> a = beautifulArray((n + 1) / 2);
        vector<int> b = beautifulArray(n / 2);

        vector<int> ans;

        for (int x : a)
            ans.push_back(x * 2 - 1);

        for (int x : b)
            ans.push_back(x * 2);

        return ans;
    }
};