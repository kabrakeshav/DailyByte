/**
 * Given the reference to the root of a binary search tree and a target value, return whether or not 
 * two individual values within the tree can sum to the target.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since October 16, 2021
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
 * @param vector<int>, to store the inorder-traversal of BST
 */ 
void inorder(TreeNode* root, vector<int> &v)
{
    if(root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}



/** function findTarget
 * @param TreeNode*, root of BST
 * @param int, denoting the value to sum we need to find
 * @return bool, whether or not two individual nodes of BST adds upto 'k'
 */ 
bool findTarget(TreeNode* root, int k)
{
    
    /** Logic :
     * 
     * Find inorder traversal of BST - which will always be sorted
     * Now apply binary search for finding whether given sum-pair is present or not
     * 
     */ 
    
    if(root == NULL)
        return false;
    
    vector<int> v;
    inorder(root, v);
    
    int l = 0;
    int r = v.size()-1;
    
    while(l < r)
    {
        int s = v[l]+v[r];
        if(s == k)
            return true;
        if(s > k)
            r--;
        else
            l++;
    }
    
    return false;
}




// main function - driver code
int main()
{
	
	// TESTCASES
	
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	cout<<findTarget(root, 4)<<"\n";
	
	
	root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(7);
	cout<<findTarget(root, 28)<<"\n";
	
	return 0;
}
