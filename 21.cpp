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
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 typedef struct ListNode Node;

 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* phead = new ListNode(-1);
        ListNode* p = phead;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                p->next = list1;
                list1 = list1->next;
            } else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        p->next = list1 == nullptr ? list2 : list1;
        return p->next;
    }
};
Node* creatlist2(int n) {
    //头节点 不存储数据，指针域指向空
	Node* Head=new Node;    
	Head->next = NULL; 
	//为了让节点连接成链接，定义pre，最开始pre等于Head    
	Node* pre = Head;  
	cout<<"input"<<endl;
	for(int i=0;i<n;i++)
	   {
        //每次循环都创建一个新的节点
		Node* temp = new Node;
		//把值赋给temp节点的数据域
		cin>>temp->val;
        //pre的指数域指向的下一个节点temp，把pre和temp连接起来
		pre->next = temp;
		//把temp节点赋给pre，重新定义pre
		pre = temp;
		//在下次for循环再一次创建新temp节点前，temp的指数域指向空
		temp->next = NULL;	
	}
	//把头节点返回，知道头节点，节点与节点之间又相互连接，所以知道每个节点中的值
	return Head;
}
int main()
{
  ListNode* heada=creatlist2(3);
  ListNode* headb=creatlist2(3);
  Solution* a=new Solution();
  ListNode* tf=a->mergeTwoLists(heada->next,headb->next);
  while(tf)
  {
    cout<<tf->val<<endl;
    tf=tf->next;
  }

  return 0;

}