class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty()){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());

        int longest = 1;
        int current = 1;
        int n = nums.size();

        for(int i=1;i<n;i++){
            if(nums[i] - nums[i-1] == 1){
                current ++;
                longest = max(longest,current);
            }
            else{
                current = 1;
            }
        }

        return longest;
    }
};
