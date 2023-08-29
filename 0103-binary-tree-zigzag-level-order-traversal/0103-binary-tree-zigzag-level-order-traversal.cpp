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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(root == NULL){
            return {};
        }
        vector<vector<int>>result;
        queue<TreeNode*>q;
        q.push(root);
        bool direction = true;
        while(!q.empty()){
            
           
            int size = q.size();
            vector<int>ans(size);

            for(int i =0 ; i<size; i++){

                 TreeNode*temp = q.front();
                 q.pop();
                 
                int index = direction ? i : size-i-1;
                ans[index] = temp->val;

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
            }

            direction = !direction;
            result.push_back(ans);
        }

        return result;

         
    }
    
};