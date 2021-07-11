/**
 * Facebook
 * Given an integer N, where N represents the number of pairs of parentheses.
 * Return a list containing all possible well-formed parentheses you can create.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since July 11, 2021
 */



/** function get_answer
 * @param int, denoting the number of open parentheses to be added
 * @param int, denoting the number of close parentheses to be added
 * @param string, denoting the answer string (one particular string of answer)
 * @param vector, array to store all possible answers
 */ 
void get_answer(int open, int close, string output, vector<string> &v)
{
    
    /** Logic :
     * 
     * if open and close, both are equal to 0, it means we have generated a well-formed parentheses string,
     * hence push it to answer vector.
     * 
     * If open is not equal to zero, we can add one or more '(' to the output, hence add one '(' to the
     * output string and recursively call 'get_answer' with param 'open' decremented by 1.
     * 
     * Similarily, if close is not equal to zero, we can add one or more ')' to the output, hence 
     * add one ')' to the output string and recursively call 'get_answer' with param 'close' decremented by 1.
     * 
     */ 
    
    if(open==0 && close==0)
    {
        v.push_back(output);
        return;
    }
    if(open != 0)
    {
        string output1 = output+"(";
        get_answer(open-1, close, output1, v);
    }
    if(close > open)
    {
        string output2 = output+")";
        get_answer(open ,close-1, output2, v);
    }
    
}



/** function generateParenthesis
 * @param int, denoting the number of pairs of parentheses (i.e. ”(“ and ”)”) to be generated
 * @return vector, denotinga list containing all possible well-formed parentheses
 */ 
vector<string> generateParenthesis(int n) 
{
    
    /** Logic :
     * 
     * We will call a recursive-backtracking function 'get_answer' to calculate all possible
     * answers.
     * 
     * Time complexity  : O(2^N)            since for each character we have two options - '(' or ')'
     * Space complexity : O(2*N*k) ~ O(N*k) since we have k valid strings and each has length 2*N in list
     * 
     */ 
    
    vector<string> ans;
    if(n == 0)
    {
        ans.push_back("");
        return ans;
    }
    
    string output = "";
    get_answer(n, n, output, ans);
    return ans;
}



/** function print_answer
 * @param vector<int>, denoting the array which stores all permutations of parentheses 
 *
 * displays the contents on vector on console
 *
 */
void print_answer(vector<string> v)
{
	for(string str : v)
		cout<<str<<"\t ";
	cout<<"\n";
}



// main function - driver code
int main()
{
	vector<string> ans;
	
	
	// TESTCASE
	
	ans = generateParenthesis(3);
	print_answer(ans);
	
	return 0;
}
