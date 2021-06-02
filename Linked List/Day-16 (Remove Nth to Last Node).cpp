/**
 * Facebook
 * Given a linked list and a value n, remove the nth to last node and 
 * return the resulting list.
 */

#include<iostream>
#include<vector>
using namespace std;

/**
 * @author keshav kabra
 * @since June 2, 2021
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
 
 

/** functon removeNthFromEnd_using_vector
 * @param ListNode*, denoting head of linked-list
 * @param int, denoting the nth node number from last we need to remove
 * @return ListNode*, denoting the linked-list after removing nth nodde from last
 */ 
ListNode* removeNthFromEnd_using_vector(ListNode* head, int n)
{
	if(head==NULL || head->next==NULL)
        return NULL;
        
    /** Logic :
     * We store the entire linked-list into a vector
     * Then from this vector we can easily delete the nth last term
     * After removing, store the vector back into linked-list
     * and return this modified linked-list
     */ 
    
    vector<int> v;
    while(head)
    {
        v.push_back(head->val);
        head = head->next;
    }
    v.erase(v.end()-n);
    
    ListNode* temp = new ListNode(v[0]);
    ListNode* ans = temp;
    for(int i=1;i<v.size();i++)
    {
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }
    return ans;
}



/** function removeNthFromEnd
 * @param ListNode*, denoting head of linked-list
 * @param int, denoting the nth node number from last we need to remove
 * @return ListNode*, denoting the linked-list after removing nth nodde from last
 */ 
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(head == NULL)
        return NULL;
        
    /** Logic :
     * We start with two pointers, first and second.
     * At first, increment 'first' by n times. This will make
     * 'first' ahead of 'second' by exactly n nodes.
     * 
     * Now, if 'first' is NULL, it means n is greater than list size by 1, 
     * hence return head->next.
     * 
     * Else, maintain the gap of exactly n nodes between 'first' and 'second'
     * till 'first' not becomes NULL (in loop)
     * After the loop, 'second' will be pointing to (n-1)th node from last, 
     * hence, modify its 'next' pointer address of one node ahead.
     * Return the modified head.
     */ 
    
    ListNode* first = head;
    ListNode* second = head;
    
    for(int i=0;i<n;i++)
        first = first->next;
    
    if(first == NULL)
        return head->next;
    
    while(first->next != NULL)
    {
        first = first->next;
        second = second->next;
    }
    
    second->next = second->next->next;
    return head;
}



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
 
 
// main function - driver code 
int main()
{
    
	// TESTCASE - 1
	
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	ListNode* ans = removeNthFromEnd_using_vector(l1, 1);
	display_list(ans);
	
	ans = removeNthFromEnd(l1, 1);
	display_list(ans);
	l1 = nullptr;
	ans = nullptr;
	
	
	// TESTCASE - 2
	
	cout<<"\n";
	l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	ans = removeNthFromEnd_using_vector(l1, 2);
	display_list(ans);
	
	ans = removeNthFromEnd(l1, 2);
	display_list(ans);
	l1 = nullptr;
	ans = nullptr;
	
	
	// TESTCASE - 3
	
	cout<<"\n";
	l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	ans = removeNthFromEnd_using_vector(l1, 3);
	display_list(ans);
	ans = removeNthFromEnd(l1, 3);
	display_list(ans);
	
	return 0;
}

