class Solution {
public:
    bool checkMap(unordered_map<char,int>& freq){
        for(auto it: freq){
            if(it.second > 0) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int startIndex = -1;
        int len = s.length() + 1;
        if(t.length() > s.length()) return "";
        unordered_map<char,int> freq;
        for(auto c: t){
            freq[c]++;
        }
        int left = 0;
        int right = 0;
        while(left <= right && right < s.length()){
            freq[s[right]]--;
            while(checkMap(freq)){
                if(len > right - left + 1){
                    len = right - left + 1;
                    startIndex = left;
                }
                freq[s[left]]++;
                left++;
            }
            right++;
        }
        if(startIndex == -1) return "";
        return s.substr(startIndex, len);
    }
};
