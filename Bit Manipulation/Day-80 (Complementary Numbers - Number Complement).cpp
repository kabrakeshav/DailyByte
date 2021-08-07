/**
 * Given a positive number, return its complementary number.
 * Note: The complement of a number is the number that results from flipping every bit in the 
 * original number. (i.e. zero bits become one bits and one bits become zero bits).
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since August 7, 2021
 */



/** function findComplement
 * @param int, number whose complement is to be calculated
 * @return int, the complemented number
 */
int findComplement(int num) 
{
	
	/** Logic :
	 *  
	 * We basically check every bit of number by XOR'ing it with appropriate power of 2 
	 * which leads to its invertion.
	 * 
     * For example:
     *    Entered: 4=>100;
     *    100 ^ 001 = 101;
     *    101 ^ 010 = 111;
     *    111 ^ 100 = 011;
     *    Out :     011 => 3;
     * 
     * 
     * Why 'long i' in loop instead of 'int i' :
     * 
     * In for loop, first i get updated then it performs comparison.
     * suppose num=2^31 -1 ( maximum limit of int)
     * when i=2^30, the loop runs again.
     * During updation, i becomes 2^31 (Overflow).
     * This give error. Hence, instead of int we chose long.
     *
	 */ 
	
    for(long i=1;i<=num;i*=2)
        num ^= i;
    
    return num;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	cout<<findComplement(27)<<"\n";
	
	return 0;
}
