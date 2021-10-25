/**
 * Given the reference to a binary tree, return the maximum path sum.
 * Note: The path that creates the maximum sum does not need to pass through the root of the tree.
 */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


/**
 * @author keshav kabra
 * @since October 25, 2021
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
 * @param TreeNode*, root of binary tree
 * @param int, final max sum path value
 * @return int, value for making correct recursive calls
 */ 
int get_answer(TreeNode* root, int &ans)
{
    
    // refer : https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603423/Python-Recursion-stack-thinking-process-diagram
    
    if(root == NULL)
        return 0;
    
    int left = max(get_answer(root->left, ans), 0);
    int right = max(get_answer(root->right, ans), 0);
    
    int curr_ans = root->val + left + right;
    ans = max(ans, curr_ans);
    
    return root->val + max(left, right);
}



/** function maxPathSum
 * @param TreeNode*, root of binary tree
 * @return int, max path sum in the binary tree
 */ 
int maxPathSum(TreeNode* root) 
{
    int ans = INT_MIN;
    get_answer(root, ans);
    
    return ans;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(4);
	root->right = new TreeNode(9);
	cout<<maxPathSum(root)<<"\n";
	
	root = new TreeNode(-10);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	cout<<maxPathSum(root)<<"\n";
	
	return 0;
}
