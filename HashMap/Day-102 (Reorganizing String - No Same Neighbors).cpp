/** Facebook
 * Given a string, check if it can be modified such that no two adjacent characters are 
 * the same. 
 * If it is possible, return any string that satisfies this condition and if it is not possible 
 * return an empty string.
 */

#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since September 10, 2021
 */



/** function comp
 * @param pair<char, char>, first pair of char-count
 * param pair<char, char>, second pair of char-count
 * @return bool, if first pair's second value if greater than second pair's second value
 * Help to sort the unordered_map by decreasing order of frequency of count of characters
 */ 
static bool comp(pair<char,int> &p1, pair<char,int> &p2)
{
    return p1.second > p2.second;
}



/** function reorganizeString
 * @param string, given string
 * @return string, modified string in which no two adjacent characters are the same
 */ 
string reorganizeString(string S)
{
    int N = S.length();
    
    
    // getting count of each character of string into unordered_map(char, count)
    unordered_map<char, int> mp;
    for(char ch : S)
        mp[ch]++;
    
    
    // sorting the map by decreasing order of count of characters
    vector<pair<char, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), comp);
    
    
    // result string - made of spaces of length N
    string str(N, ' ');
    
    // iterating on each pair of the map
    int t = 0;
    for(auto it : v)
    {
        
        // if value of greater than half of length of string, we can not put characters in required fashion
        // hence return empty string
        if(it.second > (N+1)/2)
            return "";
        
        // putting characters to result string    
        while(it.second > 0)
        {
            
            // if index goes beyond the original string length, diver it back to 1 (we start from 0 hence at first,
            // we are filling even indices only), not revert back to fill odd indices
            if(t >= N)
                t = 1;
            str[t] = it.first;
            t += 2;
            it.second--;
        }
    }
    
    // return resul string
    return str;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<reorganizeString("abb")<<"\n";
	cout<<reorganizeString("xxxy")<<"\n";
	
	return 0;
}

