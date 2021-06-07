/**
 * Facebook
 * Given a linked list, containing unique values, reverse it, and return the result.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since June 7, 2021
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



/** function display_list
 * @param ListNode*, denoting the linked-list
 * displays the given linked-list on console
 */ 
void display_list(ListNode *ls)
{
	while(ls != nullptr)
	{
		cout<<ls->val<<" ";
		ls = ls->next;
	}
	cout<<"\n";
}



/** function reverseList
 * @param ListNode*, denoting the head of linked-list to be reversed
 * @return ListNode*, denoting the reversed linked-list
 */ 
ListNode* reverseList(ListNode* head) 
{
    
    /** Logic :
     * We iterate through the linked-list and make each node
     * pointing to its previous node, thus making the linked-list
     * reversed
     * 
     * Time complexity : O(n) as entire linked-list is traversed
     * Space complexity : O(1) inplace reversed
     * [ n is the size of linked-list ]
     */
    
    if(head==NULL || head->next==NULL)
        return head;
    
    ListNode *r = NULL;
    ListNode *s = NULL;
    
    while(head)
    {
        s = r;
        r = head;
        head = head->next;
        r->next = s;
    }
    return r;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	ListNode* ans = reverseList(l1);
	display_list(ans);
	l1 = nullptr;
	ans = nullptr;
	
	l1 = new ListNode(7);
	l1->next = new ListNode(15);
	l1->next->next = new ListNode(9);
	l1->next->next->next = new ListNode(2);
	ans = reverseList(l1);
	display_list(ans);
	l1 = nullptr;
	ans = nullptr;
	
	l1 = new ListNode(1);
	ans = reverseList(l1);
	display_list(ans);
	
	
	
	return 0;
}
