/**
 * Given a sorted integer array, nums, remove duplicates from the array in-place such that each element 
 * only appears once. Once you’ve removed all the duplicates, return the length of the new array.
 * Note: The values you leave beyond the new length of the array does not matter.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since December 7, 2021
 */



/** function removeDuplicates
 * @param vector<int>, given array
 * @return int, length of array after removing all duplicates
 */ 
int removeDuplicates(vector<int>& nums) 
{
    nums.erase(unique(nums.begin() ,nums.end()),nums.end()); 
    return nums.size() ;
}
    
    
    
// main function - driver code
int main()
{
	vector<int> nums;
	
	
	// TESTCASES
	
	nums = {1, 2, 2, 4, 4, 6, 8, 8};
	cout<<removeDuplicates(nums)<<"\n";
	
	nums = {1, 2, 3, 3};
	cout<<removeDuplicates(nums)<<"\n";
	
	return 0;
}
