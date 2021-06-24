/**
 * Given a binary tree, return the largest value in each of its levels.
 */

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;


/**
 * @author keshav kabra
 * @since June 24, 2021
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



/** function level_order
 * @param TreeNode*, denoting the root of the binary tree
 * @param vector<int>, denoting the array which stores the max of each level (answer)
 *     [ passed with reference ]
 */ 
void level_order(TreeNode* root, vector<int> &ans)
{
    
    /** Logic :
     * 
     * The procedure is same as finding the level-order traversal of the binary tree, but instead of
     * storing entire 'temp' array (which stores all values of a particular level), we store the max
     * of 'temp' vector, thus finding the maximum of each level.
     * 
     */ 
    
    queue<TreeNode*> q;
    q.push(root);
    
    int max = INT_MIN;
    
    while(!q.empty())
    {
        int n = q.size();
        while(n--)
        {
            TreeNode* t = q.front();
            q.pop();
            
            if(max < t->val)
                max = t->val;
            
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        ans.push_back(max);
        max = INT_MIN;
    }
    
}



/** function largestValues
 * @param TreeNode*, denoting the root of the binary tree
 * @return vector<int>, denoting the array which stores max of each level of binary tree
 */ 
vector<int> largestValues(TreeNode* root) 
{
    
    /** Logic :
     * 
     * If root is null, return empty vector.
     * 
     * Else, find the level order traversal of binary tree and find the max-value of each level
     * and store that in answer vector.
     * Return this vector as solution
     * 
     * Time complexity  : O(N) -- entire tree is traversed
     * Space complexity : O(N) -- for additional queue and vectors
     *
     */ 
    
    if(root == NULL)
        return {};
    
    vector<int> ans;
    level_order(root, ans);
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
	
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(10);
	root->right = new TreeNode(15);
	root->right->right = new TreeNode(20);
	ans = largestValues(root);
	display_answer(ans);
	root = nullptr;
	ans.clear();
	
	
	// TESTCASE - 2
	
	root = new TreeNode(1);
	root->left = new TreeNode(5);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(7);
	ans = largestValues(root);
	display_answer(ans);
	
	
	return 0;
}
