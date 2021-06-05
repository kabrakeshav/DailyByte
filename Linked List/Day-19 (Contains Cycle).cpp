/**
 * Microsoft
 * Given a linked list, containing unique numbers, return whether or not it has a cycle.
 */

#include<iostream>
#include<unordered_map>
using namespace std;


/**
 * @author keshav kabra
 * @since June 5, 2021
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



/** function hasCycle
 * @param ListNode*, denoting the head of the linked-list
 * @return bool, whether the linked-list has cycle or not
 */ 
bool hasCycle(ListNode *head) 
{
    
    /** Logic :
     * We store each node address into a map with value 1
     * Now, while traversing the linked-list, if we found that
     * the node was already present in the map, it means the
     * linked-list contains cycle, so return true.
     * If the loop ends, it means that there was no cycle,
     * hence return false
     * 
     * Time complexity : O(n)
     * Space complexity : O(n)
     * [ n is the length of linked-list ]
     */ 
    
    if(head == NULL)
            return false;
        
    unordered_map<ListNode*, int> mp;
    
    while(head)
    {
        if(mp.find(head) == mp.end())
        {
            mp[head]++;
            head = head->next;
        }
        else
            return true;
    }
    return false;
    
}



// main function - driver code
int main()
{
    
    // TESTCASES
    
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	l1->next->next->next = l1->next;
	cout<<hasCycle(l1)<<"\n";
	l1 = nullptr;
	
	l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	cout<<hasCycle(l1)<<"\n";
	l1 = nullptr;
	
    l1 = new ListNode(1);
	l1->next = l1;
	cout<<hasCycle(l1)<<"\n";
	
	return 0;
}
