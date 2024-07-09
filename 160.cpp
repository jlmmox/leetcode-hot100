#include<iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
            int val;
            ListNode *next;
            ListNode(int x) : val(x), next(nullptr) {}
                };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa=headA;
        ListNode* pb=headB;
        if(pa==nullptr||pb==nullptr)
            return nullptr;
        while(pa!=pb)
        { 
            if(pa==nullptr)
            pa=headB;
            pa=pa->next;
           if(pb==nullptr)
            pb=headA;
            pb=pb->next;
            
        }
        return pa;
    }
};