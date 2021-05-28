/**
 * Microsoft
 * Given a string, return the index of its first unique character. 
 * If a unique character does not exist, return -1.
 */

#include<iostream>
#include<unordered_map>
using namespace std;

/**
 * @author keshav kabra
 * @since May 28, 2021
 */



/** function firstUniqChar
 * @param string, denoting the string to operate upon
 * @return int, index of first unique character or -1
 * 
 * Logic :
 * We store the frequency of each character of string in a map with
 * that character as key and its frequency as value.
 * Now, iterate over this map and find if any of its value is 1 (which means
 * that particular character only occured once in the string).
 * Find its index in the string and if no such value (=1) is found
 * return -1
 */ 
int firstUniqChar(string s) 
{
    unordered_map<char,int> mp;
    
    for(char ch : s)
        mp[ch]++;
    
    int min_index = -1;
    for(auto it : mp)
    {
        if(it.second == 1)
        {
            min_index = s.find(it.first);
        }
    }
    return min_index;          
}


// main function - driver code
int main()
{
	// TESTCASES
	
	cout<<firstUniqChar("abcabd")<<"\n";
	cout<<firstUniqChar("thedailybyte")<<"\n";
	cout<<firstUniqChar("developer")<<"\n";
	
	return 0;
}

