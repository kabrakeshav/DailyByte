/* *** *** ***
This question is asked by Apple. Given two binary strings 
(strings containing only 1s and 0s) return their sum 
(also as a binary string).
Note: neither binary string will contain leading 0s 
unless the string itself is 0

Ex: Given the following binary strings...

"100" + "1", return "101"
"11" + "1", return "100"
"1" + "0", return  "1"


*** *** *** */


#include<iostream>
using namespace std;



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

int main()
{
	cout<<addBinary("100", "1")<<"\n";
	cout<<addBinary("11", "1")<<"\n";
	cout<<addBinary("1", "0")<<"\n";
	
	return 0;
}
