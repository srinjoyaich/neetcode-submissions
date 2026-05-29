class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramgroups;

        for(string word:strs){
            string sortedword = word;
            sort(sortedword.begin(),sortedword.end());

            anagramgroups[sortedword].push_back(word);
        }

        vector<vector<string>> result;

        for(auto& entry:anagramgroups){
            result.push_back(entry.second);
        }

        return result;
    }
};
