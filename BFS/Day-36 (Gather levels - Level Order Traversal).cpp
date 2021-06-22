/**
 * Given a binary tree, return its level order traversal 
 * where the nodes in each level are ordered from left to right.
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/**
 * @author keshav kabra
 * @since June 22, 2021
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



/** function levelOrder
 * @param TreeNode*, denoting the root of the binary tree
 * @return vector<vector<int>>, denoting the array which stores level-order traversal of binary tree
 */ 
vector<vector<int>> levelOrder(TreeNode* root) 
{
    
    /** Logic :
     * 
     * If root is null, return empty array.
     * 
     * Else, make a queue (which stores the nodes of a particular level) and push root into it.
     * Iterate while queue is not empty. For each time, we take the size of the queue (which denotes the
     * number of nodes on previous level) and iterate as many times. 
     * We create a temporary vector to store that level's nodes.
     * 
     * In each iteration, push the node's value into temporary vector and if its left or right child
     * exist, push them into queue.
     * At the end of the iteration, push this temporary vector into answer vector.
     * 
     * Continue process till queue is not empty.
     * 
     * Time complexity  : O(N) -- entire tree is traversed
     * Space complexity : O(N) -- for additional queue and vectors
     */ 
    
    
    // store answer of level-order traversal
    vector<vector<int>> ans;
    
    // if root is null, return empty vector
    if(root == NULL)
        return ans;
    
    // make a queue and push root into it
    queue<TreeNode*> q;
    q.push(root);
    
    
    // iterate while queue is not empty
    while(!q.empty())
    {
        // taking queue's size
        int n = q.size();
        
        // temporary vector to store one level's node's data
        vector<int> v;
        
        while(n--)
        {
            TreeNode* node = q.front();
            q.pop();
            
            // pushing value into temporary vector
            v.push_back(node->val);
            
            // if left or right child exist
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        
        // pushing temporary vector into answer vector
        ans.push_back(v);
    }
    
    // returning answer (level-order traversal)
    return ans;
}



/** function display_answer
 * @param vector<vector<int>>, denoting the array which stores level-order traversal of binary tree
 * displays the given array on console
 */
void display_answer(vector<vector<int>> v)
{
	for(vector<int> t : v)
	{
		for(int i : t)
			cout<<i<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}



// main function - driver code
int main()
{
	vector<vector<int>> ans;
	
	
	// TESTCASE - 1
	
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	ans = levelOrder(root);
	display_answer(ans);
	root = nullptr;
	ans.clear();
	
	
	// TESTCASE - 2
	
	root = new TreeNode(2);
	root->left = new TreeNode(10);
	root->right = new TreeNode(15);
	root->right->right = new TreeNode(20);
	ans = levelOrder(root);
	display_answer(ans);
	root = nullptr;
	ans.clear();
	
	
	// TESTCASE - 3
	
	root = new TreeNode(1);
	root->left = new TreeNode(9);
	root->right = new TreeNode(32);
	root->left->left = new TreeNode(3);
	root->right->right = new TreeNode(78);
	ans = levelOrder(root);
	display_answer(ans);
	
	
	return 0;
}
