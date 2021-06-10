/**
 * Facebook
 * Given a string s containing only lowercase letters, 
 * continuously remove adjacent characters that are the same and return the result.
 */


#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

/**
 * @author keshav kabra
 * @since June 10, 2021
 */


/** function remove_duplicates
 * @param string, denoting the string from which we need to remove the adjacent duplicates
 * @return string, denoting the string after removal of adjacent duplicates
 */ 
string remove_duplicates(string S) 
{
    
    /** Logic :
     * Make a stack and iterate through the string, if either stack is empty or
     * top of stack is not current character, we push into stack (sice adjacent characters 
     * not matched)
     * If the top of stack is equal to current character, we pop from stack until the top of
     * stack is not equal to current character or stack becomes empty.
     * 
     * After the loop, store the characters in stack into answer string, reverse it and return
     * it.
     * 
     * Time complexity : O(n)  -  Iterate over full string
     * Space complexity : O(n) -  Used stack to store characters
     */ 
    
    stack<char> stk;
    
    for(char ch : S)
    {
        if(stk.empty())
            stk.push(ch);
        else if(stk.top() != ch)
            stk.push(ch);
        else if(stk.top() == ch)
        {
            while(!stk.empty() && stk.top()==ch)
                stk.pop();
        }
    }
    
    string ans = "";
    while(!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<remove_duplicates("abccba")<<"\n";
	cout<<remove_duplicates("foobar")<<"\n";
	cout<<remove_duplicates("abccbefggfe")<<"\n";
	
	return 0;
}
