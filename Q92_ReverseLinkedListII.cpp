/*
* @Author: ShenZheng
* @Date:   2019-06-18 15:44:25
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-06-18 16:46:26
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL || m<0 || m>=n)
            return head;
        ListNode* Nodeheader=new ListNode(0);
        Nodeheader->next=head;
        int index=0;
        ListNode* helper=Nodeheader;
        ListNode* curListNode=helper;
        for(;index<m-1;index++)
        {
            curListNode=curListNode->next;
        }
        curListNode->next=func(curListNode->next,n-m);
        return (Nodeheader->next);
    }
    ListNode* func(ListNode* head, int num)
    {
        ListNode* CurNode = new ListNode(0);
        CurNode->next = head;
        ListNode* NextNode = head->next;
        ListNode* PreNode = NULL;

        for(int i=0;i<num;i++)
        {
            PreNode=CurNode->next;
            CurNode->next=NextNode;
            NextNode=NextNode->next;
            CurNode->next->next=PreNode;
        }
        head->next=NextNode;
        return (CurNode->next);
    }
};

int main(){
    ListNode *root=new ListNode(1);
    root->next=new ListNode(2);
    root->next->next=new ListNode(3);
    root->next->next->next=new ListNode(4);
    ListNode* result = Solution().reverseBetween(root,1,4);
    while(result!=NULL)
    {
        cout<<(result->val)<<" ";
        result=result->next;
    }
    return 0;
}