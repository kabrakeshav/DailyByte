/**
 * Given an array of integers, nums, every value appears three times except one value which only 
 * appears once. Return the value that only appears once.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


/**
 * @author keshav kabra
 * @since December 15, 2021
 */



/** function singleNumber
 * @param vector<int>, given array
 * @return int, number whose frequency is 1
 */ 
int singleNumber(vector<int>& nums) 
{
    unordered_map<int, int> mp;
    
    for(int i : nums)
    {
        mp[i]++;
    }
    
    for(auto it : mp)
        if(it.second == 1)
            return it.first;
    
    return 0;
}
    


// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASES
	
	v = {1, 2, 2, 2, 3, 3, 3};
	cout<<singleNumber(v)<<"\n";
	
	v = {3, 3, 2, 5, 2, 2, 5, 3, 9, 5};
	cout<<singleNumber(v)<<"\n";
	
	return 0;
}
