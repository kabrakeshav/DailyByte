/**
 * Facebook
 * Given an array of coins (value > 0) representing coins of different denominations and an integer amount representing a total amount of money.
 * Return the fewest number of coins that you need to make up that amount. 
 * If that amount of money cannot be made up by any combination of the coins, return -1.
 * Assume that you have an infinite number of each kind of coin.
 */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


/**
 * @author keshav kabra
 * @since July 23, 2021
 */
 


/** function coinChange
 * @param vector<int>, denoting the coin array
 * @param int, the sum we want to make
 * @return int, minimum number of coins required to make the given sum
 *    ( -1 if sum can not be created from given coins )
 */ 
int coinChange(vector<int>& coins, int sum) 
{
    
    /** Logic :
     * 
     * Variation of Unbounded Knapsack Problem
     * https://www.youtube.com/watch?v=I-l6PBeERuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=16
     * 
     * The row of dp table denoted the size of coin array available and the column denoted the sum we want to 
     * make
     * We will get answer on the last cell of the dp table
     * 
     * The first column will be initialized with 0 as if required sum is 0, we will need minimum 0 coins
     * The first row will be initialized with INT_MAX-1 as if required coin array size is 0, we can not
     * create the sum - hence infinite coins required
     * 
     * We will initialize second row as well - if the sum required is divisible by coin's value we will store
     * the division else we store INT_MAX-1 there (we can not create that sum)
     * Example, if coin is of 3 and required sum is 3 - we will store 1, if same coin is used to generate
     * sum of 4, we will store INT_MAX-1 (can't be generated)
     * 
     * Now, fill the table with same logic of Unbounded Knapsack - take the coin or do not take the coin
     * and return the minimum value
     * 
     */ 
    
    int N = coins.size();
    
    int dp[N+1][sum+1];
    
    // first column
    for(int i=0;i<=N;i++)
        dp[i][0] = 0;
    
    // first row
    for(int i=0;i<=sum;i++)
        dp[0][i] = INT_MAX-1;
    
    
    // second row
    for(int i=1;i<=sum;i++)
    {
        if(i%coins[0] == 0) // perfectly divisible
            dp[1][i] = i/coins[0];
        else
            dp[1][i] = INT_MAX-1;
    }
    
    
    for(int i=2;i<=N;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            // we can take coin only if it is <= to required sum
            if(coins[i-1] <= j)
                dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[N][sum]==INT_MAX-1 ? -1 : dp[N][sum];
    
} 



// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASE 
	
	v = {1,5, 10, 25};
	cout<<coinChange(v, 78)<<"\n";
	
	
	return 0;
}
