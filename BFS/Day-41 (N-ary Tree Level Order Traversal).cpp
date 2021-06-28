/**
 * Given a binary tree, return its zig-zag level order traversal (i.e. its level order traversal 
 * from left to right the first level, right to left the level the second, etc.).
 */


#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/**
 * @author keshav kabra
 * @since June 28, 2021
 */



/** class Node
 * To make individual node of n-ary tree
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



/** function levelOrder
 * @param Node*, denoting the root of the n-ary tree
 * @return vector<vector<int>>, denoting the level-order traversal of n-ary tree
 */ 
vector<vector<int>> levelOrder(Node* root)
{
    
    /** Logic :
     * 
     * According to the definition of Node class (individual node of n-ary tree), the value of Node
     * is in the variable 'val' and all its children are stored in a vector 'children'.
     * 
     * If root is null, return empty vector
     * 
     * Else, follow the same procudure as for level-order traversal of binary tree except for
     * recursive calls.
     * If the children of a Node exists, the 'children' vector of this Node will be non-empty, hence,
     * if 'children' vector of this Node is non-empty, we iterate on this vector and push all its Nodes
     * into the queue.
     * 
     * Time complexity  :  O(N) -- Entire tree is traversed
     * Space complexity :  O(N) -- for additional queue and vectors
     * 
     */ 
    
    if(root == NULL)
        return {};
    
    queue<Node*> q;
    q.push(root);
    
    vector<vector<int>> ans;
    
    while(!q.empty())
    {
        int N = q.size();
        vector<int> v;
        
        while(N--)
        {
            Node* fr = q.front();
            q.pop();
            v.push_back(fr->val);
            
            if(!fr->children.empty())
            {
                for(Node* k : fr->children)
                    q.push(k);
            }
        }
        ans.push_back(v);
    }
    return ans;
}



/** function display_answer
 * @param vector<vector<int>>, denoting the level-order traversal array of n-ary tree
 * Displays the array on console
 */ 
void display_answer(vector<vector<int>> ans)
{
    for(vector<int> v : ans)
    {
        for(int i : v)
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
	
	Node* root = new Node(8);
	root->children = {new Node(2), new Node(3), new Node(29)};
	ans = levelOrder(root);
	display_answer(ans);
	root = nullptr;
	ans.clear();
	
	
	// TESTCASE - 2
	
	root = new Node(2);
	root->children = {new Node(1), new Node(6), new Node(9)};
	root->children[0]->children = {new Node(8)};
	root->children[1]->children = {new Node(2)};
	root->children[2]->children = {new Node(2)};
	root->children[1]->children[0]->children = {new Node(19), new Node(12), new Node(90)};
	ans = levelOrder(root);
	display_answer(ans);
	
	
	return 0;
}
