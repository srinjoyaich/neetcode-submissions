class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long mid) {
        long long currentSum = 0;
        int count = 1; // start with one subarray
        for (int num : nums) {
            if (currentSum + num > mid) {
                count++;
                currentSum = num;
                if (count > k) return false; // too many subarrays
            } else {
                currentSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        long long left = *max_element(nums.begin(), nums.end());
        long long right = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canSplit(nums, k, mid)) {
                ans = mid;
                right = mid - 1; // try smaller
            } else {
                left = mid + 1; // need larger
            }
        }
        return (int)ans;
    }
};
