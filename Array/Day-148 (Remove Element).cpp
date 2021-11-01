/**
 * Given an integer array nums and a value, val, remove all instances of val in-place and return the 
 * length of the new array.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since November 1, 2021
 */
 


/** function removeElement
 * @param vector<int>, array of numbers
 * @param int, value to be deleted
 * @return int, size of array after removal
 */ 
int removeElement(vector<int>& nums, int val) 
{
    if(nums.size() == 0)
        return 0;
    
    nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
    return nums.size();
} 
 
 
 
// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASES
	
	v = {1, 2, 3};
	cout<<removeElement(v, 2)<<"\n";
	
	return 0;
}

