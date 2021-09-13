/** 
 * Given an integer array nums, return an array where each element i represents the product of 
 * all values in nums excluding nums[i].
 * Note: You may assume the product of all numbers within nums can safely fit within an integer range.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since September 13, 2021
 */



/** function productExceptSelf
 * @param vector<int>, denoting the array
 * @return vector<int>, denoting the answer array
 */ 
vector<int> productExceptSelf(vector<int>& nums) 
{
    
    /** Logic :
     * 
     * We store the multiplication result of all non-zero elements of array into a variable 'mult'
     * Boolean variables 'flag' is denoting if we have one 0 in array and 'two' denotes if we have two 0s
     * in tha array
     * 
     * If the array contains two 0s (variable 'two' is true), we return an array with all zeroes as multiplication
     * result is always be 0
     * 
     * Else, we iterate on the given array and store 
     *   -> mult/array[i] for non-zero elements as that will be multiplication result by excluding that number
     *   -> 'mult' itself if array[i]=0 as that will be multiplication result by excluding 0 
     *   -> 0 if 'flag' is true which denotes we have a non-excluding 0 in the array
     * 
     * return this new array as answer
     * 
     */ 
    
    int mult = 1;
    bool flag = false;
    bool two = false;
    
    for(int i : nums)
    {
        if(i != 0)
            mult *= i;
        if(flag==true && i==0)
            two = true;
        if(i == 0)
            flag = true;
    }
    
    vector<int> ans(nums.size(), 0);
    if(two == true)
        return ans;
    
    ans.resize(0);
    for(int i : nums)
    {
        if(i == 0)
            ans.push_back(mult);
        else if(flag == true)
            ans.push_back(0);
        else
            ans.push_back(mult/i);
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
	
	v = {1, 2, 3};
	ans = productExceptSelf(v);
	display_answer(ans);
	
	v = {1, 2, 3, 4};
	ans = productExceptSelf(v);
	display_answer(ans);
	
	v = {-1, 1, 0, -3, 3};
	ans = productExceptSelf(v);
	display_answer(ans);
	
	v = {0, 1, 2, 0, 3};
	ans = productExceptSelf(v);
	display_answer(ans);
	
	
	return 0;
}
