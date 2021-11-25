/**
 * Given a non-negative integer, num, repeatedly add all its digits until it has a single digit 
 * remaining and return it.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since November 25, 2021
 */



/** function addDigits
 * @param int, given number
 * @return int, single digit number obtained by repeatedly adding digits of given number
 */ 
int addDigits(int num) 
{
    if(num < 10)
        return num;
    
    int s = 0;
    while(num >= 10)
    {
        s = 0;
        int t = num;
        while(t)
        {
            s += (t%10);
            t /= 10;
        }
        num = s;
    }
    
    return num;
}
    
    
    
// main function - driver code
int main()
{
	
	// TESTCASES
	cout<<addDigits(38)<<"\n";
	cout<<addDigits(123)<<"\n";
	cout<<addDigits(0)<<"\n";
	cout<<addDigits(8353)<<"\n";
	
	return 0;
}
