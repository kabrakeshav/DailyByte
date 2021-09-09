/** Facebook
 * Given an array nums, return whether or not its values are monotonically increasing or 
 * monotonically decreasing.
 * Note: An array is monotonically increasing if for all values i <= j, nums[i] <= nums[j]. 
 * Similarly an array is monotonically decreasing if for all values i <= j, nums[i] >= nums[j].
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since September 9, 2021
 */



/** function isMonotonic
 * @param vector<int>, denoting the array of integers
 * @return bool, whether the array is monotonically increasing or decreasing
 */ 
bool isMonotonic(vector<int>& A) 
{
    
    /** Logic :
     * 
     * The array is monotonically increasing or decreasing if it is sorted either in increasing or decreasing
     * order, hence we use STL function to check the same
     *
     */
    
    if(is_sorted(A.begin(), A.end()) || is_sorted(A.rbegin(), A.rend()))
        return true;
    return false;
}



// main function - driver code
int main()
{
	vector<int> v;
	
	// TESTCASES
	
	v = {1, 2, 3, 4, 4, 5};
	cout<<isMonotonic(v)<<"\n";
	
	v = {7, 6, 3};
	cout<<isMonotonic(v)<<"\n";
	
	v = {8, 4, 6};
	cout<<isMonotonic(v)<<"\n";
	
	return 0;
}

