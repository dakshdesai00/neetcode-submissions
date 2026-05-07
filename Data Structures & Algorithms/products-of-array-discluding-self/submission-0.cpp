class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int prod = 1;
        int zeros = 0;
        int zeroIndex = -1;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != 0) {
                prod *= nums[i];
            } else {
                zeros++;
                zeroIndex = i;
            }
        }

        vector<int> res(nums.size());

        // Case 1: more than one zero
        if (zeros > 1) {

            for (int i = 0; i < nums.size(); i++) {
                res[i] = 0;
            }
        }

        // Case 2: exactly one zero
        else if (zeros == 1) {

            for (int i = 0; i < nums.size(); i++) {

                if (i != zeroIndex) {
                    res[i] = 0;
                } else {
                    res[i] = prod;
                }
            }
        }

        // Case 3: no zeros
        else {

            for (int i = 0; i < nums.size(); i++) {
                res[i] = prod / nums[i];
            }
        }

        return res;
    }
};