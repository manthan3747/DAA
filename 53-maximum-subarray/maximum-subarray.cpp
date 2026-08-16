class Solution {
public:

    int crossSum(vector<int>& nums, int left, int mid, int right) {

        int leftSum = -1000000000;
        int sum = 0;

        // Find maximum sum on left side
        for (int i = mid; i >= left; i--) {
            sum = sum + nums[i];

            if (sum > leftSum)
                leftSum = sum;
        }

        int rightSum = -1000000000;
        sum = 0;

        // Find maximum sum on right side
        for (int i = mid + 1; i <= right; i++) {
            sum = sum + nums[i];

            if (sum > rightSum)
                rightSum = sum;
        }

        return leftSum + rightSum;
    }

    int divide(vector<int>& nums, int left, int right) {

        // Only one element
        if (left == right)
            return nums[left];

        int mid = left + (right - left) / 2;

        // Maximum subarray in left half
        int leftMax = divide(nums, left, mid);

        // Maximum subarray in right half
        int rightMax = divide(nums, mid + 1, right);

        // Maximum subarray crossing middle
        int crossMax = crossSum(nums, left, mid, right);

        return max(leftMax, max(rightMax, crossMax));
    }

    int maxSubArray(vector<int>& nums) {

        return divide(nums, 0, nums.size() - 1);
    }
};