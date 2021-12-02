/**
 * Given an integer, num, return its base seven representation as a string.
 */

#include<iostream>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since December 2, 2021
 */



/** function convertToBase7
 * @param int, given integer
 * @return string, base-7 string representation of given integer
 */ 
string convertToBase7(int num) 
{
    if(num > -7 && num < 7)
        return to_string(num);
    
    string neg = num<0 ? "-" : "";
    num = abs(num);
    
    string result = "";
    while(num > 0)
    {
        int rem = num%7;
        num /= 7;
        result += to_string(rem);
    }
    
    reverse(result.begin(), result.end());
    return neg+result;
}
    
    
    
// main function - driver code
int main()
{
	cout<<convertToBase7(42)<<"\n";
	cout<<convertToBase7(100)<<"\n";
	cout<<convertToBase7(-7)<<"\n";
	
    return 0;
}
