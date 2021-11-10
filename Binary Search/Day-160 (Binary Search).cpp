/**
 * Given a sorted integer array nums and a target, search for the target with in the array. If the 
 * targets exists within the array, return its index. 
 * If it does not exist within the array, return -1.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since November 10, 2021
 */



/** function search
 * @param vector<int>, denoting array of numbers
 * @param int, number to find in array
 * @return int, index where 'target' was found in given array (else -1)
 */ 
int search(vector<int>& nums, int target) 
{
    int low = 0;
    int high = nums.size()-1;
    
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        
        if(nums[mid] == target)
            return mid;
        
        if(nums[mid] > target)
            high = mid-1;
        else if(nums[mid] < target)
            low = mid+1;
    }
    
    return -1;
}



// main function - driver code
int main()
{
	vector<int> nums;
	
	
	// TESTCASES
	
	nums = {-5, -3, 0, 3, 8, 12, 40};
	cout<<search(nums, 8)<<"\n";
	
	nums = {1, 2, 3, 6, 8};
	cout<<search(nums, 10)<<"\n";
	
	
	return 0;
}
