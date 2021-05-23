/* *** *** ***

This question is asked by Google. Given a string, return 
whether or not it uses capitalization correctly. A string 
correctly uses capitalization if all letters are capitalized, 
no letters are capitalized, or only the first letter is capitalized.

Ex: Given the following strings...
	"USA", return true
	"Calvin", return true
	"compUter", return false
	"coding", return true 

*** *** *** */




#include<iostream>
using namespace std;



// function is_correct
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




// main function
int main()
{
	
	// getting string from user
	string str;
	cout<<"Enter a string : ";
	cin>>str;
	
	
	// calling the function to check for correctness
	bool x = is_correct(str);
	
	
	// displaying result
	x==true ? cout<<"True" : cout<<"False";
	
	
	return 0;
}
