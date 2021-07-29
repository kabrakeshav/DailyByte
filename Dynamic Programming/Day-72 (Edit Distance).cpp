/**
 * Google
 * Given two non-null strings s and t, return the minimum number of operations needed to convert s into t 
 * where a single operation consists of inserting a character, deleting a character, or replacing a character.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since July 29, 2021
 */



/** function minDistance
 * @param string, the first string
 * @param string, the second string
 * @return int, minimum number of operations needed to convert first string into second string
 */ 
int minDistance(string word1, string word2) 
{
    
    /** Logic :
     * 
     * https://www.youtube.com/watch?v=AuYujVj646Q
     * 
     * We will fill the DP table for getting the answer. Each row (i) shows the considered length of string1 and 
     * each column (j) denotes the considered length of string2
     * 
     * When row is 0, it means first string is empty, hence we need to insert all characters of string2 into
     * string1, thus, operations will be equal to length of considered string2 (j) 
     * 
     * When column is 0, it means second string is empty, hence we need to remove all characters of string1,
     * thus, operations will be equal to length of considered string1 (i) 
     * 
     * Insert operation can be shown in (same row, previous column), Remove operation can be shown in
     * (previous row, same column) and Replace operation can be shown in (previous row, previous column)
     * 
     * 
     * Time complexity  : O(MN) - respective lengths of both strings
     * Space complexity : O(MN)
     * 
     */ 
    
    int m = word1.size();
    int n = word2.size();
    
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
             if(i == 0)
                 dp[i][j] = j;
             else if(j == 0)
                 dp[i][j] = i;
            else if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                //               (remove)         (replace)        (insert)
        }
    }
    return dp[m][n];
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<minDistance("cat", "bat")<<"\n";
	cout<<minDistance("beach", "batch")<<"\n";
	
	
	return 0;
}
