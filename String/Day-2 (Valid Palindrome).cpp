/**
 * Facebook
 * Given a string, return whether or not it forms a palindrome ignoring case and non-alphabetical characters.
 */


#include<iostream>
#include<algorithm>
using namespace std;

/**
 * @author keshav kabra
 * @since May 18, 2021
 */

/**
	 * @param string str
	 * @return boolean, true if it is valid palindrome
	 * function to return if string is palindrom or not
	 * ignoring all non-alphabetic characters
*/
bool isPalindrome(string str)
{
	if(str.length() <= 1)
		return true;
	
	int left = 0;
	int right = str.length()-1;
	
	while(left < right)
	{
		// both are non-alphabetic
		if((str[left]<'a' || str[left]>'z') && (str[right]<'a' || str[right]>'z')) {
			left++;
			right--;
		}
		
		// left char is non-alphabetic
		else if(str[left]<'a' || str[left]>'z')
			left++;
			
		// right char is non-alphabetic
		else if(str[right]<'a' || str[right]>'z')
			right--;
			
		// both are alphabetic and non-equal
		else if(str[left] != str[right])
			return false;
		
		// both are alphabetic and equal
		else if(str[left] == str[right]) {
			left++;
			right--;
		}
		
	}
	return true;
}



// main function - driver code
int main()
{
	// TESTCASES
	
	string str = "level";
	// converting to lower-case letter string
	// we need to ignore the cases while cheking
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	// calling function to check for palindrome
	cout<<isPalindrome(str)<<"\n";
	
	str = "algorithm";
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	cout<<isPalindrome(str)<<"\n";
	
	str = "A man, a plan, a canal: Panama.";
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	cout<<isPalindrome(str)<<"\n";
	
	return 0;
}
