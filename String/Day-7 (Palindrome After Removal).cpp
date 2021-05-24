  
/**
 * Facebook
 * Given a string and the ability to delete at most one character, 
 * return whether or not it can form a palindrome.
 */

#include<iostream>
using namespace std;

/**
 * @author keshav kabra
 * @since May 24, 2021
 */


/**
  * @param string, str
  * @param int, index(i) from where to start checking from palindrome
  * @param int, index(j) upto this index check from palindrome
  * @return bool, if string from (i,j) is palindrome
  * Logic :
  	> Two pointer algorithm
    > in a loop (from start-i to end-j) compare for the characters of string
    > if characters mis-match, return false (not a palindrome)
    > else, move to next chars by incrementing i and decrementing j
*/
bool is_pal(string str, int i, int j)
{
    while(i < j)
    {
        if(str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}


/**
  * @param string s
  * @return bool, if s can be a palindrome, removing at most one char
*/
/**
    	 * Logic:
    	 * We use two-pointer and helper function.
    	 * We keep one pointer to left most and other pointer to right-most end of string.
    	 * If the characters at pointers are same, we move both pointers inwards (by increasing left and decresing right pointer)
    	 * Else, we remove one character and check if removing makes the string a palindrome
    	 */
bool validPalindrome(string s) 
{
    int sz = s.length();
    
    // if length is 0 - it is palindrome
    if(sz == 0)
        return true;
    
    int i = 0;
    int j = sz-1;
    while(i < j)
    {
        if(s[i] != s[j])
            return (is_pal(s, i+1, j) || is_pal(s, i , j-1)); // helper function
        i++;
        j--;
    }
    return true;
}


// main function - driver code
int main()
{
	
	// TESTCASES
	cout<<validPalindrome("abcba")<<"\n";
	cout<<validPalindrome("foobof")<<"\n";
	cout<<validPalindrome("abccab")<<"\n";
}
