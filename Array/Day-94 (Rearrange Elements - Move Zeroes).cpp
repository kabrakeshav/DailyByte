/**
 * Apple
 * Given an array of numbers, move all zeroes in the array to the end while maintaining the relative 
 * order of the other numbers.
 * Note: You must modify the array you’re given (i.e. you cannot create a new array)
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since August 25, 2021
 */



/** function moveZeroes
 * @param vector<int>, denoting the array
 * Moves all zeores to the end of the given array (in-place)
 */ 
void moveZeroes(vector<int>& nums) 
{
    
    /** Logic :
     * 
     * Idea is to move all the non-zero elements of the array to starting and then fill the rest of the 
     * positions with 0
     * 
     * Hence, we iterate on the array and put all non-zero elements at the front, by ignoring all zero
     * values and after the loop ends, we fill the rest of the array with 0s
     * 
     * 
     * Time complexity  : O(N) -- Entire array is traversed
     * Space complexity : O(1)
     * 
     */ 
    
    if(nums.size() == 0)
        return;
    
    int ind = 0;
    
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] != 0)
            nums[ind++] = nums[i];
    }
    
    for(; ind<nums.size(); ind++)
        nums[ind] = 0;
}



/**  function print_array
 * @param vector, denoting the array to be displayed
 * Displays the array on the console
 */ 
void print_array(vector<int> v)
{
	for(int i : v)
		cout<<i<<" ";
	cout<<"\n";
}



// main function - driver code
int main()
{
	vector<int> nums;
	
	// TESTCASES
	
	nums = {3, 7, 0, 5, 0, 2};
	moveZeroes(nums);
	print_array(nums);
	
	nums = {0, 0, 1};
	moveZeroes(nums);
	print_array(nums);
	
	
	return 0;
}
