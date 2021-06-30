/**
 * Given a binary tree, return its maximum depth.
 * The maximum depth is defined as the number of nodes along the longest path 
 * from root node to leaf node.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since June 30, 2021
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



/** function maxDepth
 * @param TreeNode*, denoting the root of this binary tree
 * @return int, denoting the maximum depth of the binary tree
 */ 
int maxDepth(TreeNode* root) 
{
    
    /** Logic :
     * 
     * If root is null, it means no tree exist at all, so return 0
     * 
     * Else, the depth will be computed either on left subtree or the right subtree, hence make
     * recursive calls on left and right subtree after adding 1 (to consider current node in the
     * maximum depth)
     * 
     * Time complexity  : O(N) -- Entire tree is traversed
     * Space complexity : O(N) -- for recursive stack
     *
     */ 
    
    if(root == NULL)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
    
}



// main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	TreeNode* root = new TreeNode(9);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	cout<<maxDepth(root)<<"\n";
	root = nullptr;
	
	
	// TESTCASE - 2
	
	root = new TreeNode(5);
	root->left = new TreeNode(1);
	root->right = new TreeNode(29);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(13);
	cout<<maxDepth(root)<<"\n";
	
	
	return 0;
}
