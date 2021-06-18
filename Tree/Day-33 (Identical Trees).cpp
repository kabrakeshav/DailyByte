/**
 * Given two binary trees, return whether or not the two trees are identical. 
 * Identical meaning they exhibit the same structure and the same values at each node. 
 */

#include<iostream>
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



/** function isSameTree
 * @param TreeNode*, denoting the root of first tree
 * @param TreeNode*, denoting the root of second tree
 * @return bool, whether the trees are identical or not
 */ 
bool isSameTree(TreeNode* p, TreeNode* q) 
{
    
    /** Logic :
     * 
     * If both trees are null, return true. If anyone of the trees are null, return false.
     * Else, if the values of both tree nodes are different, return false.
     * 
     * Otherwise, check the same conditions for left subtree and right subtree by making recursive calls.
     * 
     * Time compplexity  : O(N) -- Entire tree will be traversed in worst case (when identical)
     * Space compplexity : O(N) -- If tree is skewed, recursive stack will be of size N
     */ 
    
    if(p==NULL && q==NULL)
        return true;
    if(p==NULL || q==NULL)
        return false;
    
    if(p->val != q->val)
        return false;
    
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}



// main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	TreeNode* root1 = new TreeNode(2);
	root1->left = new TreeNode(1);
	root1->right = new TreeNode(3);
	
	TreeNode* root2 = new TreeNode(2);
	root2->left = new TreeNode(1);
	root2->right = new TreeNode(3);
	
	cout<<isSameTree(root1, root2)<<"\n";
	root1 = nullptr;
	root2 = nullptr;
	
	
	
	// TESTCASE - 2
	
	root1 = new TreeNode(1);
	root1->right = new TreeNode(9);
	root1->right->right = new TreeNode(18);
	
	root2 = new TreeNode(1);
	root2->left = new TreeNode(9);
	root2->left->right = new TreeNode(3);
	
	cout<<isSameTree(root1, root2)<<"\n";
	root1 = nullptr;
	root2 = nullptr;
	
	
	return 0;
}
