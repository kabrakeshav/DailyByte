/** 
 * Given a binary tree, return the bottom-left most value.
 * Note: You may assume each value in the tree is unique.
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/**
 * @author keshav kabra
 * @since September 22, 2021
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
 * @param TreeNode*, root of the binary tree
 * @param vector<int>, to store the level-order traversal of tree
 */ 
void find_level_order(TreeNode* root, vector<int> &level_order)
{
    queue<TreeNode*> q;
    q.push(root);
    
    bool flag;
    
    // logic of level-order traversal
    while(!q.empty())
    {
        int n = q.size();
        flag = true;
        
        while(n--)
        {
            TreeNode* t = q.front();
            q.pop();
            
            // pushing only left-most value of each level into the vector
            if(flag) 
            {
                level_order.push_back(t->val);
                flag = false;
            }
            
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        
        flag = true;
    }
}



/** function findBottomLeftValue
 * @param TreeNode*, te root of the binary tree
 * @return int, the bottom left-most  value
 */ 
int findBottomLeftValue(TreeNode* root) 
{
    
    /** Logic :
     * 
     * Calls the find_level_order function, which traveses the tree in level-order fashion and returns the
     * bottom left-most value
     * 
     */ 
    
	vector<int> level_order;
    find_level_order(root, level_order);
    
    return level_order[level_order.size()-1];
}



// main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	cout<<findBottomLeftValue(root)<<"\n";
	
	
	// TESTCASE - 2
	
	root = new TreeNode(8);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->right->left = new TreeNode(2);
	cout<<findBottomLeftValue(root)<<"\n";
	
	return 0;
}
