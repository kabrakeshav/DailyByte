/**
 * Facebook
 * Given a reference to the root of a binary tree, return a list containing the average value 
 * in each level of the tree.
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/**
 * @author keshav kabra
 * @since August 26, 2021
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
 * @param vector<double>, array to store average of each level (passed with reference)
 */ 
void level_order(TreeNode* root, vector<double> &ans)
{
    
    /** Logic :
     * 
     * We do the level-order traversal using the queue
     * 
     * For each level, we store the count of nodes in that level in variable 'cnt' and get the sum of all nodes
     * in the variable 'sum'.
     * 
     * After each level, we store the average of that level into the answer vector with the use of 'sum' and
     * 'cnt' variables.
     * 
     */ 
    
    queue<TreeNode*> q;
    q.push(root);
    
    long sum = 0; 
    int cnt;
    
    while(!q.empty())
    {
        int n = q.size();
        cnt = n;
        while(n--)
        {
            TreeNode* t = q.front();
            q.pop();
            sum += t->val;
            
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        
        ans.push_back(sum / (cnt*1.0));
        sum = 0;
    }
    
}



/** function averageOfLevels
 * @param TreeNode*, denoting the root of the binary tree
 * @return vector<double>, array while stores the average of each level of binary tree
 */ 
vector<double> averageOfLevels(TreeNode* root) 
{
    
    /** Logic :
     * 
     * We will do the level-order traversal of the tree and store the average of each level in a vector passed
     * with reference, using a function 'level_order'
     * 
     * Return this vector as answer
     * 
     */ 
    
    if(root == NULL)
        return {};
        
    vector<double> ans;
    
    level_order(root, ans);
    return ans;
}



/** function display_answer
 * @param vector, denoting the array
 * prints the given array on the console
 */ 
void display_answer(vector<double> v)
{
    for(double i : v)
        cout<<i<<" ";
    cout<<"\n";
}



// main function - driver code
int main()
{
	vector<double> answer;
	
	
	// TESTCASE - 1
	
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(6);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(5);
	answer = averageOfLevels(root);
	display_answer(answer);
	root = nullptr;
	
	
	// TESTCASE - 2
	
	root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	answer = averageOfLevels(root);
	display_answer(answer);
	
	
	return 0;
}
