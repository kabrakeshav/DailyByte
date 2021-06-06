/**
 * Apple
 * Given a potentially cyclical linked list where each value is unique, 
 * return the node at which the cycle starts.
 * If the list does not contain a cycle, return null.
 */

#include<iostream>
#include<unordered_map>
using namespace std;


/**
 * @author keshav kabra
 * @since June 6, 2021
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



/** function detectCycle
 * @param ListNode*, denoting the head of the linked-list
 * @return ListNode*, denoting the reference to the start of cycle
 */ 
ListNode *detectCycle(ListNode *head) 
{
    
    /** Logic :
     * Store in map every ListNode and its count part
     * If we find a node (while iterating) already present in the 
     * map, it is the start of cycle and hence return this node
     * If loop ends, it means no loop is there in linked-list, 
     * hence return NULL.
     */ 
    
    if(head == NULL)
        return NULL;
    
    unordered_map<ListNode*, int> mp;
    
    while(head)
    {
        if(mp.find(head) == mp.end())
        {
            mp[head]++;
            head = head->next;
        }
        else
            return head;
    }
    
    return NULL;
}



// main function - driver code
int main()
{
	
	// TESTCASE 1
    
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	ListNode* ans = detectCycle(l1);
    if(ans == NULL)
        cout<<"NULL returned\n";
    else
    	cout<<"Reference:"<<ans<<"   Val:"<<ans->val<<"\n";
	l1 = nullptr;
	ans = nullptr;
	
	
	// TESTCASES 2
	
	l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	l1->next->next->next = new ListNode(4);
	l1->next->next->next->next = new ListNode(5);
	l1->next->next->next->next->next = l1->next;
	ans = detectCycle(l1);
	if(ans == NULL)
        cout<<"NULL returned\n";
    else
    	cout<<"Reference:"<<ans<<"   Val:"<<ans->val<<"\n";
	l1 = nullptr;
	ans = nullptr;
	
	
	// TESTCASES 3
	
    l1 = new ListNode(1);
	l1->next = new ListNode(9);
	l1->next->next = new ListNode(3);
	l1->next->next->next = new ListNode(7);
	l1->next->next->next->next = l1->next->next->next;
	ans = detectCycle(l1);
	if(ans == NULL)
        cout<<"NULL returned\n";
    else
    	cout<<"Reference:"<<ans<<"   Val:"<<ans->val<<"\n";
	
	return 0;
}
