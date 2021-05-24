/**
 * Google
 * Given a string, return whether or not it uses capitalization correctly. 
 * A string correctly uses capitalization if all letters are capitalized, 
 * no letters are capitalized, or only the first letter is capitalized.
 */


#include<iostream>
using namespace std;

/**
 * @author keshav kabra
 * @since May 19, 2021
 */



/**
	 * @param string s
	 * @return boolean, if correctly capitalized
*/
/* returns true if for passed string :
	>> no letter is capital
	>> first letter is capital
	>> All letters are capital
*/
bool is_correct(string str)
{
	
	// string length less than 2 -> true
	if(str.length() < 2)
		return true;
	
	
	// first letter is capital or not
	bool first_cap = false;
	if(str[0]>=65 && str[0]<=90)
		first_cap = true;
	
	
	// second letter is capital or not
	bool second_cap = false;
	if(str[1]>=65 && str[1]<=90)
		second_cap = true;
	
	
	// if first-letter is small and second-letter is capital
	// return false
	if(first_cap==false && second_cap==true)
		return false;
	
	// loop
	for(int i=2;i<str.length();i++)
	{
		
		// second-letter was capital & we've encountered a small-case letter
		// return false
		if(second_cap && (str[i]>=97 && str[i]<=122))
			return false;
		
		// second-letter was small & we've encountered a capital-case letter
		// return false
		else if(!second_cap && (str[i]>=65 && str[i]<=90))
			return false;
	}
	
	
	return true;
}




// main function - driver code
int main()
{

	// TESTCASES
	cout<<is_correct("USA")<<"\n";
	cout<<is_correct("Calvin")<<"\n";
	cout<<is_correct("compUter")<<"\n";
	cout<<is_correct("coding")<<"\n";
	
	return 0;
}
