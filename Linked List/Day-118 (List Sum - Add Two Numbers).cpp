/**
 * Given two linked lists that represent two numbers, return the sum of the numbers also represented 
 * as a list.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since September 27, 2021
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


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    vector<int> v1, v2;
    
    ListNode* temp = l1;
    while(temp)
    {
        v1.push_back(temp->val);
        temp = temp->next;
    }
    
    temp = l2;
    while(temp)
    {
        v2.push_back(temp->val);
        temp = temp->next;
    }
    
    
    vector<int> ans;
    int carry = 0;
    
    
    while(v1.size()>0 && v2.size()>0)
    {
        int sum = carry + v1[0] + v2[0];
        if(sum > 9) {
            sum = sum % 10;
            carry = 1;
        } else
            carry = 0;
        ans.push_back(sum);
        v1.erase(v1.begin());
        v2.erase(v2.begin());
        
        if(v1.size()==0 && v2.size()==0 && carry>0)
            ans.push_back(carry);
    }
    
    while(v1.size() > 0)
    {
        int sum = carry + v1[0];
        if(sum > 9) {
            sum = sum % 10;
            carry = 1;
        } else
            carry = 0;
        ans.push_back(sum);
        v1.erase(v1.begin());
        
        if(v1.size()==0 && carry>0)
            ans.push_back(carry);
    }
    
    
    while(v2.size() > 0)
    {
        int sum = carry + v2[0];
        if(sum > 9) {
            sum = sum % 10;
            carry = 1;
        } else
            carry = 0;
        ans.push_back(sum);
        v2.erase(v2.begin());
        
        if(v2.size()==0 && carry>0)
            ans.push_back(carry);
    }
    
    
    ListNode* ls = new ListNode(ans[0]);
    temp = ls;
    for(int i=1;i<ans.size();i++)
    {
        temp->next = new ListNode(ans[i]);
        temp = temp->next;
    }
    
    return ls;
}

// main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	
	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(3);
	
	ListNode* ans = addTwoNumbers(l1, l2);
	display_list(ans);
	
	/**
 * Given two linked lists that represent two numbers, return the sum of the numbers also represented 
 * as a list.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since September 27, 2021
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



/** function addTwoNumbers
 * @param ListNode*, head of first list
 * @param ListNode*, head of second list
 * @return ListNode*, head of list obtained by adding the two given lists
 */ 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    
    // storing the values of both linked-lists in vectors
    
    vector<int> v1, v2;
    
    ListNode* temp = l1;
    while(temp)
    {
        v1.push_back(temp->val);
        temp = temp->next;
    }
    
    temp = l2;
    while(temp)
    {
        v2.push_back(temp->val);
        temp = temp->next;
    }
    
    // iterate on vectors to get sum
    // variable 'carry' is used to remember carry obtained from previous sum
    
    vector<int> ans;
    int carry = 0;
    
    while(v1.size()>0 && v2.size()>0)
    {
        int sum = carry + v1[0] + v2[0];
        if(sum > 9) {
            sum = sum % 10;
            carry = 1;
        } else
            carry = 0;
        ans.push_back(sum);
        v1.erase(v1.begin());
        v2.erase(v2.begin());
        
        if(v1.size()==0 && v2.size()==0 && carry>0)
            ans.push_back(carry);
    }
    
    while(v1.size() > 0)
    {
        int sum = carry + v1[0];
        if(sum > 9) {
            sum = sum % 10;
            carry = 1;
        } else
            carry = 0;
        ans.push_back(sum);
        v1.erase(v1.begin());
        
        if(v1.size()==0 && carry>0)
            ans.push_back(carry);
    }
    
    
    while(v2.size() > 0)
    {
        int sum = carry + v2[0];
        if(sum > 9) {
            sum = sum % 10;
            carry = 1;
        } else
            carry = 0;
        ans.push_back(sum);
        v2.erase(v2.begin());
        
        if(v2.size()==0 && carry>0)
            ans.push_back(carry);
    }
    
    
    // making answer list and returing it
    
    ListNode* ls = new ListNode(ans[0]);
    temp = ls;
    for(int i=1;i<ans.size();i++)
    {
        temp->next = new ListNode(ans[i]);
        temp = temp->next;
    }
    
    return ls;
}



// main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	
	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(3);
	
	ListNode* ans = addTwoNumbers(l1, l2);
	display_list(ans);
	
	
	// TESTCASE - 2
	
	l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	
	l2 = new ListNode(1);
	l2->next = new ListNode(8);
	
	ans = addTwoNumbers(l1, l2);
	display_list(ans);
	
	
	return 0;
}
	// TESTCASE - 2
	
	l1 = new ListNode(1);
	l1->next = new ListNode(9);
	
	l2 = new ListNode(1);
	
	ans = addTwoNumbers(l1, l2);
	display_list(ans);
	
	
	return 0;
}
