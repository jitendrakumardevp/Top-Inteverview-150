class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> mp;
        int left = 0;
        int Longest = 0;
        int currLenth = 0;

        for (int i = 0; i < s.size(); i++) {

            if (mp.find(s[i]) != mp.end() && mp[s[i]] >= left) {

                left = mp[s[i]] + 1;
            }

            mp[s[i]] = i;

            currLenth = i - left + 1;
            Longest = max(currLenth, Longest);
        }

        return Longest;
    }
};
