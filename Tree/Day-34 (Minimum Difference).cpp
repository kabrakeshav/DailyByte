/**
 * Given a binary search tree, return the minimum difference between any two nodes in the tree.
 */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


/**
 * @author keshav kabra
 * @since June 20, 2021
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
 * @param TreeNode*, denoting the root of current BST
 * @param vector, denoting the vector where inorder traversal of BST will be stored
 *    (passed with reference)
 */ 
void inorder(TreeNode* root, vector<int> &v)
{
    if(root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}



/** function minDiffInBST
 * @param TreeNode*, denoting the root of BST
 * @return int, denoting the mi difference between any two nodes of BST
 */ 
int minDiffInBST(TreeNode* root) 
{
    
    /** Logic :
     * 
     * We store the inorder traversal of BST in a vector 'v' (inorder traversal of BST is
     * always sorted)
     * 
     * Now, loop through the vector to find the nodes with minimum difference and return that
     * as answer.
     * 
     * Time Complexity  : O(N) -- traversal of tree and loop to find minimum difference
     * Space Complexity : O(N) -- Recusion stack and vector to store inorder traversal of BST
     */ 
    
    vector<int> v;
    inorder(root, v);
    
    int diff_ans = INT_MAX;
    int sz = v.size();
    
    for(int i=0;i<sz-1;i++)
    {
        int t = v[i+1] - v[i];
        if(t < diff_ans)
            diff_ans = t;
    }
    return diff_ans;
}



// main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	cout<<minDiffInBST(root)<<"\n";
	root = nullptr;
	
	
	// TESTCASE - 2
	
	root = new TreeNode(29);
	root->left = new TreeNode(17);
	root->right = new TreeNode(50);
	root->left->left = new TreeNode(1);
	root->right->left = new TreeNode(42);
	root->right->right = new TreeNode(59);
	cout<<minDiffInBST(root)<<"\n";
	root = nullptr;
	
	
	// TESTCASE - 3
	
	root = new TreeNode(2);
	root->right = new TreeNode(100);
	cout<<minDiffInBST(root)<<"\n";
	
	return 0;
}
