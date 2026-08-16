class Solution {
public:
    int modPow(int a, int b) {
        int ans = 1;
        a = a % 1337;

        while (b > 0) {
            if (b % 2 == 1)
                ans = (ans * a) % 1337;

            a = (a * a) % 1337;
            b = b / 2;
        }

        return ans;
    }

    int superPow(int a, vector<int>& b) {
        int ans = 1;
        a = a % 1337;

        for (int i = 0; i < b.size(); i++) {
            ans = modPow(ans, 10) * modPow(a, b[i]) % 1337;
        }

        return ans;
    }
};