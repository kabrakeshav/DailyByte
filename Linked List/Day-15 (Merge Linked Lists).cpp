/**
  * Apple
  * Given two sorted linked lists, merge them together in 
  * ascending order and return a reference to the merged list
  */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * @author keshav kabra
 * @since June 1, 2021
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
 


/** function merge_lists_using_vector
 * @param ListNode*, denoting first linked-list
 * @param ListNode*, denoting second linked-list
 * @param ListNode*, denoting mearged linked-list
 */ 
ListNode* merge_lists_using_vector(ListNode* l1, ListNode* l2) 
{
    
    /** Logic :
     * We store the values of linked-list nodes into a vector
     * We sort the vector and create a new linked-list with
     * the sorted values.
     * Hence, the linked-lists are merged.
     */ 
    
    vector<int> v;
    while(l1)
    {
        v.push_back(l1->val);
        l1 = l1->next;
    }
    while(l2)
    {
        v.push_back(l2->val);
        l2 = l2->next;
    }
    
    if(v.empty())
        return NULL;
    
    sort(v.begin(), v.end());
    
    ListNode* l = new ListNode(v[0]);
    ListNode* ans = l;
    for(int i=1;i<v.size();i++)
    {
        l->next = new ListNode(v[i]);
        l = l->next;
    }
    return ans;
}



/** function merge_lists
 * @param ListNode*, denoting first linked-list
 * @param ListNode*, denoting second linked-list
 * @param ListNode*, denoting mearged linked-list
 */ 
ListNode* merge_lists(ListNode* l1, ListNode* l2)
{
    
    /** Logic :
     * We create a new ListNode pointer to store the merged list
     * Now, we iterate through each list and whose node value is smaller,
     * We add that node to the answer list and make appropriate pointer
     * increment by 1.
     * One any one of the passed linked-lists are ended, we simple need
     * to add all nodes of remaining list into answer linked-list.
     * At last, we return this answer linked-list
     */ 
    
    ListNode* ans = nullptr;
    ListNode *temp;
    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            if(ans == nullptr) {
                ans = new ListNode(l1->val);
                temp = ans;
            }
            else {
                temp->next = new ListNode(l1->val);
                temp = temp->next;
            }
            l1 = l1->next;
        }
        else 
        {
            if(ans == nullptr) {
                ans = new ListNode(l2->val);
                temp = ans;
            }
            else {
                temp->next = new ListNode(l2->val);
                temp = temp->next;
            }
            l2 = l2->next;
        }
    }
    
    while(l1)
    {
        if(ans == nullptr) {
            ans = new ListNode(l1->val);
            temp = ans;
        }
        else {
            temp->next = new ListNode(l1->val);
            temp = temp->next;
        }
        l1 = l1->next;
    }
    
    while(l2)
    {
        if(ans == nullptr) {
            ans = new ListNode(l2->val);
            temp = ans;
        }
        else {
            temp->next = new ListNode(l2->val);
            temp = temp->next;
        }
        l2 = l2->next;
    }
    
    return ans;
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
    
    // TESTCASE 1
    
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	
	ListNode* l2 = new ListNode(4);
	l2->next = new ListNode(5);
	l2->next->next = new ListNode(6);
	
	ListNode* ans1 = merge_lists_using_vector(l1, l2);
	display_list(ans1);
	ListNode* ans2 = merge_lists(l1, l2);
	display_list(ans2);
	l1 = nullptr;
	l2 = nullptr;
	ans1 = ans2 = nullptr;
	
	
	// TESTCASE 2
	
	l1 = new ListNode(1);
	l1->next = new ListNode(3);
	l1->next->next = new ListNode(5);
	
	l2 = new ListNode(2);
	l2->next = new ListNode(4);
	l2->next->next = new ListNode(6);
	
	ans1 = merge_lists_using_vector(l1, l2);
	display_list(ans1);
	ans2 = merge_lists(l1, l2);
	display_list(ans2);
	l1 = nullptr;
	l2 = nullptr;
	ans1 = ans2 = nullptr;
	
	
	// TESTCASE 3
	
	l1 = new ListNode(4);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(7);
	
	l2 = new ListNode(1);
	l2->next = new ListNode(5);
	l2->next->next = new ListNode(6);
	
	ans1 = merge_lists_using_vector(l1, l2);
	display_list(ans1);
	ans2 = merge_lists(l1, l2);
	display_list(ans2);
	
	return 0;
}
