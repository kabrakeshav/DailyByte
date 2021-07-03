/** 
 * Given a binary tree, containing unique values, determine if it is a valid binary search tree.
 */

#include<iostream>
#include<vector>
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



/** function inorder
 * @param TreeNode*, denoting the root of the tree
 * @param vector<int>, array to store inorder traversal of tree
 *     (passed with reference)
 * 
 * Performs inorder traversal on the tree
 * 
 */ 
void inorder(TreeNode* root, vector<int> &v)
{
    if(root == NULL)
        return;
    
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}



/** function isValidBST
 * @param TreeNode*, denoting the root of the binary tree
 * @return bool, denoting whether binary tree is BST or not
 */ 
bool isValidBST(TreeNode* root) 
{
    
    /** Logic :
     * 
     * The inorder traversal of a BST is always sorted in ascending order. Hence we will do the inorder traversal
     * of this tree and check if it is sorted.
     * If it is sorted, it iis BST, hence return true; else return false.
     * 
     * Time complexity  : O(N) -- entire tree is traversed
     * Space complexity : O(N) -- for recursion and vectors
     * 
     */ 
    
    if(root == NULL)
        return true;
    
    vector<int> v;
    inorder(root, v);
    
    for(int i=1;i<v.size();i++)
    {
        if(v[i] <= v[i-1])
            return false;
    }
    return true;
    
}



// main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	cout<<isValidBST(root)<<"\n";
	root = nullptr;
	
	
	// TESTCASE - 2
	
	root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	cout<<isValidBST(root)<<"\n";
	
	
	return 0;
}
