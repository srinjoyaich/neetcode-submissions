class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char> charset;
            for (int j = i; j < s.size(); j++) {
                if (charset.find(s[j]) != charset.end()) {
                    break;
                }
                charset.insert(s[j]);
            }
            res = max(res, (int)charset.size());
        }

        return res;
    }
};
