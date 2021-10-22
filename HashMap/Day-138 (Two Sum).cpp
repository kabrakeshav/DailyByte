/**
 * Given an integer array that is sorted in ascending order and a value target, return two unique 
 * indices such that the values at those indices sums to the given target.
 * Note: If no two such indices exist, return null.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


/**
 * @author keshav kabra
 * @since October 22, 2021
 */



/** function twoSum
 * @param vector, array of numbers
 * @param int, target sum
 * @return vector, indices whose elements sums up to target
 */ 
vector<int> twoSum(vector<int>& nums, int target) 
{
   int N = nums.size();
   vector<int> ans;
   unordered_map<int,int> mp;
   
   for(int i=0;i<N;i++)
   {
       if(mp.find(target-nums[i]) != mp.end())
       {
           ans.push_back(mp[target-nums[i]]);
           ans.push_back(i);
           return ans;
       }
       mp[nums[i]] = i;
   }
   
   return ans;
}



/** function display_answer
 * @param vector, denoting the array
 * prints the given array on the console
 */ 
void display_answer(vector<int> ans)
{
	for(int i : ans)
        cout<<i<<" ";
    cout<<"\n";
}



// main function - driver code
int main()
{
	vector<int> v, ans;
	
	
	// TESTCASES
	
	v = {1, 2, 5, 7, 9};
	ans = twoSum(v, 10);
	display_answer(ans);
	
	v = {1, 3, 8};
	ans = twoSum(v, 13);
	display_answer(ans);
	
	return 0;
}
 
