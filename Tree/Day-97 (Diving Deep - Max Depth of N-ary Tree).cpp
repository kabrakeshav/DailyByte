/** Google
 * Given an N-ary tree, return its maximum depth.
 * Note: An N-ary tree is a tree in which any node may have at most N children.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since September 9, 2021
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



/** function maxDepth
 * @param Node*, denoting the root of the N-ary tree
 * @return int, maximum depth of N-ary tree
 */ 
int maxDepth(Node* root) 
{
    
    /** Logic :
     * 
     * If root is Null, the depth of tree is 0, hence return 0 (base-case)
     * Else, perform recursive calls for each of the children and get the maximum depth
     * 
     */ 
    
    if(root == NULL)
        return 0;
    
    int depth = 0;
    
    for(auto child : root->children)
        depth = max(depth, maxDepth(child));
    
    return 1+depth;
}



// main function - driver code
int main()
{
    
    // TESTCASE - 1
    
	Node* root = new Node(4);
	root->children = {new Node(3), new Node(9), new Node(2)};
	root->children[0]->children = {new Node(7)};
	root->children[2]->children = {new Node(2)};
	cout<<maxDepth(root)<<"\n";
	
	
	// TESTCASE - 2
	
	root = new Node(1);
	root->children = {new Node(3), new Node(2), new Node(4)};
	root->children[0]->children = {new Node(5), new Node(6)};
	cout<<maxDepth(root)<<"\n";
	
	
	return 0;
}
