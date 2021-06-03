/**
 * Google
 * Given a linked list and a value, 
 * remove all nodes containing the provided value, and return the resulting list.
 */

#include<iostream>
#include<vector>
#include<algorithm>
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



/** function remove_elements_using_vector
 * @param ListNode*, denoting the head of linked-list
 * @param int, denoting the value we need to remove from linked-list
 * @return ListNode*, denoting the modified linked-list
 */ 
ListNode* remove_elements_using_vector(ListNode* head, int val)
{
    
    /** Logic :
     * We store each value of linked-list into a vector
     * then, by using pre-defined functions (erase and remove),
     * we delete all occurrences of 'val' from this vector.
     * Then, again store this vector into linked-list (this is
     * our answer) and return it.
     * 
     * Time complexity : O(n)
     * Space complexity : O(n)
     * where n is size of linked-list
     */ 
    
	if(head == NULL)
        return head;
    
    vector<int> v;
    while(head)
    {
        v.push_back(head->val);
        head = head->next;
    }
    v.erase(remove(v.begin(), v.end(), val), v.end());
    
    if(v.size() == 0)
        return NULL;
    
    ListNode* ans = new ListNode(v[0]);
    ListNode* temp = ans;
    for(int i=1;i<v.size();i++)
    {
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }
    return ans;
}



/** function remove_elements_using_vector
 * @param ListNode*, denoting the head of linked-list
 * @param int, denoting the value we need to remove from linked-list
 * @return ListNode*, denoting the modified linked-list
 */ 
ListNode* remove_elements(ListNode* head, int val)
{
    
    /** Logic :
     * We take current head position and check if its next node's
     * value is equal to 'val', if it is so, we skip this node by
     * changing the appropriate 'next' pointer
     * 
     * Time complexity : O(n)
     * Space complexity : O(1)
     */ 
    
    
    while(head && head->val==val)
        head = head->next;
    
    if(head == NULL)
        return NULL;
    
    ListNode* temp = head;
    
    while(temp->next != NULL)
    {
        if(temp->next->val==val)
            temp->next = temp->next->next;
        else
            temp = temp->next;
    }
    
    return head;
}



// main function - driver code
int main()
{
    
	// TESTCASE - 1
	
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	ListNode* ans = remove_elements_using_vector(l1, 3);
	display_list(ans);
	
	ans = remove_elements(l1, 3);
	display_list(ans);
	l1 = nullptr;
	ans = nullptr;
	
	
	// TESTCASE - 2
	
	cout<<"\n";
	l1 = new ListNode(8);
	l1->next = new ListNode(1);
	l1->next->next = new ListNode(1);
	l1->next->next->next = new ListNode(4);
	l1->next->next->next->next = new ListNode(12);
	ans = remove_elements_using_vector(l1, 1);
	display_list(ans);
	
	ans = remove_elements(l1, 1);
	display_list(ans);
	l1 = nullptr;
	ans = nullptr;
	
	
	// TESTCASE - 3
	
	cout<<"\n";
	l1 = new ListNode(7);
	l1->next = new ListNode(12);
	l1->next->next = new ListNode(2);
	l1->next->next->next = new ListNode(9);
	ans = remove_elements_using_vector(l1, 7);
	display_list(ans);
	
	ans = remove_elements(l1, 7);
	display_list(ans);
	
	return 0;
}
