/**
 * Amazon
 * Given a non-empty linked list, return the middle node of the list. 
 * If the linked list contains an even number of elements, return the node closer to the end.
 */

#include<iostream>
using namespace std;

/**
 * @author keshav kabra
 * @since June 4, 2021
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



/** function middleNode
 * @param ListNode*, denoting the head of the linked-list
 * @return int, denoting the value of middle-node of the linked-list
 */ 
int middleNode(ListNode* head) 
{
    
    /** Logic :
     * first we find the length of the linked-list
     * To find middle element, we divide it by 2 (which
     * points to node closer to end, if size is even)
     * Now, iterate through linked-list by size/2 times
     * and return the corresponding value
     * 
     * Time complexity : O(n)
     * Space complexity : O(1)
     * (n is size of linked-list)
     * 
     */ 
    
    if(head == NULL)
        return -1;
    
    int sz = 0;
    
    ListNode* t = head;
    
    while(t != NULL) {
        sz++;
        t = t->next;
    }
    
    int ind = sz/2;
    
    t = head;
    
    while(ind--)
        t = t->next;
    
    return t->val;
}


// main function - driver code
int main()
{
	
	// TESTCASES
	
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	cout<<middleNode(l1)<<"\n";
	l1 = nullptr;
	
	l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	l1->next->next->next = new ListNode(4);
	cout<<middleNode(l1)<<"\n";
	l1 = nullptr;
	
	l1 = new ListNode(1);
	cout<<middleNode(l1)<<"\n";
	l1 = nullptr;
	
	return 0;
}
