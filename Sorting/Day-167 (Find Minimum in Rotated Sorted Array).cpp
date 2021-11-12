/**
 * Given an sorted integer array, nums, that has been rotated at an unknown index, return the minimum value.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since November 12, 2021
 */



/** function findMin
 * @param vector<int>, array of numbers
 * @return int, minimum value in the array
 */ 
int findMin(vector<int>& nums) 
{
    if(nums.size() == 0)
        return -1;
    
    sort(nums.begin(), nums.end());
    
    return nums[0];
}



// main function - driver code
int main()
{
	vector<int> nums;
	
	
	// TESTCASE
	
	nums = {7, 9, 10, 2, 4, 6};
	cout<<findMin(nums)<<"\n";
	
	return 0;
} 
