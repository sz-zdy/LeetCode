/*
* @Author: ShenZheng
* @Date:   2018-11-06 19:20:09
* @Last Modified by:   ShenZheng
* @Last Modified time: 2018-11-06 21:06:55
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* list)
{
    while(list!=NULL)
    {
        cout<<list->val;
        list=list->next;
        if(list!=NULL)
            cout<<"->";
    }
    cout<<endl;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *pre,*cur;
    if(l1==NULL)
        return l2;
    else if(l2==NULL)
        return l1;
    else
        ListNode* l3=l1->val<l2->val?(l1->next):(l2->next);
    cur=l3;

    while(l1!=NULL || l2!=NULL)
    {
        if(l1==NULL)
        {
            pre->next=l2;
            l2=NULL;
        }
        else if(l2==NULL)
        {
            pre->next=l1;
            l1==NULL;
        }
        else
        {
            if(l1->val<l2->val)
            {

                l1=l1->next;
            }
            else
            {

                l2=l2->next;
            }
        }
    }
    return l3;

}

ListNode *MakeList(int *arr, int size)
{
    ListNode * tmp_ptr=NULL;
    for(int i=size-1;i>=0;i--)
    {
        ListNode *tmp=new ListNode(arr[i]);
        tmp->next=tmp_ptr;
        //cout<<tmp->val<<" "<<tmp->next<<endl;
        tmp_ptr=tmp;
    }
    return tmp_ptr;
}

void DeleteList(ListNode *list)
{
    ListNode *tmp;
    for(;list!=NULL;list=tmp)
    {
        tmp=list->next;
        delete list;
    }
}

int main(){
    int a[3]={1,2,4};
    int b[3]={1,3,4};
    ListNode *l1=MakeList(a,3);
    ListNode *l2=MakeList(b,3);
    printList(l1);
    printList(l2);
    ListNode *l3=mergeTwoLists(l1,l2);
    printList(l3);
    DeleteList(l1);
    DeleteList(l2);
    return 0;
}