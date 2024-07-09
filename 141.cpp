/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
class Solution {
public:
    bool hasCycle(ListNode *head) {
       unordered_set<ListNode*> seen;
        while(head)
        {
            if(seen.count(head))
            {
                return true;
            }
            seen.insert(head);
            head=head->next;
        }
        return false;
    }
};