/**
 * Google
 * Given the reference to the root of a binary search tree and a search value, 
 * return the reference to the node that contains the value if it exists and null otherwise.
 */
 
#include<iostream>
using namespace std;

/**
 * @author keshav kabra
 * @since June 15, 2021
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
 * @param TreeNode*, denoting the root of this BST
 * @param int, denoting the value to be searched
 * @return TreeNode*, the reference of node (if found), else NULL
 */ 
TreeNode* get_answer(TreeNode* root, int val)
{
    
    /** Logic :
     * Since it is BST, to a particular node, all the values smaller than this will be in
     * left sub-tree and all values greater than this will be in right sub-tree
     * 
     * So, if root is null, simply return null, as this tree ended
     * If root's value is equal to 'val', we have found the required node, return its reference
     * Else, according to smaller or larger values, make recursive calls to left or right
     * sub-trees.
     * 
     * Time complexity  : O(N) -- At worst, full BST will be traversed
     * Space complexity : O(N) -- Recursive stack to make recursive calls
     */ 
    
    if(root == NULL)
        return NULL;
    if(root->val == val)
        return root;
    if(root->val > val)
        return get_answer(root->left, val);
    return get_answer(root->right, val);
}



/** function searchBST
 * @param TreeNode*, denoting the root of BST
 * @param int, denoting the value to be searched
 * @return TreeNode*, the reference of node (if found), else NULL
 */ 
TreeNode* searchBST(TreeNode* root, int val) 
{
    if(root == NULL)
        return NULL;
    
    // call to recursive finction 'get_answer'
    TreeNode* ans = get_answer(root, val);
    
    return ans;
}



// main function - driver code
int main()
{
	
	// TESTCASE - 1
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	TreeNode* ans = searchBST(root, 1);
	if(ans != NULL)
	    cout<<"Value: "<<ans->val<<"\n";
	else
		cout<<"Null reference\n";
	ans = nullptr;
	root = nullptr;
	
	
	// TESTCASE - 2
	root = new TreeNode(7);
	root->left = new TreeNode(5);
	root->right = new TreeNode(9);
	root->right->left = new TreeNode(8);
	root->right->right = new TreeNode(10);
	ans = searchBST(root, 9);
	if(ans != NULL)
	    cout<<"Value: "<<ans->val<<"\n";
	else
		cout<<"Null reference\n";
	ans = nullptr;
	root = nullptr;
	
	
	// TESTCASE - 3
	root = new TreeNode(8);
	root->left = new TreeNode(6);
	root->right = new TreeNode(9);
	ans = searchBST(root, 7);
	if(ans != NULL)
	    cout<<"Value: "<<ans->val<<"\n";
	else
		cout<<"Null reference\n";
	
	
	return 0;
}

