/**
 * Given the reference to a binary search tree, return the kth smallest value in the tree.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since October 3, 2021
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
 * @param TreeNode*, root of (current) BST
 * @param vector<int>, to store inorder-traversal of BST
 */ 
void inorder(TreeNode* root, vector<int> &v)
{
    if(root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}



/** function kthSmallest
 * @param TreeNode*, root of BST
 * @param int, value of k
 * @return int, kth smallest element from tree
 */ 
int kthSmallest(TreeNode* root, int k) 
{
    vector<int> v;
    inorder(root, v);
    
    return v[k-1];
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(2);
	root->right = new TreeNode(4);
	cout<<kthSmallest(root, 1)<<"\n";
	
	root = new TreeNode(7);
	root->left = new TreeNode(3);
	root->right = new TreeNode(9);
	root->left->right = new TreeNode(5);
	cout<<kthSmallest(root, 3)<<"\n";
	
	return 0;
}
