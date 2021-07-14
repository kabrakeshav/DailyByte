/**
 * Amazon
 * A ship is about to set sail and you are responsible for its safety precautions. 
 * More specifically, you are responsible for determining how many life rafts to carry onboard. 
 * You are given a list of all the passengers’ weights and are informed that a single life raft
 * has a maximum capacity of limit and can hold at most two people. 
 * Return the minimum number of life rafts you must take onboard to ensure the safety of all your passengers.
 * You may assume that a the maximum weight of any individual is at most limit.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since July 14, 2021
 */



/** function numRescueBoats
 * @param vector<int>, denoting the weights of passengers
 * @param int, denoting the single life raft's maximum capacity
 * @return int, denoting the minimum number of life rafts must be take to ensure the safety of all passengers
 */ 
int numRescueBoats(vector<int>& weight, int limit) 
{
    
    /** Logic :
     * 
     * Sort the array of weights so as to allow the heaviest weight person to go with lowest weight person and
     * hence minimizing the total number of boats
     * 
     * We iterate on the weight array with two pointer approach - one pointer (i) at beginning of array and other
     * (j) to the end of the array
     * Now if sum of weights at 'i' and 'j' are less than equal to limit, we can send them together, hence 
     * decrement 'j'
     * Else, we need to arrange a separate boat for the heavier person, hence only 'i' will be increased
     * 
     * Time complexity  : O(N logN) - for sorting the array
     * Space complexity : O(1)      - no extra space required
     * 
     */ 
    
    sort(weight.begin(), weight.end(), greater<int>());
    int ans = 0;
    
    for(int i=0, j=weight.size()-1 ; i <= j ; i++)
    {
        if (weight[i] + weight[j] <= limit) 
        {
            j--;
        }
        ans++;
    }
    
    return ans;
}



// main function - driver code
int main()
{
	
	// TESTCASE - 1
	
	vector<int> weight = {1, 3, 5, 2};
	int limit = 5;
	cout<<numRescueBoats(weight, limit)<<"\n";
	weight.clear();
	
	
	// TESTCASE - 2
	
	weight = {1, 2};
	limit = 3;
	cout<<numRescueBoats(weight, limit)<<"\n";
	weight.clear();
	
	
	// TESTCASE - 3
	
	weight = {4, 2, 3, 3};
	limit = 5;
	cout<<numRescueBoats(weight, limit)<<"\n";
	
	
	return 0;
}

