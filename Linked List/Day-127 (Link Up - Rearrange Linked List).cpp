/**
 * Facebook
 * Given a singly linked list, re-order and group its nodes in such a way that the nodes in odd positions 
 * come first and the nodes in even positions come last.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since October 11, 2021
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



/** function rearrangeEvenOdd
 * @param ListNode*, head of linked-list
 * Prints list in required format
 */ 
void rearrangeEvenOdd(ListNode *head)
{
    ListNode* temp = head;
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        if(head->next != NULL)
            head = head->next->next;
        else
            break;
    }
    
    if(temp->next != NULL)
        temp = temp->next;
    
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        if(temp->next != NULL)
            temp = temp->next->next;
        else
            break;
    }
}




// main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	ListNode* head = new ListNode(4);
	head->next = new ListNode(4);
	head->next->next = new ListNode(5);
	head->next->next->next = new ListNode(6);
	head->next->next->next->next = new ListNode(3);
	head->next->next->next->next->next = new ListNode(2);
	head->next->next->next->next->next->next  = new ListNode(1);
	rearrangeEvenOdd(head);
	
	head = nullptr;
	cout<<"\n";
	
	
	// TESTCASE - 2
	
	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	rearrangeEvenOdd(head);
	
	return 0;
}
