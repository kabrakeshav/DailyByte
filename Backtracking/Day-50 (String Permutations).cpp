/**
 * Amazon
 * Given a string s consisting of only letters and digits, 
 * where we are allowed to transform any letter to uppercase or lowercase, 
 * return a list containing all possible permutations of the string.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since July 7, 2021
 */



/** function get_answer
 * @param input, denoting the input string
 * @param output, denoting the string which stores one permutation
 * @param vector<string>, to store all permutations of string
 *     ( passed with reference )
 */ 
void get_answer(string input, string output, vector<string> &ans)
{
    
    /** Logic :
     * 
     * If the length of string input is 0, it means we have found one permutation of the string (which is 
     * stored in 'output'), hence push 'output' to vector.
     * 
     * Else, create two string output1 and output2 initialized with string output.
     * 
     * Now, if the first character of string input is a digit (0-9), we have to simply append the digit to both
     * output1 and output2 (no permutations can be applied on digits)
     * 
     * Else (first letter of string input is character), we append the letter's lower-case form to output1 and
     * upper-case form to output2 and delete the first character of string input ( as this character is 
     * encountered now )
     * 
     * Now, to prevent duplicate strings to be stored in array, if output1 and output2 are equal, we make a
     * single recursive call.
     * Else, make two recursive calls with output1 and output2 respectively.
     * 
     * Hence, in each call, we are taking one character of string input and making its permutations.
     *
     */
    
    if(input.length() == 0)
    {
        ans.push_back(output);
        return;
    }
    
    // make two strings initialized with output
    string output1 = output;
    string output2 = output;
    
    // if first letter is digits, simply append
    if(isdigit(input[0]))
    {
        output1 += input[0];
        output2 += input[0];
    }
    
    // first letter is a character
    else
    {
        output1 += tolower(input[0]);
        output2 += toupper(input[0]);
    }
    
    // delete first letter of input string - it has been encountered
    input.erase(input.begin()+0);
    
    // logic to prevent duplicate strings to be stored in array
    
    if(output1 == output2)
        get_answer(input, output1, ans);
    else
    {
        get_answer(input, output1, ans);
        get_answer(input, output2, ans);
    }    
        
} 
 


/** function letterCasePermutation
 * @param string, denoting the string whose permutations we need to find
 * @return vector<string>, denoting the array which stores all permutations of string
 */ 
vector<string> letterCasePermutation(string S) 
{
    
    /** Logic :
     * 
     * If string is empty, return empty  vector
     * 
     * Else, create a string 'output' (which stores each individual permutations) and call
     * a recursive function get_answer.
     * Return the modified vector
     * 
     * Time complexity  : O(N * 2^N) -- for a string of length N there may be 2^N permutations
     * Space complexity : O(N)       -- for string vector
     * 
     */ 
    
    vector<string> ans;
    if(S.length() == 0)
        return ans;
    
    string output = "";
    get_answer(S, output, ans);
    return ans;
}



/** function print_answer
 * @param vector<string>, denoting the array which stores all permutations of string
 *
 * displays the contents on vector on console
 *
 */
void print_answer(vector<string> v)
{
	for(string str : v)
		cout<<str<<" ";
	cout<<"\n";
}



// main function - driver code
int main()
{
	vector<string> ans;
	
	// TESTCASE - 1
	
	ans = letterCasePermutation("c7w2");
	print_answer(ans);
	
	
	return 0;
}
