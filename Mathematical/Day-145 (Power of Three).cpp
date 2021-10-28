/**
 * Given an integer n, return whether or not it is a power of three.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since October 28, 2021
 */



/** function isPowerOfThree
 * @param int, denoting the number
 * @return bool, whether or not number is a power of three
 */ 
bool isPowerOfThree(int n) 
{    
    if(n == 1)
        return true;
    
    long long i = 3;
    while(i <= n)
    {
        if(i == n)
            return true;
        i *= 3;
    }
    
    return false;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<isPowerOfThree(9)<<"\n";
	cout<<isPowerOfThree(50)<<"\n";
	cout<<isPowerOfThree(1162261468)<<"\n";
	
	return 0;
}
