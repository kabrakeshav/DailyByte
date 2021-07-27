/**
 * Google
 * Given two non-null strings, s and t, return the length of their longest subsequence.
 * A subsequence of a string is a new string generated from the original string with some characters 
 * (can be none) deleted without changing the relative order of the remaining characters.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since July 27, 2021
 */



/** function longestCommonSubsequence
 * @param string, first string
 * @param string, second string
 * @return int, the longest common subsequence length
 */ 
int longestCommonSubsequence(string text1, string text2) 
{
    
    /** Logic :
     * 
     * We fill the DP table of size m*n (lengths of strings respectively) with all rows and columns number denoting
     * the length of substring
     * Fill the first row and first column with 0 (as if any one string is empty, the LCS is 0)
     * 
     * Now, if the characters of strings at ith row and jth column match, we increment the diagonal element
     * by 1 and store it, else take maximum from previous row and column
     * 
     */ 
    
    int m = text1.length();
    int n = text2.length();
    
    vector<vector<int>> v(m+1, vector<int>(n+1));
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                v[i][j] = 0;
            else if(text1[i-1] == text2[j-1])
                v[i][j] = v[i-1][j-1]+1;
            else
                v[i][j] = max(v[i-1][j], v[i][j-1]);
        }
    }
    
    return v[m][n];
    
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<longestCommonSubsequence("xyz", "xyz")<<"\n";
	cout<<longestCommonSubsequence("abca", "acea")<<"\n";
	cout<<longestCommonSubsequence("abc", "def")<<"\n";
	
	
	return 0;
}
