class Solution {
   public:
    bool isAnagram(string s, string t) {
        vector<int> arr1(26, 0);
        for (int i = 0; i < s.length(); i++) {
            arr1[s[i] - 'a'] += 1;
        }

        for (int i = 0; i < t.length(); i++) {
            arr1[t[i] - 'a'] -= 1;
        }
        for(int i = 0; i < 26; i++){
            if(arr1[i] != 0){
                return false;
            }
        }
        return true;
    }
};
