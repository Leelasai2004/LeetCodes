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
    void solve(bool &flag, TreeNode* root, long long mini, long long maxi){
        if(root == NULL || flag == false){
            return;
        }
        if(root->val <= mini || root->val >= maxi){
            flag = false;
            return;
        }
        solve(flag, root->left, mini, root->val);
        solve(flag, root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        bool flag = true;
        solve(flag, root, LLONG_MIN, LLONG_MAX);
        return flag;
    }
};
