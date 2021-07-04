/**
 * Given a binary tree, return whether or not it forms a reflection across its center 
 * (i.e. a line drawn straight down starting from the root).
 * Note: a reflection is when an image, flipped across a specified line, forms the same image.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since July 4, 2021
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
 * @param TreeNode*, denoting the left-part of this binary tree
 * @param TreeNode*, denoting the right-part of this binary tree
 * @return bool, if left and right parts of binary tree are symmetric
 */ 
bool get_answer(TreeNode* lef, TreeNode* rig)
{
    
    /** Logic :
     * 
     * If either left or right parts is null, the other part must be null in order to for tree 
     * to be symmetric.
     * 
     * If both left and right parts are non-null, their respective values must be equal.
     * 
     * Now, we will make the recursive calls on subtree parts - 
     * As we are checking with symmetric-reflection, we have to check symmetric-subtree of left
     * part with right part and vice-versa. Hence, the appropriate recursive calls.
     * 
     */ 
    
    // if any one node is null, check if other is null as well
    if(lef==NULL || rig==NULL)
        return lef==rig;
    
    // values of nodes must be same
    if(lef->val != rig->val)
        return false;
    
    // recursive calls to left subtree with right subtree 
    // and right subtree with left subtree
    return get_answer(lef->left, rig->right) && get_answer(lef->right, rig->left);
}



/** function isSymmetric
 * @param TreeNode*, denoting the root of the binary tree
 * @return bool, whether tree is symmetric or not
 */ 
bool isSymmetric(TreeNode* root) 
{
    
    /** 
     * 
     * Time complexity  : O(N) - entire tree is traversed
     * Space complexity : O(N) - for recursive stack
     *
     */ 
    
    // if root is null, return true
    if(root == NULL)
        return true;
    
    // recursive function to check if tree is symmetric or not
    return get_answer(root->left, root->right);
    
}



// main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(1);
	cout<<isSymmetric(root)<<"\n";
	root = nullptr;
	
	
	// TESTCASE - 2
	
	root = new TreeNode(1);
	root->left = new TreeNode(5);
	root->right = new TreeNode(5);
	root->left->right = new TreeNode(7);
	root->right->right = new TreeNode(7);
	cout<<isSymmetric(root)<<"\n";
	
	
	return 0;
}
