/**
 * Given an integer array, nums, return the largest unique value in nums.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since December 5, 2021
 */



/** function unique_num
 * @param vector<int>, given array
 * @return int, largest unique element in array
 */ 
int unique_num(vector<int> v)
{
	int len = v.size()-1;
	
	sort(v.begin(), v.end());
	
	int ans = -1;
	for(int i=0;i<len-1;i++)
	{
		if(v[i] != v[i+1])
			ans = v[i];
		else
		    i++;
	}
	
	if(v[len-1] != v[len])
		return v[len];
	return ans;
}



// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASES
	
	v = {4, 9, 2, 9};
	cout<<unique_num(v)<<"\n";
	
	v = {8, 1, 10, 1, 4, 8, 4, 10};
	cout<<unique_num(v)<<"\n";
	
	return 0;
}
