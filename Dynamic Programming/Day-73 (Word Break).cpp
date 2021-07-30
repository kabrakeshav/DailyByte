/**
 * Amazon
 * Given a string s and a list of words representing a dictionary, 
 * return whether or not the entirety of s can be segmented into dictionary words.
 * All characters in s and the dictionary are lowercase.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since July 30, 2021
 */



// global map for memoization - acting as cache
// used in function wordBreak
unordered_map<string,bool> mp;



/** function wordBreak
 * @param string, the string to be mede
 * @param vector<string>, dictionary
 * @return bool, if string can be made from the dictionary
 */
bool wordBreak(string s, vector<string>& dict) 
{
    
    /** Logic :
     * 
     * https://youtu.be/LPs6Qo5qlJM
     * 
     * We maintain a map, which acts as cache, for telling whether the current substring was previously
     * generated, and if yes, will it participate in word-break (true)
     * 
     * We iterate on every substring of s, and check if it is present is given dictionary, if it is present,
     * then make recursive call and find solution
     * 
     */ 
    
	if(find(dict.begin(), dict.end(), s) != dict.end())
        return true;
    
    if(mp.find(s) != mp.end())
        return mp[s];
    
    for(int i=0;i<s.size();i++)
    {
        string left = s.substr(0, i+1);
        if(find(dict.begin(), dict.end(), left) != dict.end() && wordBreak(s.substr(i+1), dict)) {
            mp.insert({s, true});
            return true;
        }
    }
    
    mp.insert({s, false});
    return false;
}



// main function - driver code
int main()
{
	vector<string> dict;
	
	
	// TESTCASES
	
	mp.clear();
	dict = {"the", "daily", "byte"};
	cout<<wordBreak("thedailybyte", dict)<<"\n";
	
	mp.clear();
	dict = {"plane", "pizza"};
	cout<<wordBreak("pizzaplanet", dict)<<"\n";
	
	
	return 0;
}
