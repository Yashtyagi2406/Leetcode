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
    void dfs(TreeNode* root, int target, int depth, TreeNode* parent,
             int &targetDepth, TreeNode* &targetParent) {

        if (root == NULL)
            return;

        if (root->val == target) {
            targetDepth = depth;
            targetParent = parent;
            return;
        }

        dfs(root->left, target, depth + 1, root, targetDepth, targetParent);
        dfs(root->right, target, depth + 1, root, targetDepth, targetParent);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int depthX = -1, depthY = -1;
        TreeNode* parentX = NULL;
        TreeNode* parentY = NULL;

        dfs(root, x, 0, NULL, depthX, parentX);
        dfs(root, y, 0, NULL, depthY, parentY);

        return depthX == depthY && parentX != parentY;
    }
};