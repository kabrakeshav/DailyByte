/**
 * Given a string s, return the length of the longest substring that contains only unique characters.
 */

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


/**
 * @author keshav kabra
 * @since October 16, 2021
 */



/** function lengthOfLongestSubstring
 * @param string, given string
 * @return int, length of longest substring that contains unique characters only
 */ 
int lengthOfLongestSubstring(string s) 
{
    
    /** Logic :
     * 
     * Maintain two pointer variables (a_pointer and b_pointer) to point to first (left) and last (right) 
     * characters of current non-repeating substring respectively.
     * Also, maintain a set to take encounter only of unique (non-repeating) characters
     * 
     * We iterate on the string as long as b_pointer is less than string's length. If the current character
     * is not present in the set, it means it is a unique character in current substring, hence add it
     * to the set and alter 'result' value as required
     * 
     * If the character is present in the map, the a_pointer will be poiting to the last occurence of 
     * that character, hence, erase that character from map and increment a_pointer to take next 
     * character into consideration.
     * 
     */ 
    
    if(s.empty())
        return 0;
    
    int a_pointer = 0;
    int b_pointer = 0;
    int result = 0;
    
    unordered_set<char> mp;
    
    while(b_pointer < s.length())
    {
        if(mp.find(s[b_pointer]) == mp.end())
        {
            mp.insert(s[b_pointer]);
            b_pointer++;
            result = max(result, (int) mp.size());
        }
        else
        {
            mp.erase(mp.find(s[a_pointer]));
            a_pointer++;
        }
    }
    
    return result;
}



// main function - driver code
int main()
{
	string str;
	
	
	// TESTCASES
	
	str = "ababbc";
	cout<<lengthOfLongestSubstring(str)<<"\n";
	
	str = "abcdssa";
	cout<<lengthOfLongestSubstring(str)<<"\n";
	
	return 0;
}
