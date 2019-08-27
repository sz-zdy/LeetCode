/*
* @Author: ShenZheng
* @Date:   2019-06-27 10:36:55
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-27 13:09:48
*/

#include <iostream>

using namespace std;


 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL)
            return ;
        //step1:找到中间位置
        ListNode* fastptr = head;
        ListNode* slowptr = head;
        while(fastptr!=NULL)
        {
            fastptr=fastptr->next;
            if(fastptr!=NULL)
            {
                fastptr=fastptr->next;
                slowptr=slowptr->next;
            }
        }
        ListNode* midptr = slowptr;

        //step2:对后半段反转
        ListNode* dummy = new ListNode(0);
        ListNode* nextNode;
        while(slowptr!=NULL)
        {
            nextNode = slowptr->next;
            slowptr->next = dummy->next;
            dummy->next = slowptr;
            slowptr=nextNode;
        }
        // printList(head);
        // printList(dummy->next);
        //step3:两个链表进行衔接
        fastptr = head;     //复用fastptr和slowptr
        slowptr = dummy->next;
        while(slowptr!=midptr)
        {
            nextNode=fastptr->next;
            fastptr->next=slowptr;
            slowptr=slowptr->next;
            fastptr=fastptr->next;
            fastptr->next=nextNode;
            fastptr=nextNode;
        }
    }
    void printList(ListNode* root)
    {
        while(root!=NULL)
        {
            cout<<(root->val)<<" ";
            root=root->next;
        }
        cout<<endl;
    }
};

int main(){
    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    // root->next->next->next->next->next = new ListNode(6);
    //Solution().printList(root);
    Solution().reorderList(root);
    return 0;
}