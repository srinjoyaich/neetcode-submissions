class Solution {
public:
    bool isPalindrome(string s) {
        string filterd = "";

        for(char c:s){
            if(isalnum(c)){
                filterd += tolower(c);
            }
        }
        string r(filterd.rbegin(),filterd.rend());

        if(filterd == r){
            return true;
        }
        else{
            return false;
        }


    }
};
