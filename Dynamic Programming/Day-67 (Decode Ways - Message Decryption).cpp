/**
 * Microsoft
 * Given a message that is encoded using the following encryption method…
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * Return the total number of ways it can be decoded.
 * ‘0’ has no mapping and a character following a ‘0’ also has no mapping (i.e. “03” has no mapping).
 */

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;


/**
 * @author keshav kabra
 * @since July 24, 2021
 */


int get_answer(string str, int start, vector<int> &mem)
{
    if(start == str.size())
        return 1;
    
    if(str[start] == '0')
        return 0;
    
    if(start == str.size()-1)
        return 1;
    
    if(mem[start] > 0)
        return mem[start];
    
    int first = get_answer(str, start+1, mem);
    int second = 0;
    
    string two = str.substr(start, 2);
    if(stoi(two)<=26 && stoi(two)>0)
        second = get_answer(str, start+2, mem);
    
    return mem[start] = first+second;
    
}
 
int numDecodings(string s) 
{
    vector<int> v(s.size()+1, 0);
    
    return get_answer(s, 0, v);
}
 
 
// main function - driver code
int main()/**
 * Microsoft
 * Given a message that is encoded using the following encryption method…
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * Return the total number of ways it can be decoded.
 * ‘0’ has no mapping and a character following a ‘0’ also has no mapping (i.e. “03” has no mapping).
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since July 24, 2021
 */



/** function get_answer
 * @param string, denoting the string of numbers
 * @param int, denoting the starting index for current recursive call
 * @param vector<int>, vector for memoization
 * @return int, denoting the number of ways string can be decoded
 */
int get_answer(string str, int start, vector<int> &mem)
{
    
    // if string is ended - return 1 (we have found one way to decode)
    if(start == str.size())
        return 1;
    
    
    // if current character is 0, return 0 (invalid character)
    if(str[start] == '0')
        return 0;
    
    
    // if it is last character of string is ended - return 1 (we have found one way to decode)
    if(start == str.size()-1)
        return 1;
    
    
    // if this sub-problem was already solved (memoization)
    if(mem[start] > 0)
        return mem[start];
    
    
    // first to store 1-digit number answers
    int first = get_answer(str, start+1, mem);
    
    // first to store 2-digit number answers
    int second = 0;
    
    
    // getting substring of length 2 from 'start' index
    string two = str.substr(start, 2);
    
    // if the substring is [1, 26]
    if(stoi(two)<=26 && stoi(two)>0)
        second = get_answer(str, start+2, mem);
    
    
    // return while memoization
    return mem[start] = first+second;
    
}



/** function numDecodings
 * @param string, denoting the string of numbers
 * @return int, denoting the number of ways string can be decoded
 */ 
int numDecodings(string s) 
{
    
    /** Logic :
     * 
     * We use the vector 'v' as cache for memoization and call the recursive function 'get_answer' to
     * return the required answer
     * 
     */ 
    
    vector<int> v(s.size()+1, 0);
    return get_answer(s, 0, v);
    
}
 
 
 
// main function - driver code
int main()
{
	cout<<numDecodings("23")<<"\n";
	cout<<numDecodings("1234")<<"\n";
	cout<<numDecodings("111111111111111111111111111111111111111111111")<<"\n";
	
	return 0;
}
{
	cout<<numDecodings("23")<<"\n";
	cout<<numDecodings("1234")<<"\n";
	cout<<numDecodings("111111111111111111111111111111111111111111111")<<"\n";
	
	return 0;
}
