class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<vector<int>> bucket(nums.size() + 1);
        vector<int> ans;

        for(int num: nums)
            mp[num] ++;

        for(auto &it: mp){
            bucket[it.second].push_back(it.first);
        }
        for(int i= bucket.size() -1 ; i>=0; i--){
            for(int num : bucket[i]){
                ans.push_back(num);

                if(ans.size() == k)
                    return ans;
            }
        }
        return ans;
    }
};