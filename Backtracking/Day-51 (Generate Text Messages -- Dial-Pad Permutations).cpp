/**
 * Google
 * Given a string containing digits from 2-9 inclusive, each number maps to set of characters just like on a dial pad.
 * Return all possible letter combinations that the number could represent if pressed in that order(any number can be pressed any non-zero number of times). 
 * Return the answer in any order.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


/**
 * @author keshav kabra
 * @since July 8, 2021
 */



/** function get_results
 * @param string, denoting the string which holds one of the answer strings
 * @param unordered_map, map which stores the digits-characters as key-value pairs (dialpad)
 * @pairs string, denoting the string of digits whose text messages we need to generate
 * @pairs vector<string> denoting the array which holds all answer strings
 */ 
void get_results(string sol, unordered_map<char, vector<char>> &mp, string digits, vector<string> &ans)
{
    
    /** Logic :
     * 
     * If the length of string digits is 0, it means we have found one permutation of the string (which is 
     * stored in 'sol'), hence push 'sol' to vector.
     * 
     * Else, iterate on the values (characters) associated which every number in 'digits' (keys) from the 
     * map.
     * Call get_results recursively, by appending one char to 'sol' string and passing substring of 'digits'
     * from 1st character to last character (0-based indexing) [remove first character from string 'digits']
     * 
     */ 
    
    
    // we have found one permutation
    if(digits.length() == 0)
    {
        ans.push_back(sol);
        return;
    }
    
    
    // iterate on every character for a particular digit
    for(char ch : mp[digits[0]])
    {
        
        // recursively calling function, updated 'sol' by appending one char to it
        // and remving first char of string 'digits' (substr)
        get_results(sol+ch, mp, digits.substr(1), ans);
    }
    
}



/** function letterCombinations
 * @param string, denoting the string of digits whose text messages we need to generate
 * @return vector<string>, array which holds all permutations of digits
 */ 
vector<string> letterCombinations(string digits) 
{    
    
    /** Logic :
     * 
     * If the digits string is empty, return empty vector
     * 
     * Else, make an unordered_map which holds all the digits (2-9) as keys as their corresponding characters
     * as values ( for eg, 2 -> {a, b, c} )
     * 
     * Call the recursive backtracting function get_results to get the answer and return the vector.
     * 
     */ 
    
    if(digits == "")
        return {};
        
    vector<string> ans;
    
    unordered_map<char, vector<char>> mp;
    mp['2'] = {'a','b','c'};
    mp['3'] = {'d','e','f'};
    mp['4'] = {'g','h','i'};
    mp['5'] = {'j','k','l'};
    mp['6'] = {'m','n','o'};
    mp['7'] = {'p','q','r','s'};
    mp['8'] = {'t','u','v'};
    mp['9'] = {'w','x','y','z'};
    
    get_results("", mp, digits, ans);
    
    return ans;
}



/** function print_answer
 * @param vector<int>, denoting the array which stores all permutations of string
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
	
	
	// TESTCASE
	ans = letterCombinations("23");
	print_answer(ans);
	
	
	return 0;
}
