class Solution {
public:
    static constexpr int MAX = 1000001;

    string smallestPalindrome(string s, int k) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        vector<int> half(26, 0);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
            if (cnt[i] & 1)
                mid.push_back(char('a' + i));
        }

        if (countWays(half) < k)
            return "";

        int len = 0;
        for (int x : half)
            len += x;

        string left;

        while ((int)left.size() < len) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0)
                    continue;

                half[c]--;

                int ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char(c + 'a'));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }

private:
    int countWays(vector<int>& freq) {
        int remain = 0;
        for (int x : freq)
            remain += x;

        long long ans = 1;

        for (int x : freq) {
            if (x == 0)
                continue;

            ans *= nCr(remain, x);

            if (ans >= MAX)
                return MAX;

            remain -= x;
        }

        return (int)ans;
    }

    long long nCr(int n, int r) {
        if (r > n)
            return 0;

        r = min(r, n - r);

        long long res = 1;

        for (int i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i;

            if (res >= MAX)
                return MAX;
        }

        return res;
    }
};