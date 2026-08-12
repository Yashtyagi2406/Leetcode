/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(NEED), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int camera =0;
    enum State{
        NEED = 0,
        CAMERA = 1,
        COVERED = 2
    };
    int dfs(TreeNode* root){
        if(root == NULL) return COVERED;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if(left == NEED || right ==NEED){
            camera ++;
            return CAMERA;
        }
        if(left == CAMERA || right == CAMERA) return COVERED;

        return NEED;
    }

    int minCameraCover(TreeNode* root) {
        if(dfs(root)== NEED)
            camera ++;

        return camera;
    }
};