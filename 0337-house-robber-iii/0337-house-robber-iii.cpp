class Solution {
public:
    unordered_map<TreeNode*, int> dp;

    int calc(TreeNode* root) {
        if (!root) return 0;
        if (dp.count(root)) return dp[root];

        int pick = root->val;
        if (root->left) pick += calc(root->left->left) + calc(root->left->right);
        if (root->right) pick += calc(root->right->left) + calc(root->right->right);

        int skip = calc(root->left) + calc(root->right);

        return dp[root] = max(skip, pick);
    }

    int rob(TreeNode* root) {
        return calc(root);
    }
};