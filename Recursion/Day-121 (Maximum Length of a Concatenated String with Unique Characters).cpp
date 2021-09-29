/**
 * You are given an array of strings arr. A string s is formed by the concatenation of a subsequence 
 * of arr that has unique characters.
 * 
 * Return the maximum possible length of s.
 * 
 * A subsequence is an array that can be derived from another array by deleting some or no elements 
 * without changing the order of the remaining elements.
 */


#include<iostream>
#include<vector>
#include<set>
using namespace std;


/**
 * @author keshav kabra
 * @since September 29, 2021
 */



/** function is_unique
 * @param string, string to be compute
 * @return bool, whether given string contains all unique characters or not
 */ 
bool is_unique(string str)
{
    set<char> st;
    for(char ch : str)
    {
        if(st.find(ch) != st.end())
            return false;
        st.insert(ch);
    }
    return true;
}



/** function get_answer
 * @param string, string which contains the actual longest phrase
 * @param vector<string>, given array of strings
 * @param int, denoting start of array (for recursive calls)
 * @param int, for storing the length of answer string
 */ 
void get_answer(string str, vector<string> &arr, int start, int &ans)
{
    
    /** Logic :
     * 
     * If string contains duplicate chars, we do not have to consider it, hence return
     * 
     * If the length of 'str' (which stores actual answer-string) is greater than 'ans', update value of 'ans'
     * 
     * Append the current string of array to 'ans' and make recursive call for all remaining strings in array
     * 
     */ 
    
    if(is_unique(str) == false)
        return;
        
    if(str.length() > ans)
        ans = str.length();
    
    for(int i=start;i<arr.size();i++)
        get_answer(str+arr[i], arr, i+1, ans);
}



/** function maxLength
 * @param vector<string>, array of string 
 * @return int, max length of phrase formed by strings of vector such that only unique char strings are considered
 */ 
int maxLength(vector<string>& arr) 
{
    int ans = 0;
    get_answer("", arr, 0, ans);
    return ans;
}



// main function - driver code
int main()
{
	vector<string> v;
	
	
	// TESTCASES
	
	v = {"the", "dog", "ran"};
	cout<<maxLength(v)<<"\n";
	
	v = {"the", "eagle", "flew"};
	cout<<maxLength(v)<<"\n";
	
	return 0;
}
