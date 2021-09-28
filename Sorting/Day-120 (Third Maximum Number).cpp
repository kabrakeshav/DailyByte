/**
 * Given an array nums, return the third largest (distinct) value.
 * Note: If the third largest number does not exist, return the largest value.
 */

#include<iostream>
#include<vector>
#include<set>
using namespace std;


/**
 * @author keshav kabra
 * @since September 28, 2021
 */
 
 

/** function thirdMax
 * @param vector<int>, denoting the array
 * @return int, 3rd max element of array (else max of array)
 */ 
int thirdMax(vector<int>& nums) 
{
    set<int, greater<int>> st(nums.begin(), nums.end());
    
    if(st.size() < 3)
        return *st.begin();
    
    return *next(st.begin(), 2);
} 
 
 
 
// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASES
	
	v = {1, 4, 2, 3, 5};
	cout<<thirdMax(v)<<"\n";
	
	v = {2, 3, 3, 5};
	cout<<thirdMax(v)<<"\n";
	
	v = {9, 5};
	cout<<thirdMax(v)<<"\n";
	
	return 0;
} 
