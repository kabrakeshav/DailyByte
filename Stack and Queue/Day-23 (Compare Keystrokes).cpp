/**
 * Amazon
 * Given two strings s and t, which represents a sequence of keystrokes, 
 * where # denotes a backspace, return whether or not the sequences produce the same result.
 */

#include<iostream>
#include<stack>
using namespace std;


/**
 * @author keshav kabra
 * @since June 9, 2021
 */
 

/** function backspace_compare
 * @param string, denoting first string
 * @param string, denoting second string
 * @return bool, if the string are equal 
 *   after removing backspaces (denoted by '#')
 */ 
bool backspace_compare(string S, string T) 
{
    
    /** Logic :
     * Make two stacks (one for each string), now iterate through the string,
     * if chracter is alpabet, push into the stack, and if it is '#' (backspace), 
     * then pop a character out from the stack (if any)
     * 
     * Thus, after oterating on both strings, we have the stack containing strings
     * without any backspaces ('#')
     * 
     * Now, iterate over both stacks, if top matches, then pop the current top and compare
     * next characters, else, since, characters mis-matched, return false.
     * 
     * Afer iteration, if stacks are empty, return true (both string are equal), else
     * return false
     * 
     * Time complexity : O(n)  -  iteration over full strings
     * Space complexity : O(n)  -  stacks to store characters
     */ 
    
    stack<char> stk1, stk2;
    
    for(char ch : S)
    {
        if(ch != '#')
            stk1.push(ch);
        if(ch=='#' && !stk1.empty())
            stk1.pop();
    }
    
    for(char ch : T)
    {
        if(ch != '#')
            stk2.push(ch);
        if(ch=='#' && !stk2.empty())
            stk2.pop();
    }
    
    while(!stk1.empty() && !stk2.empty())
    {
        if(stk1.top() == stk2.top()) {
            stk1.pop();
            stk2.pop();
        }
        else
            return false;
    }
    
    if(stk1.empty() && stk2.empty())
        return true;
        
    return false;
}



// main function - driver code 
int main()
{
	
	// TESTCASES
	
	cout<<backspace_compare("ABC#", "CD##AB")<<"\n";
	cout<<backspace_compare("como#pur#ter", "computer")<<"\n";
	cout<<backspace_compare("cof#dim#ng", "code")<<"\n";
	
	return 0;
}
