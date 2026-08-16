class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;

        for (auto q : queries) {
            int k = q[0];
            int trim = q[1];

            vector<pair<string, int>> a;

            for (int i = 0; i < nums.size(); i++) {
                string x = nums[i].substr(nums[i].size() - trim);
                a.push_back({x, i});
            }

            sort(a.begin(), a.end());

            ans.push_back(a[k - 1].second);
        }

        return ans;
    }
};