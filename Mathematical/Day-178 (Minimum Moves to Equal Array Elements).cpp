/**
 * Given a non-empty integer array, nums, return the minimum number of moves to make all values in nums 
 * equal. A move consists of incrementing all but one element in the array by one.
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;


/**
 * @author keshav kabra
 * @since December 2, 2021
 */



/** function minMoves
 * @param vector<int>, given array
 * @return int, minimum number of moves to make all values in array equal
 */ 
int minMoves(vector<int>& nums) 
{
    
    /** Logic :
     * 
     * Iteratively decrementing the max item in the list until all items have the same value (which will be guaranteed to 
     * be the original list's minimum value).
         
     * APPROACH  - DECREMENTING:
        
        # sum(nums) - n * 1 = t * len(nums)
        # Explanation: the sum of the original list minus all the decrements (count) required to make all values the same is 
          equal to the sum of the finished list.
        
        -> Upon further inspection, we already know t; t is equal to the current minimum element, t = min(nums), so replacing 
           that, we get:
        
        # sum(nums) - n = min(nums) * len(nums)
      
         
     * Solving for n, we get:
        
        # n = sum(nums) - min(nums) * len(nums)
        
     * 
     */ 
    
	int sum = accumulate(nums.begin(), nums.end(), 0);
    int mini = *min_element(nums.begin(), nums.end());
    
    return sum - (mini * nums.size());
}



// main function - driver code
int main()
{
	vector<int> nums;
	
	
	// TESTCASES
	
	nums = {1, 2, 3};
	cout<<minMoves(nums)<<"\n";
	
	nums = {1, 1, 1};
	cout<<minMoves(nums)<<"\n";
	
	return 0;
}
