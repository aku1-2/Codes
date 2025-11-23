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
        string s;
    serializeHelper(root, s);
    return s;
    }
    void serializeHelper(TreeNode* root, string &s) {
    if (!root) {
        s += "# ";
        return;
    }
    s += to_string(root->val) + " ";
    serializeHelper(root->left, s);
    serializeHelper(root->right, s);
}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
    return deserializeHelper(ss);
    }
    TreeNode* deserializeHelper(stringstream &ss) {
    string val;
    if (!(ss >> val))
        return nullptr;
    if (val == "#")
        return nullptr;
    TreeNode* node = new TreeNode(stoi(val));
    node->left = deserializeHelper(ss);
    node->right = deserializeHelper(ss);
    return node;
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));