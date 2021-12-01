/**
 * Given a sorted array of integers, nums, and a target, return the index of the target within nums. 
 * If it does not exist, return the index of where target should be inserted.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since December 1, 2021
 */



/** function searchInsert
 * @param vector<int>, given array
 * @param int, target number : to search or inserted
 * @return int, index where 'target' is either found or can be inserted in sorted array 'nums'
 */ 
int searchInsert(vector<int>& nums, int target) 
{
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] >= target)
            return i;
    }
    
    return nums.size();
}
    
    

// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASES
	
	v = {1, 5, 8, 12};
	cout<<searchInsert(v, 12)<<"\n";
	
	v = {3, 4, 7, 12, 29};
	cout<<searchInsert(v, 5)<<"\n";
	
	return 0;
}
