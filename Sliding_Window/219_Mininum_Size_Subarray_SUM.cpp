class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int sum = 0;
        int left = 0;
        int minLen = INT_MAX;
        int currentMin = 0; 

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            while (sum >= target) {
                
                currentMin =  i - left + 1;
                minLen = min(currentMin, minLen);
                sum -= nums[left];
                left++;
            }
            
        }

        if(minLen == INT_MAX)
        {
            return 0;
        }

        return minLen;
    }
};
