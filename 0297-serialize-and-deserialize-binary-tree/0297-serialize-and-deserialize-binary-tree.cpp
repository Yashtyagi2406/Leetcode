/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.

    void helper(TreeNode* root , string& ans){
        if(root == NULL){
            ans += "N,";
            return;
        }

        ans += to_string(root->val);
        ans += ",";

        helper(root->left , ans);
        helper(root-> right, ans);
    }

    string serialize(TreeNode* root) {
        string ans = "";
      helper(root, ans);
      return ans;

    }

    // Decodes your encoded data to tree.

    TreeNode* build(vector<string>&values, int& index){
        if(values[index] == "N"){
            index ++;
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(values[index]));
        index ++;

        node->left = build(values,index);
        node-> right = build(values, index);

        return node;
    }

    TreeNode* deserialize(string data) {
       
        vector<string> values;
        stringstream ss(data);

        string token;

        while (getline(ss, token, ',')) {
            values.push_back(token);
        }

        int index = 0;
        return build(values, index);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));