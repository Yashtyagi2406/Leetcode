class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int count = 0;
        int ans= -1;
        while(curr){
            if(curr->left == nullptr){
                if(++count == k)
                    ans=  curr-> val;
                
                curr = curr->right;
            }
            else{
                TreeNode* pred = curr->left;

                while(pred->right && pred->right != curr)
                    pred = pred->right;

                if(pred->right == nullptr){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    pred->right = nullptr;

                    if(++count == k)
                        ans= curr-> val;
                    
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};