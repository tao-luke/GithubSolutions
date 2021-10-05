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
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        return helper(data);
    }
    TreeNode* helper(string& data){
        if (data[0] == '#'){
            if (data.size() != 1){
                data.erase(0,2);
            }
            return nullptr;
        }else{
            unsigned char index = data.find(',');
            string tmp = data.substr(0,index+1);
            tmp.pop_back();
            TreeNode* root = new TreeNode(stoi(tmp));
            data.erase(0,tmp.size()+1);
            root->left = helper(data);
            root->right = helper(data);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));