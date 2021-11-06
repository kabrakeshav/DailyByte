/**
 * Given the root of a binary tree, each node in the tree has a distinct value.
 * After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of 
 * trees).
 * Return the roots of the trees in the remaining forest. You may return the result in any order.
 */

#include<iostream>
#include<vector>
#include<set>
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



/* *** refer : https://www.youtube.com/watch?v=aaSFzFfOQ0o *** */



/** function get_answer
 * @param TreeNode*, denoting the root of the binary tree
 * @param set<int>, set of values to be deleted from the tree
 * @param vector<TreeNode*>, array to store roots of each forest remained
 * @return TreeNode*, deleting/not-deleting the current node
 */ 
TreeNode* get_answer(TreeNode* root, set<int> st, vector<TreeNode*> &ans)
{
    
    /** Logic :
     * 
     * Use DFS approach to first get all the way down to the tree. Now, after reaching to bottom of the tree
     * 
     * If the value is present in the set (value to be deleted), check if current root's left and right are
     * null or not - if not-null, it means they should not be deleted and hence, we push them into answer
     * array. Return null (as current root is deleted)
     * 
     * Else, return root.
     * 
     */
     
    if(root == NULL)
        return NULL;
    
    root->left = get_answer(root->left, st, ans);
    root->right = get_answer(root->right, st, ans);
    
    if(st.find(root->val) != st.end())
    {
        if(root->left)
            ans.push_back(root->left);
        if(root->right)
            ans.push_back(root->right);
        
        return NULL;
    }
    
    return root;
}



/** function delNodes
 * @param TreeNode*, denoting the root of the binary tree
 * @param vector<int>, denoting the array of values to be deleted from the tree
 * @return vector<TreeNode*>, denoting the array containing the root of each forest remained
 */ 
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
{
    vector<TreeNode*> ans;
    set<int> st(to_delete.begin(), to_delete.end());
    
    get_answer(root, st, ans);
    
    // deciding whether to include root-node or not
    if(st.find(root->val) == st.end())
        ans.push_back(root);
    
    return ans;
}



/** function display_answer
 * @param vector<TreeNode*>, denoting the array containing the root of each forest remained
 * 
 * Displays the answer on console
 */ 
void display_answer(vector<TreeNode*> ans)
{
	for(TreeNode* v : ans)
		cout<<v->val<<" ";
	cout<<"\n";
}



// main function - driver code
int main()
{
	vector<int> to_delete;
	vector<TreeNode*> ans;
	
	
	// TESTCASE
	
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(8);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(6);
	
	to_delete = {7, 8};
	
	ans = delNodes(root, to_delete);
	display_answer(ans);
	
	
	return 0;
}
