/**
 * You’re a thief trying to rob a binary tree. As a thief, you are trying to steal as much money as 
 * possible. The amount of money you steal is equivalent to the sum of all the node’s values that you 
 * decide to rob. If two adjacent nodes are robbed, the authorities are automatically alerted. 
 * Return the maximum loot that you can steal without alerting the authorities.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since November 6, 2021
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
 * @param TreeNode*, denoting the root of the binary tree
 * @return pair<int, int>, denoting the max-value pair from chosen/not-chosen strategy
 * 
 * DFS Approach
 */ 
pair<int,int> get_answer(TreeNode* root)
{
    if(root == NULL)
        return {0, 0};
    
    int choose, not_choose;
    
    pair<int,int> left = get_answer(root->left);
    pair<int,int> right = get_answer(root->right);
    
    choose = root->val + left.second + right.second;
    not_choose = max(left.first, left.second) + max(right.first, right.second);
    
    return {choose, not_choose};
}



/** function rob
 * @param TreeNode*, denoting the root of the binary tree
 * @return int, maximum amount that can be robbed
 */
int rob(TreeNode* root) {
    if(root == NULL)
        return 0;
    
    auto it = get_answer(root);
    
    return max(it.first, it.second);
}



// main function - driver code
int main()
{
	vector<int> in;
	
	
	// TESTCASES
	
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(5);
	root->right = new TreeNode(7);
	cout<<rob(root)<<"\n";
	
	
	root = new TreeNode(4);
	root->left = new TreeNode(3);
	root->right = new TreeNode(2);
	root->left->right = new TreeNode(9);
	root->right->right = new TreeNode(7);
	cout<<rob(root)<<"\n";
	
	return 0;
}
