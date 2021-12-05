/**
 * You are given n pairs of numbers and asked to form a chain. Two pairs of numbers can create a link in 
 * the chain if the second number in the first pair is less than the first number in the second pair. 
 * Return the length of the longest chain you can form.
 * 
 * You may use the pairs of numbers in any order and the first number in a pair is always less than the 
 * second number in a pair.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since December 5, 2021
 */



/** function comp
 * Used to sort the given 2D array based on 2nd value
 */ 
static bool comp(vector<int> & a, vector<int> & b)
{
    if(a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}



/** function findLongestChain
 * @param vector<vector<int>>, given array of pairs
 * @return int, longest chain that can be formed as per given condition
 */ 
int findLongestChain(vector<vector<int>>& pairs) 
{
    int N = pairs.size();
    if(N == 0)
        return 0;
    
    sort(pairs.begin(), pairs.end(), comp);
    
    int ans = 0;
    vector<int> v = pairs[0];
    
    for(int i=0;i<N;i++)
    {
        if(i == 0)
            ans++;
        else if(pairs[i][0] > v[1])
        {
            v = pairs[i];
            ans++;
        }
    }
    
    return ans;
}


 
// main function - driver code
int main()
{
	vector<vector<int>> v;
	
	
	// TESTCASES
	
	v = {{3,4}, {5,6}, {7,8}};
	cout<<findLongestChain(v)<<"\n";
	
	v = {{9,14}, {3,5}, {4,7}};
	cout<<findLongestChain(v)<<"\n";
	
	return 0;
}
