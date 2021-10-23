/**
 * Given two strings s and t, return the index of the first occurrence of t within s if it exists; 
 * otherwise, return -1.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


/**
 * @author keshav kabra
 * @since October 23, 2021
 */



/** function get_answer
 * @param string, first string
 * @param string, second string
 * @return int, index where second string occurs in first string for the first time
 */ 
int get_answer(string s, string t)
{
	int N = s.length();
	int M = t.length();
	
	for(int i=0;i<N-M;i++)
	{
		int j;
		for(j=0;j<M;j++)
		{
			if(s[i+j] != t[j])
				break;
		}
		
		if(j == M)
			return i;
	}
	
	return -1;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<get_answer("abc", "a")<<"\n";
	cout<<get_answer("abc", "abcd")<<"\n";
	
	
	return 0;
}
