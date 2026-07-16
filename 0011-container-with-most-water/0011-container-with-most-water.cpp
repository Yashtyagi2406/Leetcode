class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0;
        int j= height.size()-1;
        int maxArea= 0;

        while(j> i){
            int currArea= (j-i) * min(height[i], height[j]);
            maxArea= max(currArea, maxArea);

            if(height[i] < height[j])
                i++;
            else 
                j--;
        }
        return maxArea;
    }
};