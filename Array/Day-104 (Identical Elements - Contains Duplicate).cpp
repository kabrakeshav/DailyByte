/** Google
 * Given an array, nums, and an integer k, return whether or not two unique indices exist such 
 * that nums[i] = nums[j] and the two indices i and j. 
 * j are at most k elements apart.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since September 13, 2021
 */



/** function containsDuplicate
 * @param vector<int>, denoting the array
 * @param int, the value k
 * @param int, maximum difference (always 0 in this question)
 * @return bool, two same value elements exist in array with nums[i]=nums[j] and abs(i-j)<=k
 */ 
bool containsDuplicate(vector<int>& nums, int k, int t) 
{   
    
    /** Logic :
     * 
     * Store each element and its index in a vector of pair (val, index) and sort the vector by value
     * 
     * Now, while iterating on the vector, if given conditions match, return true and if loop ends, return
     * false
     * 
     */ 
    
    int N = nums.size();
    
    vector<pair<int,int>> v(N);
    
    for(int i=0;i<N;i++)
    {
        v[i].first = nums[i];
        v[i].second = i;
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(abs((long)v[i].first-v[j].first) <= t)
            {
                if(abs(v[i].second-v[j].second) <= k)
                    return true;
            }
            else
                break;
        }
    }
    return false;
}



// main function - driver code
int main()
{
	vector<int> v;
	int k;
	
	
	// TESTCASES
	
	v = {1, 2, 1};
	k = 1;
	cout<<containsDuplicate(v, k, 0)<<"\n";
	
	v = {2, 3, 2};
	k = 2;
	cout<<containsDuplicate(v, k, 0)<<"\n";
	
	v = {1, 2, 3, 1};
	k = 3;
	cout<<containsDuplicate(v, k, 0)<<"\n";
	
	
	return 0;
}
