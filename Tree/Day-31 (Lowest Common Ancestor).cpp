/**
 * Given a binary search tree that contains unique values and two nodes within the tree, a, and b, 
 * return their lowest common ancestor. The lowest common ancestor of 
 * two nodes is the deepest node within the tree such that both nodes are descendants of it.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since June 17, 2021
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



/** function lowestCommonAncestor
 * @param TreeNode*, denoting the root of the BST
 * @param TreeNode*, denoting the TreeNode 'a'
 * @param TreeNode*, denoting the TreeNode 'b'
 * @return TreeNode*, denoting the lowest common ancestor
 */ 
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) 
{
    
    /** Logic :
     * 
     * If root is null, it means the tree (or subtree) is empty and hence return null referrence.
     * 
     * Else if a's value and b'value are both less than root's value, it means the lowest-common-ancestor
     * must be in left part of BST, so make recusrsive call on root->left.
     * 
     * Else if a's value and b'value are both greater than root's value, it means the lowest-common-ancestor
     * must be in right part of BST, so make recusrsive call on root->left.
     * 
     * Else the values of a and b are equal to root, hence return root's referrence.
     * 
     * Time complexity  : O(N) -- In worst case, we have to traverse entire BST
     * Space complexity : O(N) -- Recusrsion stack will be of size N if it is skewed tree (worst-case)
     */ 
    
    if(root == NULL)
        return NULL;
    
    if(a->val < root->val  &&  b->val < root->val)
        return lowestCommonAncestor(root->left, a, b);
    
    if(a->val > root->val  && b->val > root->val)
        return lowestCommonAncestor(root->right, a, b);
    
    return root;
}



// main function - driver code
int main()
{
	
	// TESTCASE - 1
	TreeNode* root = new TreeNode(7);
	root->left = new TreeNode(2);
	root->right = new TreeNode(9);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(5);
	TreeNode* ans = lowestCommonAncestor(root, root->left->left, root->right);
	cout<<"Value: "<<ans->val<<"\n";
	root = nullptr;
	ans = nullptr;
	
	
	// TESTCASE - 2
	root = new TreeNode(8);
	root->left = new TreeNode(3);
	root->right = new TreeNode(9);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(6);
	ans = lowestCommonAncestor(root, root->left->left, root->left->right);
	cout<<"Value: "<<ans->val<<"\n";
	root = nullptr;
	ans = nullptr;
	
	
	// TESTCASE - 3
	root = new TreeNode(8);
	root->left = new TreeNode(6);
	root->right = new TreeNode(9);
	ans = lowestCommonAncestor(root, root->left, root);
	cout<<"Value: "<<ans->val<<"\n";
	
	
	return 0;
}
