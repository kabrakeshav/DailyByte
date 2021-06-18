/**
 * Given an array of numbers sorted in ascending order, 
 * return a height-balanced binary search tree using every number from the array.
 * Height-balanced meaning that the level of any node’s two subtrees should not differ by more than one.
 */
 
#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since June 18, 2021
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



/** function inorder_traversal
 * @param TreeNode*, denoting the root of BST
 * displays the inorder traversal of BST on console
 */ 
void inorder_traversal(TreeNode* root)
{
    if(root == NULL)
        return;
    
    inorder_traversal(root->left);
    cout<<root->val<<" ";
    inorder_traversal(root->right);
}



/** function build_tree
 * @param vector, denoting the sorted array
 * @param int, denoting the starting index of array
 * @param int, denoting the ending index of array
 */ 
TreeNode* build_tree(vector<int>& v, int start, int end)
{
    
    /** Logic :
     * Since the array is sorted, we will follow binary search approach to build the tree.
     * For height-balancing factor, each time we will make the 'mid' of array as node and
     * call recursive functions appropriately
     * 
     * Time complexity  : O(N) -- N is length of array
     * Space complexity : O(N) -- maximum size of recursive stack
     */ 
    
    if(start > end)
        return NULL;
    
    int mid = (start+end)/2;
    
    TreeNode* root = new TreeNode(v[mid]);
    
    root->left = build_tree(v, start, mid-1);
    root->right = build_tree(v, mid+1, end);
    
    return root;
}



/** function sortedArrayToBST
 * @param vector, denoting the sorted array
 * @return TreeNode*, denoting the root of BST constructed
 */ 
TreeNode* sortedArrayToBST(vector<int>& nums) 
{
    if(nums.size() == 0)
        return NULL;
    
    // function to build tree and return its node
    return build_tree(nums, 0, nums.size()-1);
}


// main function - driver code
int main()
{
	
	// TESTCASE - 1
	vector<int> v = {1, 2, 3};
	TreeNode* ans = sortedArrayToBST(v);
	inorder_traversal(ans);
	v.clear();
	ans = nullptr;
	cout<<"\n";
	
	
	// TESTCASE - 2
	
	v = {1, 2, 3, 4, 5, 6};
	ans = sortedArrayToBST(v);
	inorder_traversal(ans);
	
	
	return 0;
}
