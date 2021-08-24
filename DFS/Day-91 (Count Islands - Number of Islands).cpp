#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since August 24, 2021
 */



/** function mark_adjacent_dfs
 * @param vector<vector<int>>, denoting the grid
 * @param int, current row number
 * @param int, current column number
 * @param int, total rows in the grid
 * @param int, total columns in the grid
 */ 
void mark_adjacent_dfs(vector<vector<int>> &mat, int i, int j, int r, int c)
{
    
    /** Logic :
     * 
     * We check for the boundary cases and for value of current cell, if it is valid and equal to 1, we set it
     * to the value of 2 (to mark it as visited)
     * 
     * After that we make recursive calls in all four directions to mark all cells that come in same island
     *
     */ 
    
    if(i<0 || i>=r || j<0 || j>=c || mat[i][j]!=1)
        return;
    
    mat[i][j] = 2;
    
    mark_adjacent_dfs(mat, i-1, j, r, c); // up
    mark_adjacent_dfs(mat, i+1, j, r, c); // down
    mark_adjacent_dfs(mat, i, j-1, r, c); // left
    mark_adjacent_dfs(mat, i, j+1, r, c); // right
}



/** function numIslands
 * @param vector<vector<int>>, denoting the grid
 * @return int, total number of islands in the grid
 */ 
int numIslands(vector<vector<int>>& grid) 
{
    
    /** Logic :
     * 
     * We iterate on each cell of the given grid and if the value of current cell is 1, we increment the 
     * total count of islands by 1 and call the recursive DFS function 'mark_adjacent_dfs' which marks all
     * the cells that come in the same island
     * 
     * At the end of the loop, return the 'ans' variable which holds the total number of island in the grid
     * 
     */ 
    
    int row = grid.size();
    if(row == 0)
        return 0;
    
    int col = grid[0].size();
    
    int ans = 0;
    
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(grid[i][j] == 1)
            {
                mark_adjacent_dfs(grid, i, j, row, col);
                ans += 1;
            }
        }
    }
    
    return ans;
}



// main function - driver code
int main()
{
	vector<vector<int>> grid;
	
	
	// TESTCASES
	
	grid = {{1, 1, 0, 0, 0}, {1, 1, 0, 1, 0}, {1, 1, 0, 0, 1}};
	cout<<numIslands(grid)<<"\n";
	
	grid = {{0, 0, 1, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 1, 0}};
	cout<<numIslands(grid)<<"\n";
	
	
	return 0;
}
