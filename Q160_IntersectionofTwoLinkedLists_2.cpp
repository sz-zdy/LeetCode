/*
* @Author: ShenZheng
* @Date:   2019-09-02 20:06:05
* @Last Modified by:   ShenZheng
* @Last Modified time: 2019-09-02 20:18:59
*/

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr) return nullptr;

        int NumA = 1,NumB = 1;
        ListNode *tmpHeadA = headA;
        ListNode *tmpHeadB = headB;
        while(tmpHeadA->next){
            NumA++;
            tmpHeadA = tmpHeadA->next;
        }

        while(tmpHeadB->next){
            NumB++;
            tmpHeadB = tmpHeadB->next;
        }

        if(tmpHeadA != tmpHeadB)
            return nullptr;

        if(NumA > NumB){
            for(int i = 0; i < (NumA-NumB); i++){
                headA=headA->next;
            }
        }else{
           for(int i = 0; i < (NumB-NumA); i++){
                headB=headB->next;
            }
        }

        while(headA != headB){
            headA=headA->next;
            headB=headB->next;
        }

        return headA;
    }
};

int main(){

    return 0;
}