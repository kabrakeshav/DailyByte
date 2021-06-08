/**
 * Google
 * Given a string only containing the following characters (, ), {, }, [, and ] 
 * return whether or not the opening and closing characters are in a valid order.
 */

#include<iostream>
#include<stack>
using namespace std;

/**
 * @author keshav kabra
 * @since June 8, 2021
 */



/** function isValid
 * @param string, denoting the string to be validated
 * @return bool, returning if string is valid or not
 */ 
bool isValid(string str) 
{
    
    /** Logic :
     * if string is starting with any closing brackets, simply return false.
     * Else, we will make a stack and traverse the string.
     * 
     * We will push every opening bracket into the stack
     * For closing bracket, either if stack is empty or corresponding opening
     * bracket is not the top of stack, we return false.
     * 
     * After, traversing the string, if stack is not empty, it means there are 
     * some mis-matches, hence return false.
     * Otherwise, return true.
     * 
     * Time complexity : O(n)  -  traversing the whole string
     * Space complexity : O(n)  -  made an auxiliary stack to hold characters
     */ 
    
    if(str.length()==0 || str[0]==')' || str[0]=='}' || str[0]==']')
        return false;

    stack<char> stk;
    for(char ch : str)
    {
        if(ch=='(' || ch=='{' || ch=='[')
            stk.push(ch);
        else if(ch == ')')
        {
            if(stk.empty())
                return false;
            char temp = stk.top();
            if(temp != '(')
                return false;
            stk.pop();
        }
        else if(ch == '}')
        {
            if(stk.empty())
                return false;
            char temp = stk.top();
            if(temp != '{')
                return false;
            stk.pop();
        }
        else if(ch == ']')
        {
            if(stk.empty())
                return false;
            char temp = stk.top();
            if(temp != '[')
                return false;
            stk.pop();
        }
    }
    
    if(!stk.empty())
        return false;
        
    return true;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<isValid("(){}[]")<<"\n";
	cout<<isValid("(({[]}))")<<"\n";
	cout<<isValid("{(})")<<"\n";
	
	return 0;
}
