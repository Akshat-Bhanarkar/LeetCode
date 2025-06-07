class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> st;
        TreeNode* lastVisited = nullptr;
        TreeNode* curr = root;

        while (!st.empty() || curr) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* node = st.top();
                if (node->right && lastVisited != node->right) {
                    curr = node->right;
                } else {
                    result.push_back(node->val);
                    lastVisited = node;
                    st.pop();
                }
            }
        }
        return result;
    }
};