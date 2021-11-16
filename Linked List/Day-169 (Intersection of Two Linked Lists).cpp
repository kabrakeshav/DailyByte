/**
 * Given the reference to two linked lists, return the node at which they intersect.
 * Note: If the two lists never intersect, return null.
 */

#include<iostream>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since November 16, 2021
 */



/** struct ListNode
 * For storing linked-list nodes and order
 * 'val' contains value of node
 * 'next' contains address of next node of linked-list
 */ 
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};



/** function getIntersectionNode
 * @param ListNode*, head of first linked-list
 * @param ListNode*, head of second linked-list
 * @return ListNode*, node at which given two linked-list intersects (else NULL)
 */ 
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    if(headA==NULL || headB==NULL)
        return NULL;
    
    int len1=0, len2=0;
    
    ListNode* h1 = headA;
    ListNode* h2 = headB;
    
    while(h1) {
        len1++;
        h1 = h1->next;
    }
    
    while(h2) {
        len2++;
        h2 = h2->next;
    }
    
    int diff = abs(len1-len2);
    
    if(len1 > len2) {
        h1 = headA;
        h2 = headB;
    }
    else {
        h1 = headB;
        h2 = headA;
    }
    
    // getting h1 and h2 at point from which last node is equi-distant
    while(diff--) {
        h1 = h1->next;
    }
    
    while(h1 && h2)
    {
        if(h1 == h2)
            return h1;
        h1 = h1->next;
        h2 = h2->next;
    }
    
    return NULL;
}



// main function - driver code
int main()
{
	ListNode *h1, *h2, *ans;
	
	
	// TESTCASE-1
	
	h1 = new ListNode(4);
	h1->next = new ListNode(1);
	h1->next->next = new ListNode(8);
	h1->next->next->next = new ListNode(4);
	h1->next->next->next->next = new ListNode(5);
	
	h2 = new ListNode(5);
	h2->next = new ListNode(6);
	h2->next->next = new ListNode(1);
	h2->next->next->next = h1->next->next;
	
	ans = getIntersectionNode(h1, h2);
	ans==NULL ? cout<<-1<<"\n" : cout<<ans->val<<"\n";
	
	
	// TESTCASE-2
	
	h1 = new ListNode(1);
	h1->next = new ListNode(9);
	h1->next->next = new ListNode(1);
	h1->next->next->next = new ListNode(2);
	h1->next->next->next->next = new ListNode(4);
	
	h2 = new ListNode(3);
	h2->next = h1->next->next->next;
	
	ans = getIntersectionNode(h1, h2);
	ans==NULL ? cout<<-1<<"\n" : cout<<ans->val<<"\n";
	
	
	// TESTCASE-3
	
	h1 = new ListNode(2);
	h1->next = new ListNode(6);
	h1->next->next = new ListNode(4);
	
	h2 = new ListNode(1);
	h2->next = new ListNode(5);
	
	ans = getIntersectionNode(h1, h2);
	ans==NULL ? cout<<-1<<"\n" : cout<<ans->val<<"\n";
	
	
	return 0;
}
