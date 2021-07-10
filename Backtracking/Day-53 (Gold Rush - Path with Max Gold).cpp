/**
 * Amazon
 * Given a 2D matrix that represents a gold mine, where each cell’s value represents an amount of gold, 
 * return the maximum amount of gold you can collect given the following rules:
 * You may start and stop collecting gold from any position
 * You can never visit a cell that contains 0 gold
 * You cannot visit the same cell more than once
 * From the current cell, you may walk one cell to the left, right, up, or down
 */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


/**
 * @author keshav kabra
 * @since July 10, 2021
 */



/** function get_answer
 * @param vector<vector<int>>, denoting the gold-mine
 * @param int, denoting the current row number
 * @param int, denoting the current column number
 * @return int, denoting the maximum gold we can collect from given (row, col)
 */ 
int get_answer(vector<vector<int>> &grid, int i, int j)
{
    
    /** Logic :
     * 
     * If either i or j are out of gold-mine or the value of grid[i][j] is 0, return 0
     * 
     * Else, make a variable (maxi) to hold maximum gold collection and make the current cell as taken
     * (by assigning 0)
     * Get DFS call on all 4 directions and get maximum of all of them.
     * 
     * Backtrack the current cell and return the maximum gold we can collect (maxi)
     * 
     */ 
    
    if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j]==0)
        return 0;
    
    int maxi = 0;
    int t = grid[i][j];
    grid[i][j] = 0;
    
    maxi = max(maxi, t+get_answer(grid, i-1, j));
    maxi = max(maxi, t+get_answer(grid, i+1, j));
    maxi = max(maxi, t+get_answer(grid, i, j-1));
    maxi = max(maxi, t+get_answer(grid, i, j+1));
    
    grid[i][j] = t;
    
    return maxi;
}



/** function getMaximumGold
 * @ param vector<vector<int>>, denoting the gold-mine
 * @return int, denoting the maximum gold we can collect
 */ 
int getMaximumGold(vector<vector<int>>& grid) 
{
    
    /** Logic :
     * 
     * Iterate on the entire grid and call a DFS-backstracking function 'get_answer', which calculates
     * the maximum gold we can collect from a position (i, j)
     * 
     * Calculate max of all values and return the answer.
     * 
     * Time Complexity: O(4 * 3^(max(N-1), max(N-1)) ~ O(3^N), where N is one dimension of grid. Because at starting from any cell, we can move in 4 directions. For remaining, we have 3 directions only.
	 * Space Complexity: O(M * N) for implicit stack where grid is of dimensions MxN, worst case when no 0 is there
	 * 
	 */ 
    
    int ans = INT_MIN;
    
    int row = grid.size();
    int col = grid[0].size();
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            ans = max(ans, get_answer(grid, i, j));
    }
    
    return ans;
    
}



// main function - driver code
int main()
{
	
	// TESTCASE
	 
	vector<vector<int>> grid;
	grid = {{0,2,0}, {8,6,3}, {0,9,0}};
	
	cout<<getMaximumGold(grid)<<"\n";
	
	
	return 0;
}
