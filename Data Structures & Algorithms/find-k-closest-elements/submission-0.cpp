class Solution {
public:
    // Custom comparator function
    static bool compare(int a, int b, int x) {
        if (abs(a - x) == abs(b - x)) {
            return a < b;  // smaller value first if equally close
        }
        return abs(a - x) < abs(b - x);  // closer value first
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Sort using a custom comparator with x
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            return compare(a, b, x);
        });

        // Take the first k elements
        vector<int> ans(arr.begin(), arr.begin() + k);

        // Sort result in ascending order as required
        sort(ans.begin(), ans.end());
        return ans;
    }
};
