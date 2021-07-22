/**
 * Apple
 * Given a staircase where the ith step has a non-negative cost associated with it given by cost[i], 
 * return the minimum cost of climbing to the top of the staircase. 
 * You may climb one or two steps at a time and you may start climbing from either the first 
 * or second step. Size of input >= 2.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since July 22, 2021
 */




/** GREEDY APPROACH
 * function minCostClimbingStairs_DP
 * @param vector<int>, denoting the ocst array
 * @return int, denoting minimum cost for climbing steps
 */
int minCostClimbingStairs_Greedy(vector<int> cost) 
{       
    
    /** Logic :
     * 
     * At each step we take min cost of both available steps and continue to go ahead
     * At the end, return the minimum cost
     * 
     */
     
	int N = cost.size();
	        
	for(int i=2;i<N;i++)
		cost[i] += min(cost[i-1], cost[i-2]);
	        
	return min(cost[N-1], cost[N-2]);
}





/** function get_answer
 * @param vector<int>, denoting the cost array
 * @param int, denoting the starting index
 * @param int, denoting the last index
 * @param vector<vector<int>>, the cache array - for DP
 */ 
int get_answer(vector<int> cost, int start, int end, vector<vector<int>> &dp)
{
    
    /** Logic :
     * 
     * At the first index, we have two options - either to take first step or the second step, hence we need
     * to make two recursive calls for first index
     * 
     * Otherwise, we make a single recursive call - adding the cost of current step and making recursive calls
     * to get minimum answer from next and next-to-next step
     * 
     */ 
    
    if(start > end)
        return 0;
    
    if(start == end)
        return cost[end];
    
    if(dp[start][end] != 0)
        return dp[start][end];
    
    if(start == 0) 
    {
        return dp[start][end] = min(cost[start] + min(get_answer(cost, start+1, end, dp), get_answer(cost, start+2, end, dp)), 
                    cost[start+1] + min(get_answer(cost, start+2, end, dp), get_answer(cost, start+3, end, dp)));
    }
    
    return dp[start][end] = cost[start] + min(get_answer(cost, start+1, end, dp), get_answer(cost, start+2, end, dp));
}



/** DYNAMIC PROGRAMMING APPROACH
 * function minCostClimbingStairs_DP
 * @param vector<int>, denoting the ocst array
 * @return int, denoting minimum cost for climbing steps
 */ 
int minCostClimbingStairs_DP(vector<int> cost) 
{
    vector<vector<int>> dp(cost.size(), vector<int> (cost.size()));
    return get_answer(cost, 0, cost.size()-1, dp);
}




// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASES
	
	v = {5, 10, 20};
	cout<<minCostClimbingStairs_Greedy(v)<<"\n";
	cout<<minCostClimbingStairs_DP(v)<<"\n\n";
	
	v = {1, 5, 10, 3, 7, 2};
	cout<<minCostClimbingStairs_Greedy(v)<<"\n";
	cout<<minCostClimbingStairs_DP(v)<<"\n";
	
	
	return 0;
}
