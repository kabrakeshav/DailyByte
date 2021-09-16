/** 
 * Given an array of integers, nums, and a value k, return the kth largest element.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since September 16, 2021
 */



/** function findKthLargest
 * @param vector<int>, denoting the array
 * @param int, value of k
 * @return int, kth largest element of the array
 */ 
int findKthLargest(vector<int>& nums, int k) 
{
    if(nums.size() == 0)
        return -1;
        
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k-1];
}



// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASES
	
	v = {1, 2, 3};
	cout<<findKthLargest(v, 1)<<"\n";
	
	v = {9, 2, 1, 7, 3, 2};
	cout<<findKthLargest(v, 5)<<"\n";
	
	v = {3, 2, 3, 1, 2, 4, 5, 5, 6};
	cout<<findKthLargest(v, 4)<<"\n";
	
	
	return 0;
}
