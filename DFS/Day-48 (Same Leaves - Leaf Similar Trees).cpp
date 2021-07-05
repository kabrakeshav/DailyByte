/**
 * Given two binary trees, return whether or not both trees have the same leaf sequence. 
 * Two trees have the same leaf sequence if both trees’ leaves read the same from left to right.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since July 5, 2021
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
 * @param TreeNode*, denoting the root of this binary tree
 * @param vector<int>, to store leaves in inorder traversal 
 *     ( passed with reference )
 */ 
void inorder(TreeNode* root, vector<int> & v)
{
    
    /** Logic :
     * 
     * Performs inorder traversal on the given binary tree and stores only the leaf nodes into 
     * the vector.
     * Hence, we get all leaves from left to right.
     * 
     */ 
    
    if(root == NULL)
        return;
        
    inorder(root->left, v);
    
    if(root->left==NULL && root->right==NULL)
        v.push_back(root->val);
        
    inorder(root->right, v);
}



/** function leafSimilar
 * @param TreeNode*, denoting the root of first binary tree
 * @param TreeNode*, denoting the root of second binary tree
 * @return bool, denoting if leaf-sequence of both binary trees is same
 */ 
bool leafSimilar(TreeNode* root1, TreeNode* root2) 
{
    
    /** Logic :
     * 
     * If both binary trees are null, return true. If any one of binary tree is null (and other is not), 
     * return false
     * 
     * Else, we will find the inorder traversal of tree and store only the leaf nodes into vectors. Due to
     * inorder traversal, the leaf-sequence will automatically be from left to right.
     * Now, if both trees' inorder traversal is equal, return true. Else return false.
     * 
     * Time complexity  : O(N) -- entire tree is parsed
     * Space complexity : O(N) -- for inorder traversal (recursion) and vectors
     * 
     */
     
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
    
    vector<int> v1, v2;
    inorder(root1, v1);
    inorder(root2, v2);
    
    return v1 == v2;
    
}



//main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	TreeNode* root1 = new TreeNode(1);
	root1->left = new TreeNode(1);
	root1->right = new TreeNode(3);
	
	TreeNode* root2 = new TreeNode(7);
	root2->left = new TreeNode(1);
	root2->right = new TreeNode(2);
	
	cout<<leafSimilar(root1, root2)<<"\n";
	root1 = nullptr;
	root2 = nullptr;
	
	
	// TESTCASE - 2
	
	root1 = new TreeNode(8);
	root1->left = new TreeNode(2);
	root1->right = new TreeNode(29);
	root1->right->left = new TreeNode(3);
	root1->right->right = new TreeNode(9);
	
	root2 = new TreeNode(8);
	root2->left = new TreeNode(2);
	root2->right = new TreeNode(29);
	root2->left->left = new TreeNode(2);
	root2->right->left = new TreeNode(3);
	root2->right->right = new TreeNode(9);
	root2->right->left->right = new TreeNode(3);
	
	cout<<leafSimilar(root1, root2)<<"\n";
	
	
	return 0;
}
