class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans = -1;
        unordered_map<int, int> count;

        for (int i = 0; i <= nums.size() - k; i++) {
            unordered_set<int> st;

            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            for (int x : st) {
                count[x]++;
            }
        }
        for (auto it : count) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};