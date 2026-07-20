class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        int expected = 1;

        for(int i= 0; i< n; i++){
            if(nums[i] <=0)
                continue;
            else if(nums[i] < expected)
                continue;

            else if(nums[i] == expected)
                expected ++;
            else 
                return expected;
              
        }
        return expected;
        
    }
};