class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> freq;
        vector<int> ans;

       sort(nums.begin(), nums.end());

       for(int i= 0; i< nums.size(); i++){
            int count = 1;
            while( i+ 1< nums.size() && nums[i] == nums[i+ 1]){
                count ++;
                i++;
            }
             freq.push_back({nums[i], count});
       }
             sort(freq.begin(), freq.end(),
                    [](const pair<int,int> & a, const pair<int, int> &b){
                        return a.second> b.second;
                    }
                );
            for(int i= 0; i< k ; i++)
                ans.push_back(freq[i].first);
            
        return ans;
    }
};