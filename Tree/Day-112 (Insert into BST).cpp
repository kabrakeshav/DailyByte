/** 
 * Given the reference to a binary search tree and a value to insert, return a reference to the root 
 * of the tree after the value has been inserted in a position that adheres to the invariants of a 
 * binary search tree.
 * Note: It is guaranteed that each value in the tree, including the value to be inserted, is unique.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since September 16, 2021
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
 * @param TreeNode*, root of BST
 * @param int, value to be inserted
 */ 
void get_answer(TreeNode* root, int val)
{
    
    /** Logic :
     * 
     * Make recursive calls to appropriate left and right parts of the BST by comparing the value to be inserted
     * with the current node's value
     */ 
    
    if(root->val > val)
    {
        if(root->left)
            get_answer(root->left, val);
        else
        {
            root->left = new TreeNode(val);
            return;
        }
    }
    
    if(root->val < val)
    {
        if(root->right)
            get_answer(root->right, val);
        else
        {
            root->right = new TreeNode(val);
            return;
        }
    }
}



/** function insertIntoBST
 * @param TreeNode*, root of BST
 * @param int, value to be inserted
 * @return TreeNode*, new root of BST after insertion
 */ 
TreeNode* insertIntoBST(TreeNode* root, int val) 
{
    if(root == NULL)
        return new TreeNode(val);
    
    get_answer(root, val);
    
    return root;
} 
 
 

/** function print_inorder
 * @param TreeNode*, root of BST
 * prints inorder traversal of BST
 */ 
void print_inorder(TreeNode* root) 
{
	if(root == NULL)
		return;
	print_inorder(root->left);
	cout<<root->val<<" ";
	print_inorder(root->right);
}
 
 
 
// main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	TreeNode* new_root = insertIntoBST(root, 4);
	print_inorder(new_root);
	
	
	// TESTCASE - 2
	
	cout<<"\n";
	root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	new_root = insertIntoBST(root, 5);
	print_inorder(new_root);
	
	return 0;
}
