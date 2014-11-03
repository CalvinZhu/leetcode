/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> path;
		stack<TreeNode*> stk;
		while(root != NULL || !stk.empty())
		{
			if(root != NULL)
			{
				while(root)
				{
					path.push_back(root->val);
					stk.push(root);
					root=root->left;
				}
			}
			else{
				root = stk.top()->right;
				stk.pop();
			}
		}
		return path;
    }
};
