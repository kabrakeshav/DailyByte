/**
 * Google
 * Given a staircase with N steps and the ability to climb either one 
 * or two steps at a time, return the total number of ways to arrive at the 
 * top of the staircase.
 */

#include<iostream>
using namespace std;


/**
 * @author keshav kabra
 * @since August 2, 2021
 */



/** function climbStairs
 * @param int, number of steps in staircase
 * @return int, total number of ways to arrive at the top of the staircase with either one or two steps at a time
 */
int climbStairs(int n) 
{
    
    /** Logic :
     * 
     * We will make a DP table of size N which denotes the number of distinct ways to reach that particular
     * step
     * The first step can only be climbed in 1 way and second step in 2 ways (two jumps of 1 steps or 
     * 1 jump of 2 steps)
     * 
     * The next number of steps is simply the sum of previous two answers. Return the last value of DP table
     * 
     * 
     * Time complexity  : O(N)
     * Space complexity : O(N)
     * 
     */ 
    
    if(n == 1)
        return 1;
    
    int v[n];
    v[0] = 1;
    v[1] = 2;
    
    for(int i=2;i<n;i++)
    {
        v[i] = v[i-1]+v[i-2];
    }
    
    return v[n-1];
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<climbStairs(2)<<"\n";
	cout<<climbStairs(3)<<"\n";
	cout<<climbStairs(45)<<"\n";
	
	return 0;
}
