/** Amazon 
 * Given two trees s and t return whether or not t is a subtree of s.
 * Note: For t to be a subtree of s not only must each node’s value in t match its corresponding 
 * node’s value in s, but t must also exhibit the exact same structure as s. You may assume both 
 * trees s and t exist.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since September 13, 2021
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
 * @param TreeNode*, tree s
 * @param TreeNode*, tree t
 * @return bool, if t same tree as to that of s
 */ 
bool get_answer(TreeNode* s, TreeNode* t)
{
    if(s==NULL && t==NULL)
        return true;
    
    if(s==NULL || t==NULL)
        return false;
    
    if(s->val == t->val)
        return get_answer(s->left, t->left) && get_answer(s->right, t->right);
    
    return false;
}



/** function isSubtree
 * @param TreeNode*, tree s
 * @param TreeNode*, tree t
 * @return bool, if t is subtree of s
 */ 
bool isSubtree(TreeNode* s, TreeNode* t) 
{
    
    /** Logic :
     * 
     * We call a recursive function 'get_answer' for every node of tree s, the function checks if that particular
     * subtree is s is equal to t, if it is equal, we return true, else call for other sub-parts of s
     * 
     */ 
    
    if(s==NULL && t==NULL)
        return true;
    
    if(s==NULL || t==NULL)
        return false;
    
    bool x = get_answer(s, t);
    
    bool y = isSubtree(s->left, t);
    bool z = isSubtree(s->right, t);
    
    return x || y || z;
    
}



// main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	TreeNode* s = new TreeNode(1);
	s->left = new TreeNode(3);
	s->right = new TreeNode(8);
	
	TreeNode* t = new TreeNode(1);
	t->right = new TreeNode(8);
	
	cout<<isSubtree(s, t)<<"\n";
	
	
	// TESTCASE - 2
	
	s = new TreeNode(7);
	s->left = new TreeNode(8);
	s->right = new TreeNode(3);
	
	t = new TreeNode(7);
	t->left = new TreeNode(8);
	t->right = new TreeNode(3);
	
	cout<<isSubtree(s, t)<<"\n";
	
	
	// TESTCASE - 3
	
	s = new TreeNode(7);
	s->left = new TreeNode(8);
	s->right = new TreeNode(3);
	
	t = new TreeNode(7);
	t->left = new TreeNode(8);
	t->right = new TreeNode(3);
	t->right->left = new TreeNode(1);
	
	cout<<isSubtree(s, t)<<"\n";
	
	
	return 0;
}
