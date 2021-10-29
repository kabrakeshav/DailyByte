/**
 * You are given the list of prices of a particular stock. Each element in the array represents the price 
 * of the stock at a given second throughout the current day. Return the maximum profit you can make 
 * trading this stock.
 * Note: You may only ever buy and sell a single share of the stock, but you may make multiple 
 * transactions (i.e. buys and sells)
 */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


/**
 * @author keshav kabra
 * @since October 29, 2021
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
	vector<int> v;
	
	
	// TESTCASE
	
	v = {8, 3, 2, 4, 6, 4, 5};
	cout<<maxProfit(v)<<"\n";
	
	return 0;
}/**
 * You are given the list of prices of a particular stock. Each element in the array represents the price 
 * of the stock at a given second throughout the current day. Return the maximum profit you can make 
 * trading this stock.
 * Note: You may only ever buy and sell a single share of the stock, but you may make multiple 
 * transactions (i.e. buys and sells)
 */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


/**
 * @author keshav kabra
 * @since October 29, 2021
 */



/** function maxProfit
 * @param vector, array denoting the prices of share
 * @return int, max profit that can be earned by purchasing and selling the stock
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
	vector<int> v;
	
	
	// TESTCASE
	
	v = {8, 3, 2, 4, 6, 4, 5};
	cout<<maxProfit(v)<<"\n";
	
	return 0;
}
