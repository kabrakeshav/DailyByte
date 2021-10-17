/**
 * Given the reference to a binary tree, return the length of the longest path in the tree that 
 * contains consecutive values.
 * Note: The path must move downward in the tree.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since October 16, 2021
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



/** function get_answer
 * @param TreeNode*, denoting the root of the binary tree
 * @param int, denoting the count of current consecutive integers of tree
 * @param int, denoting the target element (of node) in the next recursive call
 * @param int, to store the answer (longest consecutive path)
 */ 
void get_answer(TreeNode* root, int cnt, int target, int &ans)
{
	if(root == NULL)
		return;
	if(root->val == target)
		cnt++;
	else
		cnt = 1;
	
	ans = max(ans, cnt);
	get_answer(root->left, cnt, root->val+1, ans);
	get_answer(root->right, cnt, root->val+1, ans);
}



/** function longestConsecutive
 * @param TreeNode*, denoting the root of the binary tree
 * @return int, the longest consecutive path of integers in the tree (downward direction)
 */ 
int longestConsecutive(TreeNode* root)
{
	int ans = 0;
	get_answer(root, 0, 0, ans);
	return ans;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(3);
	cout<<longestConsecutive(root)<<"\n";
	
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(8);
	root->left->right->left = new TreeNode(4);
	cout<<longestConsecutive(root)<<"\n";
	
	
	return 0;
}
