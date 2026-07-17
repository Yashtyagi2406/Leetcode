class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0;
        int ans= 0;
        int n = s.size();


        for(int r = 0; r < n; r ++){
            if(mp.find(s[r]) != mp.end()) // duplicate mila?
                // left ko duplicate ke baad le jao,
                // leking kabhi peeche nhi lana
                left= max (left, mp[s[r]]+ 1);

                // current index ka latest index update kiya
            mp[s[r]]= r;

                // window ka size nikala and ans update kiya
            ans= max(ans, r-left + 1);
        }

        return ans;
    }

};