/**
 * Facebook
 * Given two strings s and t return whether or not s is an anagram of t.
 */

#include<iostream>
#include<algorithm>
using namespace std;

/**
 * @author keshav kabra
 * @since May 27, 2021
 */



/** function isAnagram_sorting
 * @param string, denoting first string
 * @param string, denoting second string
 * uses sort method
 * sort the two strings alphabetically using inbuilt function sort
 * and compare if they are equal
 */ 
bool isAnagram_sorting(string s, string t) 
{
    if(s == t)
        return true;
    
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    return s==t;
}



/** function isAnagram_map
 * @param string, denoting first string
 * @param string, denoting second string
 * uses hash table
 * Make an array of size 26 and for every character of first string
 * increment the count of that position by 1 and for every character 
 * of second string decrement that count by 1
 * Now if at the end, all positions of array is 0, strings are anagrams
 * else not 
 */ 
bool isAnagram_map(string s, string t)
{
	if (s.length() != t.length()) {
        return false;
    }
    int counter[26] = {0};
    for (int i=0; i<s.length(); i++) 
	{
        counter[s[i] - 'a']++;
        counter[t[i] - 'a']--;
    }
    
    for(int i=0;i<26;i++)
    {
    	if(counter[i] != 0)
    		return false;
	}
    return true;
}


// main function - driver code
int main()
{
	// TESTCASES
	
	cout<<isAnagram_sorting("cat", "tac")<<"\n";
	cout<<isAnagram_sorting("listen", "silent")<<"\n";
	cout<<isAnagram_sorting("program", "function")<<"\n";
	
	cout<<"\n";
	
	cout<<isAnagram_map("cat", "tac")<<"\n";
	cout<<isAnagram_map("listen", "silent")<<"\n";
	cout<<isAnagram_map("program", "function")<<"\n";
	
	return 0;
}

