/**
 * Google
 * A company is booking flights to send its employees to its two satellite offices A and B. 
 * The cost of sending the ith employee to office A and office B is given by 
 * prices[i][0] and prices[i][1] respectively. Given that half the employees must be sent to office A 
 * and half the employees must be sent to office B,
 * return the minimum cost the company must pay for all their employees’ flights.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since July 19, 2021
 */



/** function twoCitySchedCost
 * @param vector<vector<int>>, denoting the cost array
 * @return int, denoting the min cost to send half people to A and other half to B
 */ 
int twoCitySchedCost(vector<vector<int>>& costs) 
{
    
    /** Logic :
     * 
     * The problem is to send n persons to city A and n persons to city B with minimum cost.
     * The idea is to send each person to city A first, hence we get total cost of sending each person
     * to city A
     * 
     * Now, we need to send n persons to city B.
     * Here, we need to minimize the cost. We have already paid money to go to city A.
     * So, Send the persons to city B who get more refund so that our cost will be minimized.
     * refund will be cost[1] - cost[0]
     * 
     * The positive refund means we need to pay and negative refund means we will get money, hence sort
     * the array and take the maximum refund from it.
     * 
     * Example ::
     * 
     * costs = [[10,20],[30,200],[400,50],[30,20]]
     * totalCost = 10 + 30 + 400 + 30 = 470
     * refund = [10, 170, -350, -10]          { refund[i] = cost[i][1] - cost[i][0] }
     * refund = [-350, -10, 10, 170]          { after sorting }
     * totalCost += 470 + -350 + -10 = 110    { get refund for first N people }
     * minimum cost is 110
     * 
     * 
     * Time complexity  : O(N logN)
     * Space complexity : O(N)
     * 
     */ 
    
	vector<int> refund;
	int ans = 0;
	
	for(vector<int> v : costs)
	{
	    ans += v[0];
	    refund.push_back(v[1] - v[0]);
	}
	
	sort(refund.begin(), refund.end());
	
	for(int i=0;i<costs.size()/2;i++)
	    ans += refund[i];
	   
	return ans;
}



// main function - driver code
int main()
{
	
	vector<vector<int>> v;
	
	
	// TESTCASE
	
	v = {{40, 30}, {300, 200}, {50, 50}, {30, 60}};
	cout<<twoCitySchedCost(v)<<"\n";
	
	
	return 0;
}
