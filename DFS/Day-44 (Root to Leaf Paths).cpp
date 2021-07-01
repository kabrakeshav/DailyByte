/**
 * Given a binary tree, print all paths from root to leaf paths 
 * (including one node only once in a path).
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since July 1, 2021
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



/** function print_util_paths
 * @param TreeNode*, denoting the root of this binary tree
 * @param string, deno the string which will store this root to leaf path
 * @path vector<string> , to store the entire answer (passed with reference)
 */ 
void print_util_paths(TreeNode* root, string str, vector<string> &ans)
{
    
    /** Logic :
     * 
     * If root is not null, we will add the 'val' of root to string. Now if the root has no left and
     * right child (leaf node), we append the current string to 'ans' vector and reinitialize string.
     * 
     * Else (child node of root exist), we add '->' to current string and make recursive calls to left and 
     * right sub-tree.
     * 
     * Time complexity  : O(N) - entire tree is traversed
     * Space complexity : O(N) - for recursive calls and vector
     * 
     */ 
    
    if(root == NULL)
        return;
    
    str += to_string(root->val);
    
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(str);
        str = "";
    }
    else
    {
        str += "->";
        print_util_paths(root->left, str, ans);
        print_util_paths(root->right, str, ans);
    }
}



/** function binaryTreePaths
 * @param TreeNode*, denoting the root of the binary tree
 * @return vector<string>, denoting the vector which stores the binary tree paths
 */ 
vector<string> binaryTreePaths(TreeNode* root) 
{
    
    /** Logic :
     * 
     * If root is null, return empty vector.
     * 
     * Else, call a helper function (print_util_paths) which will get the required answer into
     * the vector.
     * 
     */ 
    
	vector<string> ans;
	
    if(root == NULL)
        return ans;
    
    print_util_paths(root, "", ans);
    return ans;
}


/** function print_answer
 * @param vector<string>, denoting the vector which stores the binary tree paths
 * displays the binary-tree paths on the console
 */
void print_answer(vector<string> ans)
{
	for(string str : ans)
		cout<<str<<"  ";
	cout<<"\n";
}



// main function - driver code
int main()
{
	vector<string> ans;
	
	
	// TESTCASE - 1
	
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	ans = binaryTreePaths(root);
	print_answer(ans);
	root = nullptr;
	ans.clear();
	
	
	// TESTCASE - 2
	
	root = new TreeNode(8);
	root->left = new TreeNode(2);
	root->right = new TreeNode(29);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(9);
	ans = binaryTreePaths(root);
	print_answer(ans);
	
	
	return 0;
}
