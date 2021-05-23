/* *** *** ***

This question is asked by Amazon. Given a string representing 
the sequence of moves a robot vacuum makes, return whether 
or not it will return to its original position. The string will 
only contain L, R, U, and D characters, representing left, right, 
up, and down respectively.

Ex: Given the following strings...
	"LR", return true
	"URURD", return false
	"RUULLDRD", return true 
	
*** *** *** */


#include<iostream>
using namespace std;


// function to return whether vacuum cleaner get back
// to its starting postition.
// It will return if number of L equals to number of R and
// number of U equals to number of D.
bool return_to_original_position(string str)
{
	int lr=0, ud=0;
	
	for(int i=0;i<str.length();i++)
	{
		if(str[i] == 'L')
			lr++;
		else if(str[i] == 'R')
			lr--;
		else if(str[i] == 'U')
			ud++;
		else if(str[i] == 'D')
			ud--;
	}
	
	return (lr==0 && ud==0);
}



// main function - driver code
int main()
{
	
	// getting string from user
	string str;
	cout<<"Enter the string : ";
	cin>>str;
	
	// calling function
	bool x = return_to_original_position(str);
	
	// displaying result
	x==true ? cout<<"True" : cout<<"False";
	
	return 0;
}
