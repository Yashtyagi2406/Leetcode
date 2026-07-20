class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n= nums.size();
        int current;
        int i= 0;

        while(i < n){
            current = nums[i];

            if(current >= 1 && current <= n){
                int correctIndex = current -1 ;
                if(i== correctIndex)
                    i++;
                else if(nums[correctIndex]== current)
                    i++;
                else{
                    swap(nums[i], nums[correctIndex]);
                }
            }
            else{
                i++;
            }
        }
         for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1)
                 return i + 1;
        }
            return n + 1;
    }
};