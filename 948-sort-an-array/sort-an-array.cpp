class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r) {
        vector<int> temp;
        int i = l;
        int j = mid + 1;

        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= r) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++)
            nums[l + k] = temp[k];
    }

    void divide(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        divide(nums, l, mid);
        divide(nums, mid + 1, r);

        merge(nums, l, mid, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        divide(nums, 0, nums.size() - 1);
        return nums;
    }
};