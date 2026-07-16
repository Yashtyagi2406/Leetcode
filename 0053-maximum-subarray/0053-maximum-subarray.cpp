class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum= nums[0];
        int n= nums.size();
        int maxSum= nums[0];

        for(int i= 1; i< n; i++){
            // int currentSum = 0;
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};