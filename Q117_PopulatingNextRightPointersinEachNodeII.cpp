/*
* @Author: ShenZheng
* @Date:   2019-06-25 09:35:54
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-25 11:08:56
*/

#include <iostream>

using namespace std;

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        Node* InterfacetoNext = NULL;
        if(root->left!=NULL && root->right!=NULL)
        {
            root->left->next=root->right;
            InterfacetoNext=root->right;
        }
        if(root->left!=NULL && root->right==NULL)
            InterfacetoNext=root->left;
        if(root->left==NULL && root->right!=NULL)
            InterfacetoNext=root->right;

        if(InterfacetoNext!=NULL)
        {
            Node* ConnectNode=NULL;
            Node* tmp=root->next;
            while(tmp!=NULL)
            {
                if(tmp->left)
                {
                    ConnectNode = tmp->left;
                    break;
                }
                if(tmp->right)
                {
                    ConnectNode = tmp->right;
                    break;
                }
                tmp=tmp->next;
            }
            InterfacetoNext->next=ConnectNode;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};

int main(){

    return 0;
}
 {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

 {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}