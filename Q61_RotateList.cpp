/*
* @Author: ShenZheng
* @Date:   2019-05-13 21:39:25
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-05-13 21:57:11
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k<=0)
            return head;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        int size = 1;
        ListNode* result = NULL;
        while(ptr1->next!=NULL)
        {
            ptr1=ptr1->next;
            size++;
        }
        int rotateK = k%size;
        if(rotateK==0)
            return head;
        else
        {
            ptr1->next=head;
            for(int i=0;i<size-rotateK-1;i++)
            {
                ptr2=ptr2->next;
            }
            result=ptr2->next;
            ptr2->next=NULL;
        }
        return result;
    }
};

int main(){

    return 0;
}