/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        vector<int> level;
        unordered_map<TreeNode*, int> mp;
        mp[root] = 1;
        queue<TreeNode*> q;
        q.push(root);
        level.push_back(root->val);
        while (!q.empty()) {
            TreeNode* ptr = q.front();
            q.pop();
            if (mp.find(ptr) != mp.end()) {
                result.push_back(level);
                level.clear();
            }
            if (ptr->left) {
                if (level.empty()) {
                    mp[ptr->left] = 1;
                }
                level.push_back(ptr->left->val);
                q.push(ptr->left);
            }
            if (ptr->right) {
                if (level.empty()) {
                    mp[ptr->right] = 1;
                }
                level.push_back(ptr->right->val);
                q.push(ptr->right);
            }
        }
        for (auto& i : level) {
            cout << i << endl;
        }
        return result;
    }
};
