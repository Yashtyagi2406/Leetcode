class Solution {
public:
    TreeNode* solve(
        vector<int> & preorder,
        int preStart,
        int preEnd,
        vector<int> & inorder,
        int inStart, 
        int inEnd,
        unordered_map <int ,int > & mp
    ){

        if(preStart > preEnd || inStart > inEnd)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = mp[root->val];
        int leftSize = inRoot - inStart;

        root->left = solve(
            preorder, 
            preStart + 1,
            preStart + leftSize,
            inorder,
            inStart, 
            inRoot- 1,
            mp
        );
         root->right = solve(
            preorder, 
            preStart + leftSize +1,
            preEnd,
            inorder,
            inRoot + 1,
            inEnd,
            mp
        );

        return root;

    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;


        for(int i= 0; i< inorder.size() ; i++){
            mp[inorder[i]] = i;

        }
        return solve(preorder, 
                     0, 
                    preorder.size() - 1,
                    inorder, 
                    0, 
                    inorder.size() - 1,
                    mp
        );
        
    }
};