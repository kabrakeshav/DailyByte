/**
 * Amazon 
 * Given two strings, passage and text return whether or not the characters in text can be used 
 * to form the given passage.
 * Note: Each character in text may only be used once and passage and text will only contain 
 * lowercase alphabetical characters.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since August 21, 2021
 */



/** function passage_from_text
 * @param string, dentoing string passage
 * @param string, dentoing string text
 * @return bool, whether or not the characters in 'text' can be used to form the given 'passage'
 */ 
bool passage_from_text(string passage, string text)
{
    
    /** Logic :
     * 
     * We store the frequency of each character in 'text' string into a map (since string can only contain
     * lowercase alphabets, we make a vector of size 26)
     * Fill the corresponding indices with the frequency of characters in string text
     * 
     * Now, we iterate on string passage; if in the map, the frequency of current character is greater 
     * than 0, we decrement the frequency by 1 ( as one char can only be used one time )
     * If frequency is less than or equal to 0, we return false.
     * If we come out of loop, passage can be formed using text, hence return true
     * 
     * 
     * Time complexity  : O(N) -- Entire string is traversed
     * Space complexity : O(N) -- vector to store frequencies
     */ 
    
	vector<char> map(26, 0);
	for(char ch : text)
		map[ch-'a']++;
	
	for(char ch : passage)
	{
		if(map[ch-'a'] > 0)
			map[ch-'a']--;
		else
			return false;
	}
	return true;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	cout<<passage_from_text("bat", "cat")<<"\n";
	cout<<passage_from_text("dog", "didnotgo")<<"\n";
	
	return 0;
}
