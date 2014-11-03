/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //http://www.2cto.com/kf/201311/257394.html
class Solution {  
public:  
    vector<int> postorderTraversal(TreeNode *root) {  
        // IMPORTANT: Please reset any member data you declared, as  
        // the same Solution instance will be reused for each test case.  
        stack<TreeNode*> TreeStack;  
        vector<int> result;  
        TreeNode * Hasvisited;  
           
        if(root == NULL) return result;  
        while(root || !TreeStack.empty()){  
            while(root){  
                TreeStack.push(root);  
                root = root->left;  
            }  
            root = TreeStack.top();  
   
            if(root->right == NULL || Hasvisited == root->right){  
                result.push_back(root->val);  
                Hasvisited = root;  
                TreeStack.pop();  
                root = NULL;  
            }  
            else{  
                root = root->right;  
            }  
        }  
           
        return result;  
           
    }  
};
