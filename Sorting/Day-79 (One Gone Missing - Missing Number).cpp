/**
 * Amazon
 * Given an array that contains all distinct values from zero through N except one number, 
 * return the number that is missing from the array.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since August 5, 2021
 */



/** function missingNumber
 * @param vector<int>, array of numbers
 * @return int, number that is missing from the array
 */
int missingNumber(vector<int>& nums) 
{
    
    /** Logic :
     * 
     * We sort the array, if first number is not 0, 0 itself is the missing number, hence return 0
     * 
     * Else, iterate on the array, as we have sorted the array, the previous term added with 1 should give
     * the next term. 
     * If this is not the case, a number is missing there. Hence, we break out of the loop.
     * 
     * Out of loop, we check value of i, if it equal to size of given array, the last element is missing, 
     * hence return last element of array plus 1
     * Else, return the element we had broke from loop added by 1
     * 
     */ 
    
    int N = nums.size();
    if(N == 0)
        return 0;
 
    sort(nums.begin(), nums.end());
    if(nums[0] != 0)
        return 0;
    
    int i;
    for(i=1; i<N; i++)
    {
        if(nums[i-1]+1 != nums[i])
            break;
    }
    
    if(i == N)
        return nums[N-1]+1;
        
    return nums[i-1]+1;
    
}


// main function - driver code
int main()
{
	
	vector<int> v;
	
	
	// TESTCASES
	
	v = {1, 4, 2, 0};
	cout<<missingNumber(v)<<"\n";
	
	v = {6, 3, 1, 2, 0, 5};
	cout<<missingNumber(v)<<"\n";
	
	
	return 0;
}
