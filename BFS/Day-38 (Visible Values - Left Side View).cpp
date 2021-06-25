/**
 * Given a binary tree return all the values you’d be able to see 
 * if you were standing on the right side of it with values ordered from top to bottom.
 */

#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;


/**
 * @author keshav kabra
 * @since June 25, 2021
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



/** function find_level_order
 * @param TreeNode*, denoting the root of the binary tree
 * @param vector<int>, vector for storing the left-side view of binary tree
 *    [ passed with reference ]
 */ 
void find_level_order(TreeNode* root, vector<int> &ans)
{
    
    /** Logic :
     * 
     * Same as level order traversal, but here we just store the left-most value (that is, first value
     * of each level) into the vector
     *
     */ 
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty())
    {
        int n = q.size();
        int x = INT_MIN;
        while(n--)
        {
            TreeNode* t = q.front();
            
            if(x == INT_MIN)
            	x = t->val;
            	
            q.pop();
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        ans.push_back(x);
        x = INT_MIN;
    }
    
}



/** function leftSideView
 * @param TreeNode*, denoting the root of the binary tree
 * @return vector<int>, denoting the left-side view of binary tree
 */ 
vector<int> leftSideView(TreeNode* root) 
{   
    
    /** Logic :
     * 
     * If root is null, return empty vector.
     * 
     * Else, find the level order traversal of the binary tree. Now, instead of storing all values
     * of a level, we will just store the first value of each level (which is the left-side view) into
     * the vector.
     * return this vector as answer.
     * 
     * Time complexity  : O(N) -- entire tree is traversed
     * Space complexity : O(N) -- for additional queue and vectors
     * 
     */ 
    
    if(root == NULL)
        return {};
    
    vector<int> ans;
    find_level_order(root, ans);
    
    return ans;
}



/** function display_answer
 * @param vector<int>, denoting the array which stores max of each level of binary tree
 * displays the given array on console
 */
void display_answer(vector<int> v)
{
	for(int i : v)
		cout<<i<<" ";
	cout<<"\n";
}



// main function - driver code
int main()
{
	vector<int> ans;
	
	
	// TESTCASE - 1
	
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	ans = leftSideView(root);
	display_answer(ans);
	root = nullptr;
	ans.clear();
	
	
	// TESTCASE - 2
	
	root = new TreeNode(7);
	root->left = new TreeNode(4);
	root->right = new TreeNode(9);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(8);
	root->right->right = new TreeNode(9);
	root->right->right->right = new TreeNode(9);
	ans = leftSideView(root);
	display_answer(ans);
	
	
	return 0;
}
