/**
 * Amazon. 
 * Given a valid IP address, defang it.
 * Note: To defang an IP address, replace every ”.”, with ”[.]”.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since August 18, 2021
 */



/** function defangIPaddr
 * @param string, the IP address 
 * @return string, defanged IP address
 */ 
string defangIPaddr(string address) 
{
    string ans = "";
    
    for(char ch : address)
    {
        if(ch == '.')
            ans += "[.]";
        else
            ans += ch;
    }
    
    return ans;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<defangIPaddr("127.0.0.1")<<"\n";
	cout<<defangIPaddr("255.100.50.0")<<"\n";
	
	return 0;
}
