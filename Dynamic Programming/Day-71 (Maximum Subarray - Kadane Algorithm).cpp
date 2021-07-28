/**
 * Facebook
 * Given an integer array, return the sum of its contiguous subarray that produces the largest value
 * Note: Your subarray must contain at least one value
 */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


/**
 * @author keshav kabra
 * @since July 28, 2021
 */



/** function maxSubArray
 * @param vector<int>, denoting the given array
 * @return int, sum of array's contiguous subarray that produces the largest value
 */ 
int maxSubArray(vector<int>& nums) 
{
    
    /** Logic :
     * 
     * Kadane’s algorithm
     * 
     * We add the current term of array to variable 'curr_sum' (which holds temporary sum) and make an 'answer'
     * variable with INT_MIN (which stores the final result)
     * 
     * Now, after adding the term, if 'answer' becomes smaller than 'curr_sum', we assign 'answer' to 
     * 'curr_sum'
     * 
     * Also, since we need to find maximum sum, if 'curr_sum' becomes less than 0, we assign it to 0 (we will
     * consider subarray from next term to produce maxim sum)
     * 
     */ 
    
    int sz = nums.size();
    
    int answer = INT_MIN;
    int curr_sum = 0;
    
    for(int i=0;i<sz;i++)
    {
        curr_sum += nums[i];
        if(answer < curr_sum)
            answer = curr_sum;
        if(curr_sum < 0)
            curr_sum = 0;
    }
    return answer;
}



// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASES
	
	v = {-3, 8, -8, 2};
	cout<<maxSubArray(v)<<"\n";
	
	v = {2, 3,-4, 2};
	cout<<maxSubArray(v)<<"\n";
	
	v = {1, 5,-2, -3, 7};
	cout<<maxSubArray(v)<<"\n";
	
	
	return 0;
}
