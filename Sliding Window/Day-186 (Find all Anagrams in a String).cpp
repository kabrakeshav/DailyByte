/**
 * Given a string s and a string p, return all the starting indices of p’s anagrams within s.
 * Both strings will contain at least one character and will only contain lowercase alphabetical 
 * characters.
*/

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since December 13, 2021
 */



/** function findAnagrams
 * @param string, denoting the given main string
 * @param string, pattern string
 * @return vector<int>, array containing all the starting indices of p’s anagrams within s
 */ 
vector<int> findAnagrams(string s, string p) 
{
    int N1 = s.length();
    int N2 = p.length();
    
    vector<int> ss(26, 0), pp(26, 0), ans;
    
    if(N1 < N2)
        return ans;
    
    // fill pp, vector of counters for pattern string and ss, vector of counters for the sliding window
    for(int i=0;i<N2;i++)
    {
        ss[s[i]-'a']++;
        pp[p[i]-'a']++;
    }
    
    if(ss == pp)
        ans.push_back(0);
    
    
    // here window is moving from left to right across the string. 
    // window size is p.size(), so s.size()-p.size() moves are made 
    for(int i=N2; i<N1; i++)
    {
        // window extends one step to the right. counter for s[i] is incremented 
        ss[s[i]-'a']++;
        
        // since we added one element to the right, one element to the left should be discarded. 
        //counter for s[i-p.size()] is decremented
        ss[s[i-N2]-'a']--;
        
        
        // if after move to the right, the anagram can be composed, add new position of window's left point to the result 
        if(ss == pp)
            ans.push_back(i-N2+1);
    }
    
    return ans;
}



/** function display_answer
 * Displays given vector on console
 */ 
void display_answer(vector<int> ans) 
{
	for(int i : ans)
		cout<<i<<" ";
	cout<<"\n";
}
    
    
    
// main function - driver code
int main()
{
	vector<int> ans;
	
	ans = findAnagrams("abcbabc", "abc");
	display_answer(ans);
	
	ans = findAnagrams("cbaebabacd", "abc");
	display_answer(ans);
	
	ans = findAnagrams("abab", "ab");
	display_answer(ans);
	
	return 0;
}
