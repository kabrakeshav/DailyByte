/** Given an integer N, return the total number self divisible numbers that are strictly less than N 
 * (starting from one).
 * Note: A self divisible number if a number that is divisible by all of its digits.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since September 14, 2021
 */



/** function selfDividingNumbers
 * @param int, denoting the integer
 * @return int, count of self divisible numbers
 */ 
int selfDividingNumbers(int lim) 
{
    vector<int> res;
    
    for (int i=1, n=0; i<=lim; i++) 
    {
        for (n=i; n>0; n/=10)
        {
            
            // if n is not zero or it is not self divisible number, break from loop
            // we will not add this number
            if (n%10==0 || i%(n%10)!=0) 
                break;
        }
        
        if (n == 0) 
            res.push_back(i);
    }
    
    
    // return the vector to get list of all self divisible numbers
    return res.size();
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<selfDividingNumbers(17)<<"\n";
	cout<<selfDividingNumbers(85)<<"\n";
	cout<<selfDividingNumbers(22)<<"\n";
	
	return 0;
}

