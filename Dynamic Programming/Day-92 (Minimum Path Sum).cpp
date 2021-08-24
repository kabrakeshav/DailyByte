/**
 * Google
 * Given an NxM matrix, grid, where each cell in the matrix represents the cost of stepping on the 
 * current cell, return the minimum cost to traverse from the top-left hand corner of the matrix to 
 * the bottom-right hand corner.
 * Note: You may only move down or right while traversing the grid.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since August 24, 2021
 */



/** function minPathSum
 * @param vector<vector<int>>, denoting the given matrix
 * @return int, minimum path sum to traverse from top-left to bottom-right
 */
int minPathSum(vector<vector<int>>& grid) 
{
    
    /** Logic :
     * 
     * We use dynamic programming to solve the problem
     * 
     * In the DP table, the first row and column is the sum of the terms above them (as there is one and only
     * one way to reach them)
     * 
     * Now, the subsequence cells of the DP table will be filled by taking the current cell value and adding 
     * it with the minimum value of top and left cells of the DP table
     * 
     * The last cell of DP table contains the minimum path sum.
     * 
     * 
     * Time complexity  : O(M*N) -- Entire matrix is traversed
     * Space complexity : O(M*N) -- For the DP table
     * 
     */ 
    
    int row = grid.size();
    int col = grid[0].size();
    
    vector<vector<int>> dp(row, vector<int> (col));
    dp[0][0] = grid[0][0];
    
    // first row
    for(int i=1;i<col;i++)
    {
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }
    
    // first column
    for(int i=1;i<row;i++)
    {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    
    
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[row-1][col-1];
}



// main function - driver code
int main()
{
	vector<vector<int>> grid;
	
	
	// TESTCASES
	
	grid = {{1, 1, 3}, {2, 3, 1}, {4, 6, 1}};
	cout<<minPathSum(grid)<<"\n";
	
	grid = {{1, 2, 3}, {4, 5, 6}};
	cout<<minPathSum(grid)<<"\n";
	
	
	return 0;
}

