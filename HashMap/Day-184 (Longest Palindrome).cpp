/**
 * Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
 * palindrome that can be built with those letters.
 * 
 * Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


/**
 * @author keshav kabra
 * @since December 7, 2021
 */



/** function longestPalindrome
 * @param string, given string
 * @return int, length of the longest palindrome that can be formed from the given string
 */ 
int longestPalindrome(string s) 
{
    unordered_map<char,int> mp;
    
    for(char ch : s)
        mp[ch]++;
    
    int ans = 0;
    
    bool odd = false;
    for(auto it : mp)
    {
        
        // if count of character is even - we can arrange it in palindrome fashion
        if(it.second%2 == 0)
            ans += it.second;
            
        // if count of character is odd, but count is greater that 1
        // we will ignore 1 character - hence making count even which
        // can be arranged in palindrome fashion
        else if(it.second%2==1 && it.second>1)
            ans += it.second-1;
            
        // We can add one-single mismatching character at middle of palindrome string
        // adding one character at middle of forming palindrome string
        if(it.second%2==1 && odd==false) 
        {
            ans++;
            odd = true;
        }
        
    }
    
    return ans;
}
    


// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<longestPalindrome("aa")<<"\n";
	cout<<longestPalindrome("abbcaadabac")<<"\n";
	cout<<longestPalindrome("abccccdd")<<"\n";
	
	return 0;
}
