/**
 * Given a binary tree, return the sum of all LEFT leaves of the tree.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since July 6, 2021
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



/** function get_sum
 * @param TreeNode*, denoting the root of this binary tree
 * @param int, variable to store the sum of all left leaves
 *   ( passed with reference )
 */ 
void get_sum(TreeNode* root, int &sum)
{
    
    /** Logic :
     * 
     * If root is null, it means no binary tree exists, so simply return
     * 
     * Else, if we have a left child of current node and that left child's left and right children are null,
     * it means we have found a left leaf of binary tree. Add it to sum variable.
     * 
     * Make recursive calls to left and right sub-trees
     * 
     */ 
    
    if(root==NULL)
        return;
    if(root->left && root->left->left==NULL && root->left->right==NULL)
        sum += root->left->val;
    get_sum(root->left, sum);
    get_sum(root->right, sum);
    
}



/** function sumOfLeftLeaves
 * @param TreeNode*, denoting the root of the binary tree
 * @return int, denoting the sum of all leaf leaves of binary tree
 */ 
int sumOfLeftLeaves(TreeNode* root) 
{   
    
    /** Logic :
     * 
     * If root is null, return 0
     * 
     * Else, we call a recursive function get_sum to get the sum of all left leaves
     * 
     * 
     * Time complexity  : O(N) -- entire tree is traversed
     * Space complexity : O(N) -- for recursive stack
     * 
     */
     
    if(root==NULL)
        return 0;
        
    int sum = 0;
    get_sum(root, sum);
    return sum;
    
}



//main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(2);
	root->right = new TreeNode(12);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(8);
	cout<<sumOfLeftLeaves(root)<<"\n";
	root = nullptr;
	
	
	// TESTCASE - 2
	
	root = new TreeNode(2);
	root->left = new TreeNode(4);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(9);
	cout<<sumOfLeftLeaves(root)<<"\n";
	
	
	return 0;
}
