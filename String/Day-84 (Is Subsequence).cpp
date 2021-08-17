/**
 * Google
 * Given two strings s and t return whether or not s is a subsequence of t.
 * Note: You may assume both s and t only consist of lowercase characters and both have a 
 * length of at least one.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since August 17, 2021
 */
 


/** function isSubsequence
 * @param string, first string (s)
 * @param string, second string (t)
 * @return bool, whether s is subsequence of t
 */ 
bool isSubsequence(string s, string t) 
{
    
    /** Logic :
     * 
     * If the length of string s is 0, it is subsequence of t, hence return true
     * 
     * Else, we make two pointers initially pointing to first elements of strings s and t respectively.
     * Now, while iterating on each character of string t, if the current character is same as character 
     * of string s, we increment the pointer of string s.
     * 
     * Now, if s-pointer is pointing to end of string s, we have found the subsequence, hence return true
     * Else return false
     * 
     * 
     * Time complexity  : O(N) -- entire string is traversed
     * Space complexity : O(1)
     * 
     */ 
    
    int NS = s.length();
    int NT = t.length();
    
    if(NS == 0)
        return true;
    
    int t_ptr = 0;
    int s_ptr = 0;
    
    while(t_ptr < NT)
    {
        if(t[t_ptr] == s[s_ptr])
        {
            s_ptr++;
            if(s_ptr == NS)
                return true;
        }
        t_ptr++;
    }
    
    return false;
}



// main functiom - driver code
int main()
{
	
	// TESTCASES
	
	cout<<isSubsequence("abc", "aabbcc")<<"\n";
	cout<<isSubsequence("cpu", "computer")<<"\n";
	cout<<isSubsequence("xyz", "axbyc")<<"\n";
	
	return 0;
}
