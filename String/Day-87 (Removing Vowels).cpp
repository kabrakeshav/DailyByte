/**
 * Amazon
 * Given a string s remove all the vowels it contains and return the resulting string
 * Note: In this problem y is not considered a vowel
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since August 20, 2021
 */



/** function isVowel
 * @param char, character 
 * @return bool, whether character is vowel (true) or not (false)
 */ 
bool isVowel(char ch)
{
	return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E'
		|| ch=='I' || ch=='O' || ch=='U';
}



/** function remVowel
 * @param string, string from which vowels need to be removed
 * @return string, removed vowels string
 */ 
string remVowel(string str)
{	
	for(int i=0;i<str.length();i++)
	{
	    
		if(isVowel(str[i])) 
		{
		    // replace substring from index 'i' of length 1 by string - ""
			str.replace(i, 1, "");
			i -= 1;
		}
		
	}
	
	return str;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<remVowel("aeiou")<<"\n";
	cout<<remVowel("byte")<<"\n";
	cout<<remVowel("xyz")<<"\n";
	
	return 0;
}
