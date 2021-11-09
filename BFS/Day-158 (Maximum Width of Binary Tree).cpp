/**
 * Given the root of a binary tree, return the maximum width of the given tree.
 * The maximum width of a tree is the maximum width among all levels.
 * 
 * The width of one level is defined as the length between the end-nodes (the leftmost and rightmost 
 * non-null nodes), where the null nodes between the end-nodes are also counted into the length 
 * calculation.
 */

#include<iostream>
#include<queue>
using namespace std;


/**
 * @author keshav kabra
 * @since November 9, 2021
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



/** function level_order_traversal
 * @param TreeNode*, root of binary tree
 * @return int, width of binary tree
 * 
 * REFER : https://www.youtube.com/watch?v=ZbybYvcVLks
 * 
 */ 
int level_order_traversal(TreeNode* root)
{
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    
    int ans = 0;
    
    while(!q.empty())
    {
        int sz = q.size();
        int first, last;
        int min_level = q.front().second;  // min-value at any level (left-most value)
        
        for(int i=0;i<sz;i++)
        {
            int cur_id = q.front().second - min_level;  // to avoid overflow in integer
            
            TreeNode* node = q.front().first;
            q.pop();
            
            if(i == 0)
                first = cur_id;
            if(i == sz-1)
                last = cur_id;
            
            if(node->left)
                q.push({node->left, cur_id*2+1});
            if(node->right)
                q.push({node->right, cur_id*2+2});
        }
        
        ans = max(ans, last-first+1);
    }
    
    return ans;
}



/** function widthOfBinaryTree
 * @param TreeNode*, root of binary tree
 * @return int, width of binary tree
 */ 
int widthOfBinaryTree(TreeNode* root) 
{
    if(root == NULL)
        return 0;
    
    int ans = level_order_traversal(root);
    return ans;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(3);
	root->right = new TreeNode(9);
	root->left->left = new TreeNode(8);
	root->left->right = new TreeNode(7);
	cout<<widthOfBinaryTree(root)<<"\n";
	
	
	root = new TreeNode(1);
	root->left = new TreeNode(3);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(5);
	root->right->right = new TreeNode(9);
	root->left->left->left = new TreeNode(6);
	root->right->right->right = new TreeNode(7);
	cout<<widthOfBinaryTree(root)<<"\n";
	
	return 0;
}
