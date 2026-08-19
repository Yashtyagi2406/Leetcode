class Solution {
public:

    void dfs(vector<vector<int>>&image, int r , int c , int oldcolor, int newcolor){
        if(r < 0 || r >= image.size() || 
           c < 0 || c>= image[0].size())
            return ;

        if(image[r][c] != oldcolor) return;

        image[r][c] = newcolor;

        dfs(image , r -1, c, oldcolor, newcolor);
        dfs(image , r +1, c, oldcolor, newcolor);
        dfs(image , r , c-1, oldcolor, newcolor);
        dfs(image , r , c + 1, oldcolor, newcolor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor = image[sr][sc];
        int newcolor = color;

        if(oldcolor == newcolor) return image;
        dfs(image, sr , sc, oldcolor, newcolor);

        return image;
    }
};