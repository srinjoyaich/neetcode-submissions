class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto sr = unique(nums.begin(),nums.end());

        nums.erase(sr,nums.end());

        return nums.size();
    }
};