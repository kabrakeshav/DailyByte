/**
 * Given two non-negative numbers, num1 and num2 represented as strings, sum the integers together 
 * and return the result as a string.
 */

#include<iostream>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since November 15, 2021
 */



/** function addStrings
 * @param string, first number in form of string
 * @param string, second number in form of string
 * @return string, denoting sum of given strings
 */ 
string addStrings(string num1, string num2)
{
    string ans = "";
    
    int l1 = num1.length()-1, l2 = num2.length()-1;
    
    int carry = 0;
    while(l1>=0 && l2>=0)
    {
        int x = num1[l1]-'0';
        int y = num2[l2]-'0';
        
        int z = carry+x+y;
        carry = z/10;
        z = z%10;
        
        ans += to_string(z);
        l1--;l2--;
    }
    
    
    while(l1>=0)
    {
        int x = num1[l1]-'0';
        int z = carry+x;
        carry = z/10;
        z = z%10;
        
        ans += to_string(z);
        l1--;
    }
    
    while(l2>=0)
    {
        int x = num2[l2]-'0';
        int z = carry+x;
        carry = z/10;
        z = z%10;
        
        ans += to_string(z);
        l2--;
    }
    
    if(carry != 0)
        ans += to_string(carry);
    
    reverse(ans.begin(), ans.end());
    return ans;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<addStrings("2", "5")<<"\n";
	cout<<addStrings("7", "95")<<"\n";
	cout<<addStrings("3876620623801494171", "6529364523802684779")<<"\n";
	cout<<addStrings("456", "77")<<"\n";
	
	return 0;
}
