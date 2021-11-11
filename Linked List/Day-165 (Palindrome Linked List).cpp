/**
 * Given a reference to a linked list, return whether or not it forms a palindrome.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since November 11, 2021
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



/** function isPalindrome
 * @param ListNode*, denoting the head of the linked-list
 * @return bool, whether or not linked-list forms a palindrome digit
 */ 
bool isPalindrome(ListNode* head) 
{
    if(head==NULL || head->next==NULL)
        return true;
    
    vector<int> v;
    while(head)
    {
        v.push_back(head->val);
        head = head->next;
    }
    
    vector<int> vv = v;
    reverse(v.begin(), v.end());
    
    if(v == vv)
        return true;
    return false;
}

 
 
// main function - driver code
int main()
{
	
	// TESTCASES
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(3);
	head->next->next = new ListNode(1);
	cout<<isPalindrome(head)<<"\n";
	
	
	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(1);
	cout<<isPalindrome(head)<<"\n";
	
	
	head = new ListNode(1);
	head->next = new ListNode(2);
	cout<<isPalindrome(head)<<"\n";
	
	
	return 0;
}
