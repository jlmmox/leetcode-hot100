#include<iostream>
#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<vector>
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

ListNode* CloneList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	ListNode* pCloneHead, *pCloneNode;
	if (pNode != NULL)
	{
		pCloneHead = new ListNode();
		pCloneHead->val = pNode->val;
		pCloneHead->next = NULL;
		pCloneNode = pCloneHead;
		pNode = pNode->next;
	}
	while (pNode != NULL)
	{
		ListNode* pTempNode = new ListNode();
		pTempNode->val= pNode->val;
		pTempNode->next= NULL;
		pCloneNode->next = pTempNode;
		pCloneNode = pCloneNode->next;
		pNode = pNode->next;
	}
	return pCloneHead;
}
    bool isPalindrome(ListNode* head) {

          //ListNode* q=head;//指针,在后面的操作中head的链表断了
          ListNode* q=CloneList(head);
          q=q->next;
          ListNode* newlist =  reverseList(head);
          ListNode* p=newlist;
          while(q!=nullptr)
          {
            if(p->val!=q->val)
                return false;
            p=p->next;
            q=q->next;
          }
          return true;
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* p=nullptr;
        ListNode* q=head;
        while(q)
        {
            ListNode* temp=q->next;
            q->next=p;
            p=q;
            q=temp;
        }
        return p;
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
  ListNode* head=creatlist2(1);
  Solution* a=new Solution();
  bool tf=a->isPalindrome(head);
  cout<<tf;
  return 0;

}