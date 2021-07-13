/**
 * Google
 * Given a string s, return all possible partitions of s such that each substring is a palindrome.
 * Order of characters matters.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since July 13, 2021
 */



/** function is_palindrome
 * @param string, denoting the string
 * @param int, denoting the starting index
 * @param int, denoting the ending index
 * 
 * Checks if the substring starting from 'st' and ending at 'en' is palindromic or not
 */ 
bool is_palindrome(string s, int st, int en)
{
    string t = s.substr(st, en-st+1);
    string m = t;
    reverse(m.begin(), m.end());
    return t == m;
}



/** function get_answer
 * @param vector<vector<string>>, to store all palindromic partitions of the string
 * @param vector<string>, to store all palindromic partitions for current level
 * @param string, denoting the string whose palindromic partitions are to be done
 * @param int, starting index
 * @param int, ending index
 */ 
void get_answer(vector<vector<string>> &ans, vector<string> &temp, string s, int start, int end)
{
    
    /** Logic :
     * 
     * If start becomes greater than or equal to end, it means we have got all palindromic partitions for
     * current level, hence push temp vector into ans vector and return
     * 
     * Else, iterate from start to end, and check for every substring if it is palindromic, if it is - push it
     * into temp vector and make recursive call with starting index increased by 1.
     * At the end, pop the last element out of the vector - for backtracking
     * 
     */ 
    
    if(start >= end)
    {
        ans.push_back(temp);
        return;
    }
    
    for(int i=start;i<end;i++)
    {
        if(is_palindrome(s, start, i))
        {
            string pal = s.substr(start, i-start+1);
            temp.push_back(pal);
            get_answer(ans, temp, s, i+1, end);
            temp.pop_back();
        }
    }
}



/** function partition
 * @param string, denoting the string whose palindromic partitions are to be done
 * @return vector<vector<string>>, denoting all palindromic partitions of the string
 */ 
vector<vector<string>> partition(string s) 
{
    
    /** Logic :
     * 
     * We call a recursive-backtracking function 'get_answer' to store all palindromic partitions into
     * answer vector and return it as solution
     * 
     */ 
    
    vector<vector<string>> ans;
    
    vector<string> temp;
    
    get_answer(ans, temp, s, 0, s.length());
    
    return ans;
}



/** function print_answer
 * @param vector<vector<<string>>, denoting the array which stores all palindromic partitions
 *
 * displays the contents on vector on console
 *
 */
void print_answer(vector<vector<string>> v)
{
	for(vector<string> t : v)
	{
		for(string i : t)
			cout<<i<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}



// main function - driver code
int main()
{
	vector<vector<string>> ans;
	
	
	// TESTCASE
	
	ans = partition("abcba");
	print_answer(ans);
	
	
	return 0;
}
