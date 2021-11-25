/**
 * Given a string paragraph and a string array of the banned words banned, return the most frequent 
 * word that is not banned. It is guaranteed there is at least one word that is not banned, and that 
 * the answer is unique.
 * The words in paragraph are case-insensitive and the answer should be returned in lowercase.
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


/**
 * @author keshav kabra
 * @since November 25, 2021
 */



/** function comp
 * Returns whether frequency of first string is greater than that of other
 */ 
static bool comp(pair<string,int> &p1, pair<string,int> &p2)
{
    return p1.second > p2.second;
}



/** function mostCommonWord
 * @param string, given paragraph
 * @param vector<string>, list of banned words
 * @return string, most frequent string which is not in banned list
 */ 
string mostCommonWord(string paragraph, vector<string>& banned) 
{
    transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
    
    unordered_map<string,int> mp;
    
    vector<string> v;
    string str = "";
    
    // splitting string based on any non-alphabetic character
    for(char ch : paragraph)
    {
        if(ch>=97 && ch<=122)
            str += ch;
        else
        {
            if(str != "")
                v.push_back(str);
            str = "";
        }
    }
    if(str != "")
        v.push_back(str);
    
    // count of strings in map
    for(string s : v)
        mp[s]++;
    
    vector<pair<string,int>> z(mp.begin(), mp.end());
    sort(z.begin(), z.end(), comp);
    
    
    for(auto it : z)
    {
        if(find(banned.begin(), banned.end(), it.first) == banned.end())
            return it.first;
    }
    
    return "";
}
    
    
    
// main function - driver code
int main()
{
	string paragraph = "";
	vector<string> banned;
	
	
	// TESTCASES
	
	paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
	banned  = {"hit"};
	cout<<mostCommonWord(paragraph, banned)<<"\n";
	
	paragraph = "The daily, the byte Daily.";
	banned  = {"the"};
	cout<<mostCommonWord(paragraph, banned)<<"\n";
	
	return 0;
}
