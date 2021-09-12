/** Facebook
 * Given the root of a binary tree and two values low and high return the sum of all values in the 
 * tree that are within low and high.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since September 10, 2021
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
 * @param TreeNode*, denoting the root of the binary tree
 * @param int, denoting the low
 * @param int, denoting the high
 * @param int, to store answer sum
 * inorder traversal of binary tree while adding appropriate values
 */ 
void inorder(TreeNode* root, int L, int R, int &ans)
{
    if(root == NULL)
        return;
    inorder(root->left, L, R, ans);
    if(root->val>=L && root->val<=R)
        ans += root->val;
    inorder(root->right, L, R, ans);
}



/** function rangeSumBST
 * @param TreeNode*, denoting the root of the binary tree
 * @param int, denoting the low
 * @param int, denoting the high
 * @return int, sum of values of nodes ranging between low and high
 */ 
int rangeSumBST(TreeNode* root, int L, int R) 
{
    /** Logic :
     * 
     * Do inorder traversal of binary tree, if node value of in between low and high, count it in
     * answer
     */ 
    
    if(root == NULL)
        return 0;
    
	int ans = 0;
    inorder(root, L, R, ans);
    return ans;
}



// main function - driver code
int main()
{
    
    // TESTCASE
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(7);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(4);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(9);
	cout<<rangeSumBST(root, 3, 5)<<"\n";
	
	return 0;
}
