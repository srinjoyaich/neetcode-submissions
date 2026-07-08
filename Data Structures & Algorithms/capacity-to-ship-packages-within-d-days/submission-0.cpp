class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int result = right;

        auto canship = [&](int capacity) {
            int currentload = 0;
            int requireddays = 1;
            for (int w : weights) {
                if (currentload + w > capacity) {
                    requireddays++;
                    currentload = 0;
                }

                currentload += w;
            }

            return requireddays <= days;
        };

        while(left <= right){
            int mid = left + (right-left) / 2;

            if(canship(mid)){
                result = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        return result;
    }
};