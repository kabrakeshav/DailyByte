/** 
 * Given a string s, remove the minimum number of parentheses to make s valid. Return all possible 
 * results.
 */

#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;


/**
 * @author keshav kabra
 * @since October 28, 2021
 */



// refer : https://www.youtube.com/watch?v=Cbbf5qe5stw



/** function get_min
 * @param string, denoting the string
 * @return int, minimum number of brackets to be removed to make string balanced parentheses string
 * 
 * -> If returned 0, it means string is alredy balanced
 * 
 */ 
int get_min(string str)
{
    stack<char> stk;
    
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '(')
            stk.push('(');
        else if(str[i] == ')')
        {
            if(stk.size() == 0 || stk.top() == ')')
                stk.push(')');
            else if(stk.top() == '(')
                stk.pop();
        }
    }
    return stk.size();
}



/** function get_answer
 * @param string, denoting the string
 * @param int, min number of brackets to be removed from string to make it balanced
 * @param set<string>, to store balanced strings
 * @param unordered_map, acting as cache to prevent re-processing of same string
 */ 
void get_answer(string str, int min_remove, set<string> &st, unordered_map<string, int> &mp)
{
    
    // if string is alredy processed, return
    if(mp[str] != 0)
        return;
    else
        mp[str] = 1;
    
    
    // if string is balanced and min_remove is 0, insert into set and return
    if(min_remove == 0)
    {
        if(get_min(str) == 0)
            st.insert(str);
        
        return;
    }
    
    
    // recursive calls
    for(int i=0;i<str.length();i++)
    {
        string left = str.substr(0, i);
        string right = str.substr(i+1, str.length()-1);
        get_answer(left+right, min_remove-1, st, mp);
    }
}



/** function removeInvalidParentheses
 * @param string, string
 * @return vector<string>, all balanced strings that can be formed
 */ 
vector<string> removeInvalidParentheses(string s)
{   
    if(s.size() == 0)
        return {};
    
    int min_remove = get_min(s);
    
    set<string> ans;
    unordered_map<string, int> mp;
    get_answer(s, min_remove, ans, mp);
    
    vector<string> res(ans.begin(), ans.end());
    return res; 
}



/** function display_answer
 * @param vector, denoting the array
 * prints the given array on the console
 */ 
void display_answer(vector<string> ans)
{
	for(string str : ans)
        cout<<str<<" ";
    cout<<"\n";
}



// main function - driver code
int main()
{
	vector<string> ans;
	
	
	// TESTCASES
	
	ans = removeInvalidParentheses("(()()()");
	display_answer(ans);
	
	ans = removeInvalidParentheses("()()()");
	display_answer(ans);
	
	ans = removeInvalidParentheses("()((((((()l(");
	display_answer(ans);
	
	return 0;
}

