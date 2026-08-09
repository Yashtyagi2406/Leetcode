/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     map< int, vector<pair<int, int>>> mp;

    void dfs(TreeNode* root, int row, int col){
        if(root == NULL) return;

        mp[col].push_back({row, root->val});

        dfs(root->left, row + 1, col-1);
         dfs(root->right, row + 1, col + 1);
        
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        dfs(root, 0, 0);

        for(auto &it : mp){
           sort(it.second.begin(), it.second.end());

           vector<int> temp;

           for(auto &p : it.second){
            temp.push_back(p.second);
           }

           ans.push_back(temp);
        }

        return ans;
    }
};