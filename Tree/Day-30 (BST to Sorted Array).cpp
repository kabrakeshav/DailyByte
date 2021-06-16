/**
 * Given a binary search tree, rearrange the tree such that 
 * it forms a list where all its values are in ascending order.
 */
 
#include<iostream>
#include<vector>
using namespace std;

/**
 * @author keshav kabra
 * @since June 16, 2021
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



/** function increasingBST
 * @param TreeNode*, denoting the root of current BST
 * @param vector, denoting the array in which sorted tree will be stored
 */ 
void increasingBST(TreeNode* root, vector<int> &v)
{
    
    /** Logic :
     * 
     * Inorder traversal (left -> root -> right) of a BST is always sorted. Hence we will do inorder
     * traversal and whenever got the leaf node, we will push it into the vector (passed with
     * reference) 
     * else, make recursive calls appropriately
     * 
     * Time complexity  : O(N) -- Entire tree is traversed
     * Space complexity : O(N) -- Vector is used to store the values of BST nodes
     */ 
    
	if(root == NULL)
		return;
	
	if(root->left==NULL && root->right==NULL)
		v.push_back(root->val);
	
	else
	{
		increasingBST(root->left, v);
		v.push_back(root->val);
		increasingBST(root->right, v);
	}
}



/**  function print_array
 * @param vector, denoting the array to be dsplayed
 * Displays the array on the console
 */ 
void print_array(vector<int> v)
{
	for(int i : v)
		cout<<i<<" ";
	cout<<"\n";
}



// main function - driver code
int main()
{
    
	vector<int> v;
	
	
	// TESTCASE - 1
	
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(1);
	root->right = new TreeNode(6);
	increasingBST(root, v);
	print_array(v);
	root = nullptr;
	v.clear();
	
	
	// TESTCASE - 2
	
	root = new TreeNode(5);
	root->left = new TreeNode(2);
	root->right = new TreeNode(9);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	increasingBST(root, v);
	print_array(v);
	root = nullptr;
	v.clear();
	
	
	// TESTCASE - 3
	
	root = new TreeNode(5);
	root->right = new TreeNode(6);
	increasingBST(root, v);
	print_array(v);
	
	
	return 0;
}
