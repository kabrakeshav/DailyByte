/**
 * Given an n-ary tree, return a list containing the post order traversal of the tree.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since November 11, 2021
 */



/** class Node
 * Definition of Node of N-ary tree
 */ 
class Node 
{
	public:
	    int val;
	    vector<Node*> children;
	
	    Node() {}
	
	    Node(int _val) {
	        val = _val;
	    }
	
	    Node(int _val, vector<Node*> _children) {
	        val = _val;
	        children = _children;
	    }
};



/** function postorder
 * @param Node*, root of N-ary tree
 * @param vector<int>, to store post-order traversal
 */ 
void postorder(Node* root, vector<int> &v) 
{
    if(root == NULL)
        return;
        
    if(!root->children.empty())
    {
        for(Node* node : root->children)
            postorder(node, v);
    }
    
    v.push_back(root->val);
}



/** function display_answer
 * @param vector<int>, array containing post-order traversal of given tree
 * Displays the array on console
 */ 
void display_answer(vector<int> ans)
{
	for(int i : ans)
		cout<<i<<" ";
	cout<<"\n";
}



// main function - driver code
int main()
{
	vector<int> ans;
	
	
	// TESTCASES
	
	Node* root = new Node(1);
	root->children = {new Node(2), new Node(3), new Node(4)};
	postorder(root, ans);
	display_answer(ans);
	
	root = new Node(1);
	root->children = {new Node(3), new Node(2), new Node(4)};
	root->children[0]->children = {new Node(5), new Node(6)};
	postorder(root, ans);
	display_answer(ans);
	
	
	return 0;
}
