/**
 * Given a binary tree, return a list containing its inorder traversal without using recursion.
 *
 */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


/**
 * @author keshav kabra
 * @since August 17, 2021
 */



/** struct TreeNode
 * To make individual node of a tree
 */ 
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



/** function inorder
 * @param TreeNode*, denoting the root of the binary tree
 * @return vector<int>, inorder traversal of the binary tree
 */ 
vector<int> inorder(TreeNode* root)
{
    
    // to store answer - inorder traversal
	vector<int> ans;
	
	stack<TreeNode*> stk;
	TreeNode* curr = root;
	
	
	while(curr!=NULL || stk.empty()==false)
	{
	    
	    // reach to left-most node of curr pointer
		while(curr != NULL)
		{
			stk.push(curr);
			curr = curr->left;
		}
		
		
		// taking the root element out of stack and pusing its value to answer vector
		curr = stk.top();
		stk.pop();
		
		ans.push_back(curr->val);
		
		
		// going to right sub-tree
		curr = curr->right;
	}
	
	return ans;
}



/** function display_answer
 * @param vector, denoting the array
 * prints the given array on the console
 */ 
void display_answer(vector<int> v)
{
    for(int i : v)
        cout<<i<<" ";
    cout<<"\n";
}



// main function - driver code
int main()
{
	
	vector<int> ans;
	
	// TESTCASE - 1
	
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	ans = inorder(root);
	display_answer(ans);
	ans.clear();
	root = nullptr;
	
	
	// TESTCASE - 2
	
	root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(8);
	ans = inorder(root);
	display_answer(ans);
	
	
	return 0;
}0
