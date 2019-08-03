/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class BSTIterator {
// public:
//     BSTIterator(TreeNode* root) {
//         counter = 0;curPtr=0;
//         InTraversalBST(root,arr);
//     }
    
//     /** @return the next smallest number */
//     int next() {
//         return arr[curPtr++];
//     }
    
//     /** @return whether we have a next smallest number */
//     bool hasNext() {
//         return (curPtr<counter);
//     }
// private:
//     vector<int> arr;
//     int counter;
//     int curPtr;
//     void InTraversalBST(TreeNode* root,vector<int>& arr){
//         if(root==nullptr)
//             return ;
//         InTraversalBST(root->left,arr);
//         arr.push_back(root->val);counter++;
//         InTraversalBST(root->right,arr);
//     }
// };

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        pushLeftSon(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = sta.top();
        sta.pop();
        pushLeftSon(tmpNode->right);
        return tmpNode->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !sta.empty();
    }
private:
    stack<TreeNode*> sta;
    void pushLeftSon(TreeNode* root){
        while(root!=nullptr){
            sta.push(root);
            root = root->left;
        }
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */