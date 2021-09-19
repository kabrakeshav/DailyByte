/** 
 * Given the reference to the root of a binary tree and a value k, return the number of paths in the 
 * tree such that the sum of the nodes along the path equals absolute value of k.
 * Note: The path does not need to start at the root of the tree, but must move downward.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since September 18, 2021
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



// global variable to store number of paths
int answer;



/** function get_sum
 * @param TreeNode*, denoting the root of the binary tree
 * @param int, absolute value of sum required
 * increments the value of 'answer' by 1 whenever absolute values are equal
 */ 
void get_sum(TreeNode* root, int sum)
{
    if(root == NULL)
        return;
    if(abs(root->val) == abs(sum))
        answer++;
    
    get_sum(root->left, sum-abs(root->val));
    get_sum(root->right, sum-abs(root->val));
}



/** function pathSum
 * @param TreeNode*, denoting the root of the binary tree
 * @param int, sum required
 * @return int, number of paths
 */ 
int pathSum(TreeNode* root, int sum) 
{
    if(root)
    {
        get_sum(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
    }
    return answer;
}



// main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	answer = 0;
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(8);
	cout<<pathSum(root, 11)<<"\n";
	
	
	// TESTCASE - 2
	
	answer = 0;
	root =  new TreeNode(2);
	root->left = new TreeNode(-4);
	root->right = new TreeNode(9);
	root->left->left = new TreeNode(2);
	cout<<pathSum(root, 2)<<"\n";
	
	
	return 0;
}
