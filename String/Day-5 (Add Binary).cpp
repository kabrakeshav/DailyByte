/**
 * Apple
 * Given two binary strings (strings containing only 1s and 0s) return their sum (also as a binary string).
 * Note: neither binary string will contain leading 0s unless the string itself is 0
 */


#include<iostream>
using namespace std;


/**
 * @author gaurav kabra
 * @since May 20, 2021
 */


/**
	 * Adds two binary strings to another binary string.
	 * @param first binary string, a
	 * @param second binary string, b
	 * @return sum of the two binary strings as binary string
	 * lOGIC :
	 	0 + 0 = 0 ( carry is 0 )
	 	1 + 0 = 1 ( carry is 0 )
	 	0 + 1 = 1 ( carry is 0 )
	 	1 + 1 = 0 ( carry is 1 )
*/
string addBinary(string a, string b)
{
    
    // getting string lengths
    int i = a.length()-1, j = b.length()-1;
    
    // to store carry (if any)
    int carry = 0;
    
    // result
    string ans = "";
    
    // loop if - any chars in any of string left
    // or carry is not zero
    while (i >= 0 || j >= 0 || carry!=0) 
    {
        if (i >= 0) 
        {
            carry += a[i]=='0' ? 0 : 1;
            i--;
        }
        if (j >= 0) 
        {
            carry += b[j]=='0' ? 0 : 1;
            j--;
        }
        
        ans = ( (carry%2)==0 ? "0" : "1" ) + ans;
        carry /= 2;
    }
    
    return ans;
}


// main function - driver code
int main()
{
	
	// TESTCASES
	cout<<addBinary("100", "1")<<"\n";
	cout<<addBinary("11", "1")<<"\n";
	cout<<addBinary("1", "0")<<"\n";
	
	return 0;
}
