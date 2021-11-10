/**
 * Given a string s and a value k, return the length of the longest substring that contains at most 
 * k distinct character.
 */

#include<iostream>
#include<unordered_map>
using namespace std;


/**
 * @author keshav kabra
 * @since November 10, 2021
 */



/** function lengthOfLongestSubstringKDistinct
 * @param string, given string
 * @param int, integet denoting max number of distinct characters allowed
 * @param int, length of longest substring with atmost 'k' distinct characters
 * 
 * REFER : https://www.youtube.com/watch?v=qOPxRziTxEQ
 * 
 */ 
int lengthOfLongestSubstringKDistinct(string &str, int k)
{
    int i = -1, j = -1;
    int ans = 0;
    int N = str.length();

    unordered_map<char, int> mp;

    while(true)
    {
        bool f1=false, f2=false;

        while(i < N-1)
        {
            f1 = true;

            i++;
            mp[str[i]]++;

            if(mp.size() <= k)
                ans = max(ans, i-j);
            else
                break;
        }

        while(j < i)
        {
            f2 = true;

            j++;
            if(mp[str[j]] == 1)
                mp.erase(str[j]);
            else
                mp[str[j]]--;
            
            if(mp.size() > k)
                continue;
            else
            {
                ans = max(ans, i-j);
                break;
            }
        }

        if(f1==false && f2==false)
            break;
    }

    return ans;
}



// main function - driver code
int main()
{
	string str;
	
	
	// TESTCASES
	
	str = "abccccd";
	cout<<lengthOfLongestSubstringKDistinct(str, 3)<<"\n";
	
	str = "rrr";
	cout<<lengthOfLongestSubstringKDistinct(str, 1)<<"\n";
	
	str = "WORLD";
	cout<<lengthOfLongestSubstringKDistinct(str, 4)<<"\n";
	
	
	return 0;
}
