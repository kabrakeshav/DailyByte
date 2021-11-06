/** 
 * Given a list of integers, nums, return a list containing all triplets that sum to zero.
 * 
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that 
 * i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since November 6, 2021
 */



/** function threeSum
 * @param vector<int>, given array of numbers
 * @return vector<vector<int>>, all triplets that sums up to 0
 */ 
vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> ans;
    
    if(nums.size() < 3)
        return ans;
    
    sort(nums.begin(), nums.end());
    
    for(int i=0;i<nums.size()-2;i++)
    {
        if(i==0 || (i>0 && nums[i]!=nums[i-1]))
        {
            int low = i+1;
            int high = nums.size()-1;
            int req_sum = 0-nums[i];
            
            while(low < high)
            {
                if(nums[low]+nums[high] == req_sum)
                {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    
                    while(low<high && nums[low]==nums[low+1])
                        low++;
                    while(low<high && nums[high]==nums[high-1])
                        high--;
                    
                    low++;
                    high--;
                }
                else if(nums[low]+nums[high] > req_sum)
                    high--;
                else
                    low++;
            }
        }
    }
    
    return ans;
}
    


/** function display_answer
 * @param vector<int>, denoting the array to be displayed
 * 
 * Displays the array on console
 */ 
void display_answer(vector<vector<int>> ans)
{
	for(vector<int> v : ans)
	{
		for(int i : v)
			cout<<i<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}



// main function - driver code
int main()
{
	vector<int> v;
	vector<vector<int>> ans;
	
	
	// TESTCASES
	
	v = {0};
	ans = threeSum(v);
	display_answer(ans);
	
	v = {0, -1, 1, 1, 2, -2};
	ans = threeSum(v);
	display_answer(ans);
	
	
	return 0;
}
