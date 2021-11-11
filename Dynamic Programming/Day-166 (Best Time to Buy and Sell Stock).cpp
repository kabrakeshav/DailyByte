/**
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * 
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different 
 * day in the future to sell that stock.
 *
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, 
 * return 0.
 */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


/**
 * @author keshav kabra
 * @since November 11, 2021
 */
 
 

/** function maxProfit
 * @param vector<int>, denoting the array of prices of stock
 * @return int, maximum profit that can be earned by buying stock on one day and selling on other day
 */ 
int maxProfit(vector<int>& prices) 
{
    int N = prices.size();
    if(N == 0)
        return 0;
    
    int max_profit = 0;
    int min_price = INT_MAX;
    
    for(int i=0;i<N;i++)
    {
        if(prices[i] < min_price)
            min_price = prices[i];
        else if(prices[i]-min_price > max_profit)
            max_profit = prices[i]-min_price;
    }
    
    return max_profit;
}

 
 
// main function - driver code
int main()
{
	vector<int> prices;
	
	
	// TESTCASES
	
	prices = {8, 9, 2, 3, 5, 2, 4};
	cout<<maxProfit(prices)<<"\n";
	
	prices = {10, 8, 3, 1};
	cout<<maxProfit(prices)<<"\n";
	
	prices = {7, 1, 5, 3, 6, 4};
	cout<<maxProfit(prices)<<"\n";
	
	
	return 0;
}
