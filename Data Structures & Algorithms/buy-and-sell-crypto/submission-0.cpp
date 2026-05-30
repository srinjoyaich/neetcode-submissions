class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxdiff = 0;
        int currdiff = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                currdiff = prices[j] - prices[i];
                maxdiff = max(currdiff,maxdiff);
            }
        }

        return maxdiff;
    }
};
