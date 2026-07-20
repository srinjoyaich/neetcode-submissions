class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freqmap;

        for(int i=0;i<n;i++){
            freqmap[nums[i]]++;
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(freqmap[nums[i]] > n/3){
                ans.push_back(nums[i]);
                freqmap[nums[i]] = 0;
            }
        }

        return ans;
    }
};