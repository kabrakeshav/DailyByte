/**
 * Google
 * Given a string, reverse all of its characters and return the resulting string.
 */



#include<iostream>
using namespace std;

/**
 * @author keshav kabra
 * @since May 18, 2021
 */
 
 
/**
  * @param string str to be reversed
  * @return reversed string object using loop
*/
string reverse(string str)
{
	string ans = "";
	
	// logic to reverse string
	for(int i=str.length()-1;i>=0;i--)
	{
		ans = ans + str[i];
	}
	return ans;
}


// driver - main function
int main()
{
	// TESTCASES
	cout<<reverse("Cat")<<"\n";
	cout<<reverse("The Daily Byte")<<"\n";
	cout<<reverse("civic")<<"\n";
	
	return 0;
}
