class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;

        for (int j = left; j < right; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[right]);
        return i;
    }

    int quick(vector<int>& nums, int left, int right, int k) {
        if (left == right)
            return nums[left];

        int p = partition(nums, left, right);

        if (p == k)
            return nums[p];

        if (p > k)
            return quick(nums, left, p - 1, k);

        return quick(nums, p + 1, right, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int index = nums.size() - k;
        return quick(nums, 0, nums.size() - 1, index);
    }
};