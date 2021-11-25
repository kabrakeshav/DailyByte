/**
 * Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the 
 * integers in the range [1, n] that do not appear in nums.
 */

#include<iostream>
#include<vector>

using namespace std;


/**
 * @author keshav kabra
 * @since November 25, 2021
 */



/** function findDisappearedNumbers
 * @param vector<int>, given array of numbers
 * @return vector<int>, lit of all numbers that are missing in given array in range [1, length of given array]
 */ 
vector<int> findDisappearedNumbers(vector<int>& nums) 
{
    if(nums.empty())
        return {};
    
    int maxi = nums.size();
    
    
    vector<int> mp(maxi+1, 0);
    
    for(int i : nums)
        mp[i] = 1;
    
    nums.clear();
    
    for(int i=1;i<=maxi;i++)
        if(mp[i] == 0)
            nums.push_back(i);
    
    return nums;
}
    
    

/** 
 * function display_answer
 * @param vector<int>, the answer vector to be displayed
 * 
 * Displays the vector on console
 * 
 */ 
void display_answer(vector<int> v)
{
	for(int i : v)
		cout<<i<<" ";
	cout<<"\n";
}



// main function - driver code
int main()
{
	vector<int> nums, ans;
	
	
	// TESTCASES
	
	nums = {4,3,2,7,8,2,3,1};
	ans = findDisappearedNumbers(nums);
	display_answer(ans);
	
	nums = {1,1};
	ans = findDisappearedNumbers(nums);
	display_answer(ans);
	
	nums = {1, 2, 3, 3};
	ans = findDisappearedNumbers(nums);
	display_answer(ans);
	
	nums = {3, 2, 4, 1, 5};
	ans = findDisappearedNumbers(nums);
	display_answer(ans);
	
	return 0;
}
