#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}//重载
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
typedef struct ListNode Node;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      ListNode* curr=head;//中
      ListNode *p=nullptr;//前
      while(curr)
     { 
      ListNode *temp=curr->next;//后
      curr->next=p;
      p=curr;
      curr=temp;
     }
     return p;//此时p为第一个节点
    }
};
