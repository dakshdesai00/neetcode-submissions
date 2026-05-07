class Solution {
public:
    char toLower(char letter) {
        if (letter >= 'A' && letter <= 'Z') {
            letter = letter + 32;
        }
        return letter;
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left <= right) {

            while (left < right && !isalnum(s[left])) {
                left++;
            }

            while (left < right && !isalnum(s[right])) {
                right--;
            }

            if (toLower(s[left]) != toLower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};