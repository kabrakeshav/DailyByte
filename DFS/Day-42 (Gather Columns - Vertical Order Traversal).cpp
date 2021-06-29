/** 
 * Given a binary tree, return its column order traversal from top to bottom and left to right.
 * if two nodes are in the same row and column, order them from left to right.
 * Vertical Order Traversal
 */

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since June 29, 2021
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



/** function verticalTraversal
 * @param TreeNode*, denoting the root of the binary tree
 * @return vector<vector<int>>, denoting the Vertical-order Traversal of the binary tree
 */ 
vector<vector<int>> verticalTraversal(TreeNode* root) 
{
    
    /** Logic :
     * 
     * We have the concept of horizontal-distance (hd) here, we assume that hd of root is 0, all nodes to
     * left of root goes into negative hd and all nodes right to root will have positive hd.
     * The nodes with same hd comes under same column and hence stored in same vector of Vertical-order traversal.
     * 
     * If root is null, return empty vector.
     * 
     * Else, make a queue of pair to store the tree-node and its hd. Also, make a map with key as hd and
     * value as a vector denoting all nodes for that particular hd.
     * Push root with hd 0 into the queue.
     * 
     * Now iterate while queue is not empty and push the values and make recursive calls appropriately.
     * 
     * Time complexity  : O(N) -- Entire tree is traversed
     * Space complexity : O(N) -- for additional vectors, map and queue
     */ 
    
    
    // to store answer for Vertical-order traversal
    vector<vector<int>> ans;
    
    
    // if root is null, return empty vector
    if(root == NULL)
        return ans;
    
    // map to store hd as key and all nodes of that particular hd as value (in form of vector)
    map<int, vector<int>> mp;
    
    // queue to store pair of binary-node with their corresponding hd
    // push root with hd 0
    queue<pair<TreeNode*,int>> q;
    q.push({root, 0});
    
    
    // iterate while queue is not empty
    while(!q.empty())
    {
        
        // taking queue's size
        int N = q.size();
        
        // vector to store pair of TreeNode's value and corresponding hd respectively
        vector<pair<int,int>> v;
        
        while(N--) 
        {
            
            // taking front of queue
            pair<TreeNode*, int> p = q.front();
            
            // current node
            TreeNode* t = p.first;
            // value of hd
            int xx = p.second;
            
            // pop this pair out of queue
            q.pop();

            // push into vector -> (value, hd)
            v.push_back({t->val, xx});
            
            // recursive calls to left and right subtrees
            if(t->left)
                q.push({t->left, xx-1});
            if(t->right)
                q.push({t->right, xx+1});
        }
        
        // sort(v.begin(), v.end());
        
        // pushing one level's nodes in their appropriate hd keys
        for(auto it : v)
            mp[it.second].push_back(it.first);
    }
    
    
    // putting map into answer vector
    for(auto it : mp)
    {
        vector<int> v;
        for(int i : it.second)
            v.push_back(i);
        
        ans.push_back(v);
    }
    
    
    // return answer
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
	
	TreeNode* root = new TreeNode(8);
	root->left = new TreeNode(2);
	root->right = new TreeNode(29);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(9);
	ans = verticalTraversal(root);
	display_answer(ans);
	root = nullptr;
	ans.clear();
	
	
	// TESTCASE - 2
	
	root = new TreeNode(100);
	root->left = new TreeNode(53);
	root->right = new TreeNode(78);
	root->left->left = new TreeNode(32);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(20);
	ans = verticalTraversal(root);
	display_answer(ans);
	
	
	return 0;
}
