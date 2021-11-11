/**
 * Given a binary tree, count the total number of nodes it contains.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since November 11, 2021
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



/** function countNodes
 * @param TreeNode*, denoting the root of binary tree
 * @return int, number of nodes in binary tree
 */ 
int countNodes(TreeNode* root) 
{
    if(root == NULL)
        return 0;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	cout<<countNodes(root)<<"\n";
	
	
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	cout<<countNodes(root)<<"\n";
	
	
	return 0;
}
