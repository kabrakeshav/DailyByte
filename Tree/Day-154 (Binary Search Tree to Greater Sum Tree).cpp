/**
 * Given the reference to a binary search tree, “level-up” the tree. 
 * Leveling-up the tree consists of modifying every node in the tree such that every node’s value 
 * increases by the sum of all the node’s values that are larger than it.
 * Note: The tree will only contain unique values and you may assume that it is a valid binary search tree.
 */

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;


/**
 * @author keshav kabra
 * @since November 8, 2021
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
 * @param TreeNode*, root of BST
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



/** function modify
 * @param TreeNode*, root of BST
 * @param vector<int>, storing the inorder traversal of BST
 * @param int, current root's index in inorder_traversal array 
 */ 
void modify(TreeNode* root, vector<int> &v, int &ind)
{
    if(root == NULL)
        return;
    
    modify(root->left, v, ind);
    
    root->val = accumulate(v.begin()+ind+1, v.end(), root->val);
    ind++;
    
    modify(root->right, v, ind);
}



/** function bstToGst
 * @param TreeNode*, root of BST
 * @return TreeNode*, root of newly created GST
 */ 
TreeNode* bstToGst(TreeNode* root)
{
    
    /** Logic :
     * 
     * Store inorder-traversal of BST in vector - which is always sorted. Now, in 'modify' function, make
     * root's current value to sum of all values that are ahead of it in the inorder-traversal array.
     *
     */ 
    
    if(root == NULL)
        return root;
    
    vector<int> v;
    inorder(root, v);
    
    int ind = 0;
    modify(root, v, ind);
    
    return root;
    
}



/** function print_inorder_traversal
 * @param TreeNode*, denoting the root of BST
 * displays the inorder traversal of BST on console
 */ 
void print_inorder_traversal(TreeNode* root)
{
    if(root == NULL)
        return;
    
    print_inorder_traversal(root->left);
    cout<<root->val<<" ";
    print_inorder_traversal(root->right);
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(3);
	TreeNode* new_root = bstToGst(root);
	print_inorder_traversal(new_root);
	cout<<"\n";
	
	root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	new_root = bstToGst(root);
	print_inorder_traversal(new_root);
	
	return 0;
}
