class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);

        for (char task : tasks) {
            count[task - 'A']++;
        }

        sort(count.begin(), count.end());

        int maxCount = count[25];
        int gaps = maxCount - 1;

        int spaces = gaps * n;

        for (int i = 24; i >= 0; i--) {
            spaces -= min(gaps, count[i]);
        }

        if (spaces > 0)
            return tasks.size() + spaces;

        return tasks.size();
    }
};