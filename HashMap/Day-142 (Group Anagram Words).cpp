/**
 * Given a list of strings, return a list of strings containing all anagrams grouped together.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since October 26, 2021
 */



/** function groupAnagrams
 * @param vector<string>, array of string to be grouped
 * @return vector<vector<string>>, anagram-grouped array of strings
 */ 
vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    unordered_map<string,vector<string>> mp;
    
    for(string str : strs)
    {
        string t = str;
        sort(t.begin(), t.end());
        mp[t].push_back(str);
    }
    
    vector<vector<string>> ans;
    for(auto it : mp)
    {
        ans.push_back(it.second);
    }
    
    return ans;
}
    


/** function display_answer
 * @param vector, denoting the array of grouped anagrams
 * prints the given array on the console
 */ 
void display_answer(vector<vector<string>> ans)
{
	for(vector<string> v : ans)
	{
		for(string str : v)
			cout<<str<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}



// main function - driver code
int main()
{
	vector<string> v;
	vector<vector<string>> ans;
	
	
	// TESTCASES
	
	v = {"car", "arc", "bee", "eeb", "tea"};
	ans = groupAnagrams(v);
	display_answer(ans);
	
	v = {"eat","tea","tan","ate","nat","bat"};
	ans = groupAnagrams(v);
	display_answer(ans);
	
	return 0;
}
