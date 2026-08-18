class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int n = nums.size();

        int srin = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < srin) {
                continue;
            }
            if(nums[i] != srin){
                return srin;
            }

            srin++;
        }

        return srin;
    }
};