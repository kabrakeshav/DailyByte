/** 
 * 01 knapsack Problem
 * You’ve broken into an art gallery and want to maximize the value of the paintings you 
 * steal. All the paintings you steal you place in your bag which can hold at most W pounds. 
 * Given that the weight and value of the ith painting is given by weights[i] and values[i] 
 * respectively, return the maximum value you can steal.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since August 3, 2021
 */



/** function knapsack
 * @param vector<int>, weight array
 * @param vector<int>, values (profit) array
 * @param int, maximum capacity of the bag
 * @return int, maximum value you can get in the bag
 */
int knapsack(vector<int> wt, vector<int> val, int W)
{
    
    /** Logic :
     * 
     * We make a DP table of size (N+1, W+1) - each row showing how many items are considered for putting into
     * the bag and each column showing the capacity of bag considered
     * 
     * If either size of array (N) is zero or capacity of bag is zero, we can take maximum profit of 0 only,
     * hence fill first row and first column with 0
     * 
     * Now, for a weight to be put into bag is considered only if its weight is less than current capacity of the
     * bag
     * Now, above condition meets, we have two choices - either to take that weight or to ignore it
     * If we take the weight, our profit is increased by its value and bag capacity is decreased by its weight
     * If we ignore the weight, nothing changes
     * 
     * If the weight is greater than capacity of bag, we cannot take that item
     * 
     */
    
	int N = wt.size();
    int table[N+1][W+1];
    
    // first row
    for(int i=0;i<=W;i++)
        table[0][i] = 0;
    
    // first column
    for(int i=0;i<=N;i++)
        table[i][0] = 0;
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(wt[i-1] <= j)
                table[i][j] = max(table[i-1][j], val[i-1]+table[i-1][j-wt[i-1]]);
            else
                table[i][j] = table[i-1][j];
        }
    }
    
    return table[N][W];
    
}



// main function - driver code
int main()
{
	
	vector<int> weight, values;
	int W;
	
	
	// TESTCASE - 1
	
	W = 10;
	weight = {4, 1, 3};
	values = {4, 2, 7};
	cout<<knapsack(weight, values, W)<<"\n";
	
	
	// TESTCASE - 2
	
	W = 5;
	weight = {2, 4, 3};
	values = {3, 7, 2};
	cout<<knapsack(weight, values, W)<<"\n";
	
	
	// TESTCASE - 3
	
	W = 7;
	weight = {1, 3, 4};
	values = {3, 5, 6};
	cout<<knapsack(weight, values, W)<<"\n";
	
	
	return 0;
}
