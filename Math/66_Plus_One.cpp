class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int size = digits.size();
        vector<int> result;

        int carry = 1;
        int i = 0;
        for (i = size; i > 0; i--) {

            int temp = digits[i - 1] + carry;

            int nDigit = temp % 10;
            carry = temp / 10;
            result.push_back(nDigit);
        }

        if (carry && i == 0)
            result.push_back(1);

        reverse(result.begin(), result.end());

        return result;
    }
};
