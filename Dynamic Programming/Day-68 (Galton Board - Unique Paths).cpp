/**
 * Google
 * A ball is dropped into a special Galton board where at each level in the board the ball can only
 * move right or down. Given that the Galton board has M rows and N columns, 
 * return the total number of unique ways the ball can arrive at the bottom right cell of the Galton board.
 * 
 * Galton board is a device to illustrate the binomial distribution, usually with little balls 
 * falling through grid of pegs where the balls bounce back and forth from one peg to another, 
 * to come to rest in little bins at the bottom.
 * 
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since July 25, 2021
 */
 
 
 
/** function uniquePaths
 * @param int, denoting rows
 * @param int, denoting columns
 * @return int, the number of unique ways the ball can arrive at the bottom right cell of the Galton board
 */
int uniquePaths(int N, int M) 
{
    
    /** Logic :
     * 
     * We fill the dp table and return the last cell value as answer
     * 
     * if either row or column is 0, it means there is only one way possible to reach there, hence fill that
     * cell with 1
     * Otherwise the number of ways will be the sum of terms in previous row and previous column
     * 
     */ 
    
	long long table[N][M];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(i==0 || j==0)
                table[i][j] = 1;
            else
                table[i][j] = (table[i-1][j]+table[i][j-1]);
        }
    }
    return table[N-1][M-1];
    
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<uniquePaths(2, 2)<<"\n";
	cout<<uniquePaths(4, 3)<<"\n";
	
	
	return 0;
}

