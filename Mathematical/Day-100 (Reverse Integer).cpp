/** Apple 
 * Given a 32 bit signed integer, reverse it and return the result.
 * Note: You may assume that the reversed integer will always fit within the bounds of the 
 * integer data type.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since September 9, 2021
 */



/** function reverse
 * @param int, denoting the number
 * @param int, reversed number
 */ 
int reverse(int x) 
{
    long r = 0;
    while (x) 
    {
        r = r*10 + x%10;
        x /= 10;
    }
    
    // if it fits in bounds of integer return the number, else return 0
    if(int(r) == r)
        return r;
    return 0;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<reverse(550)<<"\n";
	cout<<reverse(-37)<<"\n";
	cout<<reverse(123)<<"\n";
	
	return 0;
}
