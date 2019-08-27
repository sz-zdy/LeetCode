/*
* @Author: ShenZheng
* @Date:   2019-06-27 09:37:46
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-27 10:15:58
*/

#include <iostream>

using namespace std;

//方法1：利用map来实现
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        map<Node*,Node*> nodemap;
        Node* cur = head;
        while(cur!=NULL)
        {
            Node* newNode = new Node(cur->val,NULL,NULL);
            nodemap[cur]=newNode;
            cur=cur->next;
        }
        nodemap[NULL]=NULL;
        cur=head;
        while(cur!=NULL)
        {
            nodemap[cur]->next = nodemap[cur->next];
            nodemap[cur]->random = nodemap[cur->random];
            cur=cur->next;
        }
        return nodemap[head];
    }
};

//方法2：利用自身的关系来实现
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node* cur = head;
        Node* newNode = NULL;
        while(cur!=NULL)
        {
            newNode = new Node(cur->val,cur->next,NULL);
            cur->next = newNode;
            cur=cur->next->next;
        }

        cur = head;
        while(cur!=NULL)
        {
            cur->next->random=(cur->random)?(cur->random->next):NULL;
            cur=cur->next->next;
        }

        cur=head;
        Node* result = head->next;
        newNode = head->next;
        while(cur!=NULL)
        {
            cur->next = newNode->next;
            cur=cur->next;
            newNode->next = (cur==NULL)?cur:(cur->next);
            newNode=newNode->next;
        }
        return result;
    }
};


int main(){

    return 0;
}