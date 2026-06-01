class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            encoded += to_string(s.size()) + '#' + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        size_t i = 0;

        while (i < s.size()) {
            size_t j = s.find('#', i);

            int length = stoi(s.substr(i, j - i));

            string str = s.substr(j + 1, length);
            decoded.push_back(str);

            i = j + 1 + length;
        }

        return decoded;
    }
};
