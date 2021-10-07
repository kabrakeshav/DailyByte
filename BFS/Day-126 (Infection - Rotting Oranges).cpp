/**
 * Given a 2D array each cells can have one of three values. Zero represents an empty cell, one 
 * represents a healthy person, and two represents a sick person. Each minute that passes, any 
 * healthy person who is adjacent to a sick person becomes sick. Return the total number of minutes 
 * that must elapse until every person is sick.
 * Note: If it is not possible for each person to become sick, return -1.
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/**
 * @author keshav kabra
 * @since October 7, 2021
 */



/** function orangesRotting
 * @param vector<vector<int>>, grid of numbers
 * @param int, denoting time when every person is sick (oranges are rotten)
 */ 
int orangesRotting(vector<vector<int>>& grid) 
{
    
    /** Logic :
     * 
     * Implimenting ususal BFS algorithm to calculate answer
     * 
     */ 
    
    if(grid.empty()) 
        return 0;
   
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int row = grid.size(), col = grid[0].size();
    int ans = 0, tot = 0, cnt = 0;
    
    queue<pair<int, int>> q;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(grid[i][j] != 0) 
                tot++;
            if(grid[i][j] == 2) 
                q.push({i, j});
        }
    }
    
    while(!q.empty())
    {
        int k = q.size();
        cnt += k; 
        while(k--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nx = x+dx[i], ny = y+dy[i];
                if(nx < 0 || ny < 0 || nx >= row || ny >= col || grid[nx][ny] != 1)
                    continue;
                grid[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
        if(!q.empty()) 
            ans++;
    }
    
    return tot == cnt ? ans : -1;
}



// main function - driver code
int main()
{
	vector<vector<int>> v;
	
	
	// TESTCASES
	
	v = {{1,1,1}, {1,1,0}, {0,1,2}};
	cout<<orangesRotting(v)<<"\n";
	
	v = {{1,1,1}, {0,0,0}, {2,0,1}};
	cout<<orangesRotting(v)<<"\n";
	
	return 0;
}
