/**
 * Google
 * Given an array of integers, return whether or not two numbers sum to a given target, k.
 * Note: you may not sum a number with itself.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/**
 * @author keshav kabra
 * @since May 25, 2021
 */


/**
  * @param v, the vector of integers
  * @param target, the sum
  * @return bool, if two numbers, at separate indices, add up to k
*/
bool twoSum(vector<int> v, int target)
{
    int N = v.size();
    unordered_map<int,int> mp;
    
    /** Logic:
     * maintain a map where array-element is the key and its index in vector is the value
     * Now for every element of vector, if (target_sum - current_element) is present in the array,
     * we have found a pair and hence, return true.
     * Add appropriately into the map.
     * If we come outside of loop, it means there exists no such pair,
     * hence return false
     */
    for(int i=0;i<N;i++)
    {
        if(mp.find(target-v[i]) != mp.end())
        {
            return true;
        }
        mp[v[i]] = i;
    }
   
    return false;
}


// main function - driver code
int main()
{
    
    // TESTCASES
    
	vector<int> v1 = {1, 3, 8, 2};
	cout<<twoSum(v1, 10)<<"\n";
	
	vector<int> v2 = {3, 9, 13, 7};
	cout<<twoSum(v2, 8)<<"\n";
	
	vector<int> v3 = {4, 2, 6, 5, 2};
	cout<<twoSum(v3, 4)<<"\n";
	
	return 0;
}
