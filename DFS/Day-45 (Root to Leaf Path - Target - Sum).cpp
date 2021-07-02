/**
 * Given a binary tree and a target, return whether or not 
 * there exists a root to leaf path 
 * such that all values along the path sum to the target.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since July 2, 2021
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



/** function hasPathSum
 * @param TreeNode*, denoting the root of this binary tree
 * @param int, denoting the sum we need to find in any root to leaf path
 * @return bool, denoting whether we have found the sum or not
 */ 
bool hasPathSum(TreeNode* root, int sum) 
{
    
    /** Logic :
     * 
     * If root is null, there exists no binary tree, hence return false
     * 
     * We will make recursive calls on the left and right subtrees by subtracting the current node's
     * val from the target-sum. Thus, considering every root to leaf path.
     * Now if root's left and right is null, it means this is a leaf node, hence if the sum is equal to
     * root's val, return true.
     * 
     * Time complexity  : O(N) - entire tree is parsed
     * Space complexity : O(N) - for recursive stack
     *
     */ 
    
    if(root == NULL)
        return false;
    
    if(root->left==NULL && root->right==NULL && root->val==sum)
        return true;
    
    return (hasPathSum(root->left, sum-root->val) || 
        		(hasPathSum(root->right, sum-root->val))
		   );
}



// main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(5);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->right->left = new TreeNode(12);
	root->right->right = new TreeNode(29);
	cout<<hasPathSum(root, 15)<<"\n";
	root = nullptr;
	
	
	// TESTCASE - 2
	
	root = new TreeNode(104);
	root->left = new TreeNode(39);
	root->right = new TreeNode(31);
	root->left->left = new TreeNode(32);
	root->left->right = new TreeNode(1);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(10);
	cout<<hasPathSum(root, 175)<<"\n";
	
	
	return 0;
}
