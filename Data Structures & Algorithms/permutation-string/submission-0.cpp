class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());

        if(s2.contains(s1)){
            return true;
        }
        else{
            return false;
        }
    }
};
