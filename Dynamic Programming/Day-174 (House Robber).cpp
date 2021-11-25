/**
 * You are a professional robber planning to rob houses along a street. Each house has a certain 
 * amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent 
 * houses have security systems connected and it will automatically contact the police if two adjacent 
 * houses were broken into on the same night.
 * 
 * Given an integer array nums representing the amount of money of each house, return the maximum amount 
 * of money you can rob tonight without alerting the police.
*/

#include<iostream>
#include<vector>

using namespace std;


/**
 * @author keshav kabra
 * @since November 25, 2021
 */



/** function rob
 * @param vector<int>, given array denoting amount of money in houses
 * @return int, maximum amount of money we can rob
 */ 
int rob(vector<int>& nums) 
{
    if(nums.size() == 0)
        return 0;
    if(nums.size() == 1)
        return nums[0];
    
    vector<int> v(102, -1);
    v[0] = nums[0];
    v[1] = max(nums[0], nums[1]);
    
    int i;
    for(i=2;i<nums.size();i++)
        v[i] = max(v[i-2]+nums[i], v[i-1]);
    
    return v[i-1];
}
    
    
    
// main function - driver code
int main()
{
	vector<int> nums;
	
	
	//TESTCASES
	
	nums = {1,2,3,1};
	cout<<rob(nums)<<"\n";
	
	nums = {1, 3, 2, 5, 2};
	cout<<rob(nums)<<"\n";
	
	return 0;
}
