/**
 * You are building a pool in your backyard and want to create the largest pool possible. The largest 
 * pool is defined as the pool that holds the most water. The workers you hired to dig the hole for 
 * your pool didn’t do a great job and because of this the depths of the pool at different areas are 
 * not equal. 
 * Given an integer array of non-negative integers that represents a histogram of the different heights 
 * at each position of the hole for your pool, return the largest pool you can create.
 * 
 * Same as - Container with Most Water
 */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


/**
 * @author keshav kabra
 * @since November 1, 2021
 */



/** function maxArea
 * @param vector, denoting the array (pool / buildings)
 * @return int, max water that can be trapped
 */ 
int maxArea(vector<int>& height) 
{
    int ans = INT_MIN;
    
    int l = 0;
    int r = height.size()-1;
    
    while(l < r)
    {
        int mn = min(height[l], height[r]);
        ans = max(ans, mn*(r-l));
        
        if(height[l] < height[r])
            l++;
        else
            r--;
    }
    
    return ans;
}



// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASES
	
	v = {1, 4, 4, 8, 2};
	cout<<maxArea(v)<<"\n";
	
	
	return 0;
}
