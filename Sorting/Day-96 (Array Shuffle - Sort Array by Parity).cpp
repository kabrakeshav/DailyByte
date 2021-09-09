/**
 * Amazon
 * Given an array of integers, nums, sort the array in any manner such that when i is even, nums[i] is 
 * even and when i is odd, nums[i] is odd.
 * Note: It is guaranteed that a valid sorting of nums exists.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since August 27, 2021
 */



/** function sortArrayByParity
 * @param vector<int>, denoting the array of numbers
 * @return vector<int>, array in which even index contains even number and vice-versa
 */ 
vector<int> sortArrayByParity(vector<int>& nums) 
{
    
    /** Logic :
     * 
     * We make an array of same size as to that of passed array and while iterating on passed array, we
     * fill the values appropriately
     * 
     * 
     * Time complexity  : O(N) -- Entire array is traversed
     * Space complexity : O(N)
     * 
     */ 
    
    int sz = nums.size();
    
    vector<int> ans(sz, 0);
    
    int even_index = 0;
    int odd_index = 1;
    
    for(int i=0;i<sz;i++)
    {
        if(nums[i]%2 == 0)
        {
            ans[even_index] = nums[i];
            even_index += 2;
        }
        else
        {
            ans[odd_index] = nums[i];
            odd_index += 2;
        }
    }
    
    return ans;
}



/** function display_answer
 * @param vector, denoting the array
 * prints the given array on the console
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
	vector<int> v, ans;
	
	
	// TESTCASES
	
	v = {1, 2, 3, 4};
	ans = sortArrayByParity(v);
	display_answer(ans);
	
	v = {4, 2, 5, 7};
	ans = sortArrayByParity(v);
	display_answer(ans);
	
	
	return 0;
}
