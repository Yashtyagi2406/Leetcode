class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0;
        int ans= 0;
        int n = s.size();


        for(int r = 0; r < n; r ++){
            if(mp.find(s[r]) != mp.end())
                left= max (left, mp[s[r]]+ 1);
            mp[s[r]]= r;

            ans= max(ans, r-left + 1);
        }

        return ans;
    }

};