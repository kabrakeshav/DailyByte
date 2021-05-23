/* *** *** ***

This question is asked by Google. Given a string, reverse all of its 
characters and return the resulting string.

Ex: Given the following strings ...

	“Cat”, return “taC”
	“The Daily Byte”, return "etyB yliaD ehT”
	“civic”, return “civic”

*** *** *** */



#include<iostream>
using namespace std;


int main()
{
	// getting string from user
	string str;
	cout<<"Enter a string : ";
	getline(cin, str);
	
	// to store reversed string
	string ans = "";
	
	// logic to reverse string
	for(int i=str.length()-1;i>=0;i--)
	{
		ans = ans + str[i];
	}
	
	// displaying reverse string
	cout<<"\nReversed string : "<<ans;
	
	return 0;
}
