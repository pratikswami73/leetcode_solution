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
    TreeNode*lastr(TreeNode*root){
        if(root->right==nullptr)return root;
        return lastr(root->right);
    }
    TreeNode*helper(TreeNode* root){
        if(root->left==nullptr)return root->right;
        if(root->right==nullptr)return root->left;
        
        TreeNode*rightchild=root->right;
        TreeNode*lastright=lastr(root->left);
        lastright->right=rightchild;

        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)return nullptr;
        if(root->val==key)return helper(root);

        TreeNode*dummy=root;
        while(root!=nullptr){
            if(root->val>key){
        if(root->left!=nullptr && root->left->val==key){
            root->left= helper(root->left);
        }
        else{
            root=root->left;
        }
            }
            else{

        if(root->right!=nullptr && root->right->val==key){
           root->right= helper(root->right);
        }
        else{
            root=root->right;
        }
            }
        }
        return dummy;
    }
};