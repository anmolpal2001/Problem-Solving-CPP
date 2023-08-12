Ques : https://leetcode.com/problems/plus-one/

Solution : 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        bool carry = true;
        vector<int> result;
        for (int i = n - 1; i >= 0; i--) {
            if (carry) {
                if (digits[i] == 9) {
                    result.push_back(0);
                } else {
                    result.push_back(digits[i] + 1);
                    carry = false;
                }
            } else {
                result.push_back(digits[i]);
            }
        }
        if (carry) {
            result.push_back(1);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
