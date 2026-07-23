class Solution {
public:
    int ans = INT_MIN;
    int helper(TreeNode* root){

        if(root == nullptr)
            return 0;
        int left = helper(root-> left);

        left = max(0, left);
        int right = helper(root-> right);

        right= max(0, right);
        ans = max(ans, left + right + root-> val);

        return root->val + max(left , right);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};