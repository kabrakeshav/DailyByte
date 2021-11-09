/**
 * Given a positive integer n, return its corresponding column title in an excel spreadsheet.
 */

#include<iostream>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since November 9, 2021
 */



/** function convertToTitle
 * @param int, denoting the given integer
 * @return string, denoting the spreadsheet column name
 */ 
string convertToTitle(int n) 
{
    string ans = "";
    
    if(n <= 26) 
    {
        ans += 64+n;
        return ans;
    }
    
    while(n != 0)
    {
        int temp = n%26;
        
        if(temp == 0)
        {
            ans += "Z";
            n = n/26-1;
        }
        else 
        {
            ans += 64+temp;
            n /= 26;
        }
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<convertToTitle(1)<<"\n";
	cout<<convertToTitle(14)<<"\n";
	cout<<convertToTitle(26)<<"\n";
	cout<<convertToTitle(28)<<"\n";
	cout<<convertToTitle(2147483647)<<"\n";
	
	return 0;
}
