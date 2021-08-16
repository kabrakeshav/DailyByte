/**
 * Facebook
 * Given a string, reverse the vowels of it.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since August 16, 2021
 */



/** function is_vowel
 * @param char, character to be determined as vowel or consonant
 * @return boolean, is character a vowel
 */ 
bool is_vowel(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
           ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
        return true;
        
    return false;
}



/** function reverseVowels
 * @param string, string to be reversed by vowels
 * @return string, string whose vowels are reversed
 */ 
string reverseVowels(string s) 
{
    
    /** Logic :
     * 
     * We store all vowels of the string into an array and reverse that array - hence that vowels are now
     * reversed
     * 
     * Now, we iterate on the string and if current character of string is vowel, we replace it with the 
     * current element in the vowel-array
     * 
     */
    
    vector<char> v;
    
    for(char ch : s)
        if(is_vowel(ch))
            v.push_back(ch);
    
    if(v.size() <= 1)
        return s;
    
    reverse(v.begin(), v.end());
    
    int k = 0;
    for(int i=0;i<s.length();i++)
    {
        if(is_vowel(s[i]))
            s[i] = v[k++];
    }
    
    return s;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<reverseVowels("computer")<<"\n";
	cout<<reverseVowels("The Daily Byte")<<"\n";
	
	
	return 0;
}
