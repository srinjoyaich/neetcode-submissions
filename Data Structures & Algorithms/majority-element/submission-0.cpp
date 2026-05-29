class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freqmap;

        for(int i=0;i<nums.size();i++){
            freqmap[nums[i]]++;
        }

        int n = nums.size();
        for(auto it : freqmap){
            if(it.second > n/2){
                return it.first;
            } 
        }

        return -1;
    }
};