/**
 * Given a binary search tree, return all modes.
 * Mode is the most frequently occurring value.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since June 21, 2021
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



/** function comp
 * @param pair<int, int>, denoting first pair
 * @param pair<int, int>, denoting second pair
 * @return bool, denoting whether first pair's second value is greater than first pair's second value or not
 * 
 * The function is used to sort the vector by second value
 * called from findMode function
 */ 
static bool comp(pair<int,int> &p1, pair<int,int> &p2)
{
    return p1.second > p2.second;
}



/** function inorder
 * @param TreeNode*, denoting the root of this BST
 * @param vector, denoting the vector where we store inorder traversal of BST
 *     (passed with reference)
 */ 
void inorder(TreeNode * root, vector<int> &v)
{
    if(root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}



/** function findMode
 * @param TreeNode*, denoting the root of BST
 * @return vector, denoting the mode of BST
 */ 
vector<int> findMode(TreeNode* root) 
{
    
    /** Logic :
     * 
     * If root is null, return -1.
     * 
     * Else, we find the inorder traversal of BST (which is always sorted)
     * Now, we store the frequency of each term into a map, where key is the term itself and value
     * denotes its frequency in the given array (inorder traversal)
     * 
     * Sort the map by the second value in descending order (that is, with frequency). The first pair's
     * second value is answer (since it is most frequent term in BST)
     * Now make a vector to store all the keys whose frequency is first pair's second value.
     * return this vector as answer.
     * 
     * Time complexity  : O(NlogN) - traverse the tree, sort the vector and traverse again to find answer
     * Space complexity : O(N)     - for additional vectors and map
     */ 
    
    if(root == NULL)
        return {-1};
    
    vector<int> v;
    inorder(root, v);
    
    unordered_map<int,int> mp;
    for(int i : v)
        mp[i]++;
    
    vector<pair<int,int>> vv(mp.begin(), mp.end());
    sort(vv.begin(), vv.end(), comp);
    
    vector<int> ans;
    int freq = vv[0].second;
    
    for(auto it : vv)
    {
        if(it.second == freq)
            ans.push_back(it.first);
        else
            break;
    }
    
    return ans;
}



/** function display_answer
 * @param vector, denoting the array
 * prints the given array on the console
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
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	ans = findMode(root);
	display_answer(ans);
	ans.clear();
	root = nullptr;
	
	
	// TESTCASE - 2
	
	root = new TreeNode(7);
	root->left = new TreeNode(4);
	root->right = new TreeNode(9);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(8);
	root->right->right = new TreeNode(9);
	root->right->right->right = new TreeNode(9);
	ans = findMode(root);
	display_answer(ans);
	
	
	return 0;
}
