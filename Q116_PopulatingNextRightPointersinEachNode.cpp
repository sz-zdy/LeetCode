/*
* @Author: ShenZheng
* @Date:   2019-06-24 21:33:18
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-25 09:34:19
*/

#include <iostream>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        if(root->left)  //如果存在左节点，那么必定存在右节点
        {
            root->left->next=root->right;
            if(root->next)
                root->right->next=root->next->left;
            else
                root->right->next=NULL;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};

int main(){

    return 0;
}