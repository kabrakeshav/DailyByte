#include<iostream>
#include<vector>
#include<climits>
using namespace std;


/**
 * @author keshav kabra
 * @since August 23, 2021
 */



/** function get_near_zero
 * @param vector<vector<int>>, grid array
 * @param int, denoting current row number
 * @param int, denoting current column number
 * @param int, total rows in grid
 * @param int, total columns in grid
 * @return int, nearest zero to passed term (rabbit)
 */ 
int get_near_zero(vector<vector<int>> grid, int i, int j, int row, int col)
{
    
    /** Logic :
     * 
     * We can find nearest zero in all possible 4 directions, hence we need to make recursive calls on the 
     * same.
     * Base condition - if the current cell's value is 0, we find one of the possible nearest zeroes.
     * 
     * Else, we make recursive call on all 4 directions and set the current call value to a dummy value 
     * (-99 here) to prevent infinite function calling.
     * 
     * At the end return the nearest zero
     * 
     */ 
    
    if(grid[i][j] == 0 || grid[i][j]==-99)
        return 0;
    
    int ans = 999;
    if(i > 0)
    {
        grid[i][j] = -99;
        ans = min(ans, 1+get_near_zero(grid, i-1, j, row, col));
    }
    if(j > 0)
    {
        grid[i][j] = -99;
        ans = min(ans, 1+get_near_zero(grid, i, j-1, row, col));
    }
    if(i < row-1)
    {
        grid[i][j] = -99;
        ans = min(ans, 1+get_near_zero(grid, i+1, j, row, col));
    }
    if(j < col-1)
    {
        grid[i][j] = -99;
        ans = min(ans, 1+get_near_zero(grid, i, j+1, row, col));
    }
    
    return ans;
}



/** function distance_holes
 * @param vector<vector<int>>, grid array
 * @param vector<vector<int>>, to store answer array
 */ 
void distance_holes(vector<vector<int>> grid, vector<vector<int>> &ans)
{
    
    /** Logic :
     * 
     * We iterate on each cell of the given array and if the value is either 0 or -1, we just copy it into
     * answer vector.
     * If value is 1, we need to find the nearest zero, hence, we will call the function get_near_zero
     */ 
    
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            if(grid[i][j]==-1 || grid[i][j]==0)
                ans[i][j] = grid[i][j];
            else
            {
                ans[i][j] = get_near_zero(grid, i, j, grid.size(), grid[i].size());
            }
        }
    }
}



/** function display_answer
 * @param vector<vector<int>>, vector to be displayed
 * displays the given vector on console
 */ 
void display_answer(vector<vector<int>> v)
{
    for(vector<int> t : v)
    {
        for(int i : t)
            cout<<i<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}



// main function - driver code
int main()
{
    
    // TESTCASE
    
    vector<vector<int>> v = {{-1, 0, 1}, {1, 1, -1}, {1, 1, 0}};
    vector<vector<int>> ans(v.size(), vector<int> (v[0].size()));
    distance_holes(v, ans);
    display_answer(ans);
    
    
   return 0;
}
