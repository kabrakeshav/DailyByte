/**
 * Google
 * Given a positive integer N, return the number of prime numbers less than N.
 */

#include<iostream>
#include<cstring>
using namespace std;


/**
 * @author keshav kabra
 * @since August 16, 2021
 */



/** function countPrimes
 * @param int, number N
 * @return int, number of prime numbers less than N
 */ 
int countPrimes(int n) 
{
    
    /** Logic :
     * 
     * We make an array of boolean type of size N+1 and set all values to true - initially we assume that
     * all numbers are prime
     * 
     * Now, we iterate from 2 to square_root(N) and set all divisible numbers to false
     * 
     * At the end, count the places where value is still true - they are prime numbers and return the
     * count
     * 
     */ 
    
    bool v[n+1]; 
    memset(v, true, sizeof(v)); 
    
    for(int p=2; p*p<=n; p++)
    {
        if(v[p] == true)
        {
            for(int i=p*p; i<=n; i+=p)
                v[i] = false;
        }
    }
    
    int cnt = 0;
    
    for(int p=2; p<n; p++)
        if(v[p] == true)
            cnt++;
    
    return cnt;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<countPrimes(3)<<"\n";
	cout<<countPrimes(7)<<"\n";
	cout<<countPrimes(10008)<<"\n";
	
	
	return 0;
}
