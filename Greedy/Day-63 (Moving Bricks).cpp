/**
 * You are transporting bricks on a construction site and want to work as efficiently as possible. 
 * The weight of each brick is given by bricks[i].
 * Given a wheelbarrow that can carry up to (not including) capacity pounds (say 5000),
 * return then maximum number of bricks you can place in your wheelbarrow to transport.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since July 20, 2021
 */



/** function maxNumberOfBricks
 * @param vector<int>, denoting the array of weights of bricks
 * @param int, denoting the maximum capacity
 * @return int, denoting the maximum number of bricks we can place in wheelbarrow to transport
 */ 
int maxNumberOfBricks(vector<int> &v, int K)
{
    
    /** Logic :
     * 
     * We can maximize # of bricks if we pick lighter bricks
	 * So we sort the weights array
	 * We pick up bricks till total weight of picked bricks is < capacity
	 * 
	 * Time Complexity : O(NlogN) for sorting
	 * Space Complexity : O(1)
	 */
    
	sort(v.begin(), v.end());
	
	int weight = 0;
	int ans = 0;
	
	for(int w : v)
	{
		weight += w;
		ans++;
		if(weight >= K)
			break;
	}
	
	if(weight >= K)
		return ans-1;
	
	return ans;
}



// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASES
	
	v = {1, 12, 5, 111, 200, 1000, 10, 9, 12, 15};
	cout<<maxNumberOfBricks(v, 50)<<"\n";
	
	v = {1, 12, 5, 111, 200, 1000, 10};
	cout<<maxNumberOfBricks(v, 50)<<"\n";
	
	v = {1000, 1000, 1000, 2000};
	cout<<maxNumberOfBricks(v, 5000)<<"\n";
	
	v = {1000, 200, 150, 200};
	cout<<maxNumberOfBricks(v, 5000)<<"\n";
	
	
	return 0;
}
