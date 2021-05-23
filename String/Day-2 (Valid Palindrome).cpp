/* *** *** ***

This question is asked by Facebook. Given a string, return whether 
or not it forms a palindrome ignoring case and non-alphabetical characters.
Note: a palindrome is a sequence of characters that reads the 
same forwards and backwards.

Ex: Given the following strings...

"level", return true
"algorithm", return false
"A man, a plan, a canal: Panama.", return true

*** *** *** */


#include<iostream>
#include<algorithm>
using namespace std;


// function to return if string is palindrom or not
// ignoring all non-alphabetic characters
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
	
	// getting string from user
	string str;
	cout<<"Enter a string : ";
	getline(cin, str);
	
	// converting to lower-case letter string
	// we need to ignore the cases while cheking
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	
	// calling function to check for palindrome
	bool x = isPalindrome(str);
	
	// displaying output
	x==true ? cout<<"True" : cout<<"False";
	
	return 0;
	
	
}
