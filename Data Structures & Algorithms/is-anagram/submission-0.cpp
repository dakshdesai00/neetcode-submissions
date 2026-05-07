class Solution {
   public:
    bool isAnagram(string s, string t) {
        vector<bool> arr1(26, false);
        for (int i = 0; i < s.length(); i++) {
            arr1[s[i] - 'a'] = true;
        }
        vector<bool> arr2(26, false);
        for (int i = 0; i < t.length(); i++) {
            arr2[t[i] - 'a'] = true;
        }
        for(int i = 0; i < 26; i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }
};
