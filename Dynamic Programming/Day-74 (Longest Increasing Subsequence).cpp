/**
 * Facebook
 * Given an array of unsorted, strictly positive (i.e. >0) integers, 
 * return the length of its longest strictly increasing subsequence (LIS).
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since July 31, 2021
 */



/** function lengthOfLIS
 * @param vector<int>, denoting the array
 * @return int, length of longest increasing subsequence
 */ 
int lengthOfLIS(vector<int>& nums) 
{
    
    /** Logic :
     * 
     * We will use a table (array) is size of given array to store the LIS upto that particular index (for eg, 
     * the number in table at index 3 states the LIS upto index 3 in original array)
     * We initialize the array with 1 as every number is increasing in itself (hence, the minimum answer
     * will be 1)
     * 
     * Now, we iterate on array and check smaller numbers to the left of it and make appropriate changes
     * in the table
     * 
     * Time complexity  : O(N^2)
     * Space complexity : O(N)
     * 
     */ 
    
    int N = nums.size();
    if(N == 0)
        return 0;
    
    vector<int> ans(N, 1);
    int ans_len = 1;
    
    for(int i=1;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[j] < nums[i])
                ans[i] = max(ans[i], ans[j]+1);
        }
        ans_len = max(ans[i], ans_len);
    }
    return ans_len;
}



// main function - driver code
int main()
{
	
	vector<int> v;
	
	// TESTCASE
	v = {1, 9, 7, 4, 7, 13};
	cout<<lengthOfLIS(v)<<"\n";
	
	return 0;
}
