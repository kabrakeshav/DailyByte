/**
 * Facebook. 
 * Given an undirected graph, of N elements (0 to N-1) determine whether it is bipartite.
 * Note: A bipartite graph, also called a bigraph, is a set of graph vertices decomposed into two disjoint 
 * sets such that no two graph vertices within the same set are adjacent.
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/**
 * @author keshav kabra
 * @since October 1, 2021
 */



// must watch : https://www.youtube.com/watch?v=0ACfAqs8mm0


 
/** function bfs
 * @param vector<vector<int>>, aj matrix
 * @param vector<int>, color array
 * @param int, current node to be processed
 * @param int, value of N
 * @param bool, is graph bipartite from 'node' or not
 * 
 * Logic of BFS
 */ 
bool bfs(vector<vector<int>> &adj, vector<int> &color, int node, int N)
{
    queue<int> q;
    q.push(node);
    color[node] = 1;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int ele : adj[curr])
        {
            if(color[ele] == color[curr])
                return false;
            if(color[ele] == -1)
            {
                color[ele] = 1-color[curr];
                q.push(ele);
            }
        }
    }
    return true;
}



/** function possibleBipartition
 * @param int, denoting value of N
 * @param vector<int>, showing vertices of graph
 * @return bool, is graph bipartite or not
 */ 
bool possibleBipartition(int N, vector<vector<int>>& dislikes) 
{
    
    // mssking adjacency matrix
    
    vector<vector<int>> adj(N+1);
    for(vector<int> v : dislikes)
    {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    
    
    // logic : explained in video
    
    vector<int> color(N+1, -1);
    
    for(int i=0;i<N;i++)
    {
        if(color[i] == -1)
            if(!bfs(adj, color, i, N))
                return false;
    }
    
    return true;
}



// main function - driver code
int main()
{
	vector<vector<int>> v;
	
	
	// TESTCASES
	
	v = {{1,3}, {0,2}, {1,3}, {0,2}};
	cout<<possibleBipartition(4, v)<<"\n";
	
	v = {{1,2}, {0,2,3}, {0,1,3}, {0,2}};
	cout<<possibleBipartition(4, v)<<"\n";
	
	return 0;
}
