/**
 * Given a list of words, return the top k frequently occurring words.
 * Note: If two words occur with the same frequency, then the alphabetically smaller word should 
 * come first.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since October 20, 2021
 */



/** function comp
 * @param pair, first pair of string and its count (int) in array
 * @pair pair, second pair of string and its count (int) in array
 * @return bool, if first pair is smaller or lexicographically-smaller than second one
 */ 
static bool comp(pair<string,int> &p1, pair<string,int> &p2)
{
    if(p1.second == p2.second)
        return lexicographical_compare(p1.first.begin(), p1.first.end(), 
										p2.first.begin(), p2.first.end());
    
    return p1.second > p2.second;
}



/** function topKFrequent
 * @param vector, array of strings
 * @param int, value of k
 * @return vector, top k frequently occurring words in given array
 */ 
vector<string> topKFrequent(vector<string>& words, int k) 
{
    unordered_map<string,int> mp;
    
    for(string str : words)
        mp[str]++;
    
    vector<pair<string,int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), comp);
    
    vector<string> ans;
    for(auto it : v)
    {
        if(ans.size() == k)
            break;
        else
            ans.push_back(it.first);
    }
    
    return ans;
}

 
 
/** function display_answer
 * @param vector, denoting the array
 * prints the given array on the console
 */ 
void display_answer(vector<string> ans)
{
	for(string i : ans)
        cout<<i<<" ";
    cout<<"\n";
}
 


// main function - driver code
int main()
{
	vector<string> v, ans;
	
	v = {"the", "daily", "byte", "byte"};
	ans = topKFrequent(v, 1);
	display_answer(ans);
	
	v = {"coding", "is", "fun", "code", "coding", "fun"};
	ans = topKFrequent(v, 2);
	display_answer(ans);
	
	return 0;
}
