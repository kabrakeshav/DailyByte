/**
 * Given an MxN grid of characters and a string word, 
 * return true if word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cells, 
 * where adjacent cells are horizontally or vertically neighboring. 
 * The same letter cell may not be used more than once.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since July 8, 2021
 */



/** function get_answer
 * @param vector<vector<char>>, denoting the grid of characters
 * @param int, denoting the ith index (row) of the grid
 * @param int, denoting the jth index (column) of the grid
 * @param int, denoting the index of string we need to search (initially 0 and increments as we found characters)
 * @param string, denoting the word we need to search in the grid
 * @return bool, whether we found the word in grid or not
 */ 
bool get_answer(vector<vector<char>>& v, int i, int j, int index, string& word)
{
    
    /** Logic :
     * 
     * If the index is word's length, it means we have found the word, so return true.
     * 
     * Else if the ith or jth position is not inside the grid or the current character of grid is not
     * equal to word's current index, return false.
     * 
     * Else, mark that character as read ( by '*' ) and make 4 recursive calls to all directions.
     * 
     * At the end, set the word again to previous value (backtracking)
     * 
     * return if we found the word or not
     * 
     */ 
    
    
    // found the word - return true
    if(index == word.length())
        return true;
    
    
    // index not inside grid or characters not matched - return false
    if(i<0 || i>=v.size() || j<0 || j>=v[i].size() || v[i][j]!=word[index])
        return false;
    
    
    // marking this character as read ( by '*' )
    char t = v[i][j];
    v[i][j] = '*';
    
    
    // recursive calls to all 4 directions
    bool found = get_answer(v, i+1, j, index+1, word) ||
                 get_answer(v, i-1, j, index+1, word) ||
                 get_answer(v, i, j+1, index+1, word) ||
                 get_answer(v, i, j-1, index+1, word);
    
    
    // reversing the effect - backtracking
    v[i][j] = t;
    
    
    // whether we found the word or not
    return found;
    
}



/** function exist
 * @param vector<vector<char>>, denoting the grid of characters
 * @param string, denoting the word we need to search in the grid
 * @return bool, whether we found the word in grid or not
 */ 
bool exist(vector<vector<char>>& board, string word) 
{
    
    /** Logic :
     * 
     * Take rows and columns count of the grid and iterate on each character of the grid.
     * 
     * The word can only be generated, if the first letter of string and the current character of grid
     * are equal. 
     * If they are equal and the recursive-backtracking function get_answer returns true, it means we have
     * found the word - return true.
     * 
     * Else, return false.
     * 
     * Time complexity  : O(M*N*4^L)  - L is the length of string
     * Space complexity : O(L)        - for each cell start
     * 
     */ 
    
    int row = board.size();
    int col = board[0].size();
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            
            // found the word - return true
            if(board[i][j]==word[0] && get_answer(board, i, j, 0, word))
                return true;
        }
    }
    
    return false;
}



// main function - driver code
int main()
{
    
    // making grid (board)
	vector<vector<char>> grid;
	grid = {{'C','A','T','F'}, {'B','G','E','S'}, {'I','T','A','E'}};
	
	
	// TESTCASES
	
	cout<<exist(grid, "CAT")<<"\n";
	cout<<exist(grid, "TEA")<<"\n";
	cout<<exist(grid, "SEAT")<<"\n";
	cout<<exist(grid, "BAT")<<"\n";
	
	
	return 0;
}
