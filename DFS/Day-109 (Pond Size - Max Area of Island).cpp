/** You are given two-dimensional matrix that represents a plot of land. Within the matrix there 
 * exist two values: 1s which represent land and 0s which represent water within a pond. Given that 
 * parts of a pond can be connected both horizontally and vertically (but not diagonally), return 
 * the largest pond size.
 * Note: You may assume that each zero within a given pond contributes a value of one to the total 
 * size of the pond.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since September 14, 2021
 */



/** function mark_dfs
 * @param vector<vector<int>>, denoting the grid of plot of land
 * @param int, current row
 * @param int, current column
 * @param int, total number of rows
 * @param int, total number of columns
 * @return int, size of pond from the cell mat[i][j]
 */ 
int mark_dfs(vector<vector<int>> & mat, int i, int j, int r, int c)
{
    
    // boundary cases
    if(i<0 || j<0 || i>=r || j>=c || mat[i][j]!=0)
        return 0;
    
    
    // marking the current cell - so that it is not counted again
    // if not marked, infinite recursion will occur
    mat[i][j] = 2;
    
    
    // DFS calls in all possible four directions
    return 1 + mark_dfs(mat, i-1, j, r, c)
        + mark_dfs(mat, i+1, j, r, c)
        + mark_dfs(mat, i, j-1, r, c)
        + mark_dfs(mat, i, j+1, r, c);
        
}



/** function maxAreaOfPond
 * @param vector<vector<int>>, denoting the grid of plot of land
 * @return int, area of largest pond (group of 0s)
 */ 
int maxAreaOfPond(vector<vector<int>>& grid) 
{
    
    /** Logic :
     * 
     * Use DFS to mark the largest pond that can be formed from each individual cell of the land
     * For DFS we use 'mark_dfs' function
     * 
     * return the largest area covering cell
     * 
     */ 
    
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
	
	// TESTCASES
	
	v = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
	cout<<maxAreaOfPond(v)<<"\n";
	
	v=  {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
	cout<<maxAreaOfPond(v)<<"\n";
	
	
	return 0;
}
