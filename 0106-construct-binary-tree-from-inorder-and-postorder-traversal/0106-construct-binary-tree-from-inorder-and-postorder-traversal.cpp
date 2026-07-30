
class Solution {
public:
    TreeNode* solve(
        vector<int>& inorder,
        int inStart,
        int inEnd,
        vector<int>& postorder,
        int postStart,
        int postEnd,
        unordered_map<int, int>& mp
    ) {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = mp[root->val];
        int leftSize = inRoot - inStart;

        root->left = solve(
            inorder,
            inStart ,
            inRoot - 1,
            postorder,
            postStart,
            postStart + leftSize - 1,
            mp
        );

        root->right = solve(
            inorder,
            inRoot +1,
            inEnd,
            postorder,
            postStart + leftSize,
            postEnd -1,
            mp
        );

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return solve(
            inorder,
            0,
            inorder.size() - 1,
            postorder,
            0,
            postorder.size() - 1,
            mp
        );
    }
};