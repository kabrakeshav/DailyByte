/**
 * Given a 2D array grid, where zeroes represent water and ones represent land, return the size 
 * of the largest island.
 * Note: An island is one or more cells in grid containing a value of one that may be connected 
 * vertically or horizontally. Each cell in an island contributes a value of one to the current 
 * island’s size.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since October 27, 2021
 */



// same logic as count the number of islands
    


/** function mark_dfs
 * @param vector<vector<int>>, grid of array
 * @param int, current row number
 * @param int, current column number
 * @param int, total number of rows
 * @param int, total number of columns
 * @return int, largest island that can be formed from cell (i, j)
 * 
 * Logic of DFS
 * 
 */ 
int mark_dfs(vector<vector<int>> & mat, int i, int j, int r, int c)
{
    if(i<0 || j<0 || i>=r || j>=c || mat[i][j]!=1)
        return 0;
    
    mat[i][j] = 2;
    
    return 1 + mark_dfs(mat, i-1, j, r, c)
        + mark_dfs(mat, i+1, j, r, c)
        + mark_dfs(mat, i, j-1, r, c)
        + mark_dfs(mat, i, j+1, r, c);
}



/** function maxAreaOfIsland
 * @param vector<vector<int>>, grid of integers (0 and 1)
 * @return int, largest island in the array 
 */ 
int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    int row = grid.size();
    int col = grid[0].size();
    
    int ans = 0;
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            ans = max(ans, mark_dfs(grid, i, j, row, col));
        }
    }
    
    return ans;
}



// main function - driver code
int main()
{
	vector<vector<int>> v;
	
	
	// TESTCASE
	
	v = {{1,1,0}, {1,1,0}, {0,0,1}};
	cout<<maxAreaOfIsland(v)<<"\n";
	
	return 0;
}
