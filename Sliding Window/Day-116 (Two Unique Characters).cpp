/** 
 * Given a string s, return the length of the longest substring containing at most two distinct characters.
 * Note: You may assume that s only contains lowercase alphabetical characters.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since September 26, 2021
 */



/** function lengthOfLongestSubstringTwoDistinct
 * @param string, string
 * @return int, max length of substring with atmost 2 distinct characters
 */ 
int lengthOfLongestSubstringTwoDistinct(string str) 
{
    
    // use concept of sliding window
    
    if(str.length() <= 2)
        return str.length();

    int len = str.length();
    int ans = 0;

    for(int i=0;i<len;i++)
    {
        int temp = 0;
        char a = ' ', b = ' ';
        for(int j=i;j<len;j++)
        {
            if(a==' ' || b==' ' || a==str[j] || b==str[j])
            {
                temp++;
                if(a == ' ' || a == str[j])
                    a = str[j];
                else if(b == ' ' || b == str[j])
                    b = str[j];
            }
            
            else
                break;
        }
        ans = max(ans, temp);
    }

    return ans;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<lengthOfLongestSubstringTwoDistinct("aba")<<"\n";
	cout<<lengthOfLongestSubstringTwoDistinct("abca")<<"\n";
	cout<<lengthOfLongestSubstringTwoDistinct("cabacbbbabbb")<<"\n";
	cout<<lengthOfLongestSubstringTwoDistinct("aaa")<<"\n";
	
	return 0;
}
