/**
 * Given a binary tree, return its zig-zag level order traversal (i.e. its level order traversal 
 * from left to right the first level, right to left the level the second, etc.).
 */


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since June 27, 2021
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



/** function zigzagLevelOrder
 * @param TreeNode*, denoting the root of the binary tree
 * @return vector<vector<int>>, array which is storing zig-zag order traversal of binary tree
 */ 
vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
    
    /** Logic :
     * 
     * If root is null, return empty vector.
     * 
     * Notice that zig-zag order traversal is nothing but level-order traversal with each level at 
     * even index stored in reverse order.
     * So, we will do the same procedure of level-order traversal and maintain a boolean variable
     * which shows if the level number is even.
     * If the level number is even, we reverse the temporary vector before storing it in answer vector, 
     * else simply put temporary vector into answer vector.
     * 
     * Time complexity  : O(N) -- entire tree is traversed
     * Space complexity : O(N) -- for additional queue and vectors
     * 
     */ 
    
    vector<vector<int>> ans;
    
    if(root == NULL)
        return ans;
    
    queue<TreeNode*> q;
    bool even_flag = false;
    q.push(root);
    
    while(!q.empty())
    {
        int n = q.size();
        vector<int> v;
        
        while(n--)
        {
            TreeNode* node = q.front();
            q.pop();
            
            v.push_back(node->val);
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        if(even_flag == true)
        {
            reverse(v.begin(), v.end());
            ans.push_back(v);
            even_flag = false;
        }
        else if(even_flag == false)
        {
            ans.push_back(v);
            even_flag = true;
        }
    }
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
	
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	ans = zigzagLevelOrder(root);
	display_answer(ans);
	root = nullptr;
	ans.clear();
	
	
	// TESTCASE - 2
	
	root = new TreeNode(8);
	root->left = new TreeNode(2);
	root->right = new TreeNode(29);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(9);
	ans = zigzagLevelOrder(root);
	display_answer(ans);
	
	return 0;
}
