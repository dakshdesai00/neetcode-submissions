class Solution {
   public:
    string encode(vector<string>& strs) {
        string encoded = "";

        for (string s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;

        while (i < s.length()) {
            // Find '#'
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            // Length of current string
            int len = stoi(s.substr(i, j - i));

            // Extract actual string
            string word = s.substr(j + 1, len);

            result.push_back(word);

            // Move to next encoded part
            i = j + 1 + len;
        }

        return result;
    }
};
