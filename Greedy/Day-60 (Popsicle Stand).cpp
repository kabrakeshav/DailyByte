/**
 * Amazon
 * You’re running a popsicle stand where each popsicle costs $5. 
 * Each customer you encountered pays with either a $5 bill, a $10 bill, or a $20 bill 
 * and only buys a single popsicle. The customers that come to your stand come in the ordered given by
 * the customers array where customers[i] represents the bill the ith customer pays with. 
 * Starting with $0, return whether or not you can serve all the given customers 
 * while also giving the correct amount of change.
 * The customer won't wait for change so his changes must be returned immediately.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since July 17, 2021
 */



/** function popsicleChange
 * @param @vector<int>, denoting the bills of customers
 * @return bool, whether we can serve the customers or not
 */ 
bool popsicleChange(vector<int> &bills) 
{
    
    /** Logic :
     * 
     * If the elements is 5, we simply add it to our variable count for 5. 
     * 
     * If the elements is 10, we need to return 1 coin of five, hence if five-count is 0, we return false,
     * else we decrement the count of 5 by 1 and increase the count of 10 by 1
     * 
     * If the elements is 20, we need :
     *   3 coins of 5 or 1 coin of 5 and 2 coins of 10, we increment and decrement the variables appropriately
     * 
     * Time complexity  : O(N)
     * Space complexity : O(1)
     * 
     */
     
     
	int five = 0;
    int ten = 0;
    
    for(int i : bills)
    {
        if(i == 5)
            five++;
        else if(i == 10)
        {
            if(five == 0)
                return false;
            five--;
            ten++;    
        }
        else if(i == 20)
        {
            if(five == 0)
                return false;
            if(ten == 0)
            {
                if(five < 3)
                    return false;
                five -= 3;
            }
            else
            {
                ten--;
                five--;
            }
        }
    }
    
    return true;
    
}



// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASES
	
	v = {5, 10};
	cout<<popsicleChange(v)<<"\n";
	
	v = {10};
	cout<<popsicleChange(v)<<"\n";
	
	v = {5, 5, 5, 10, 20};
	cout<<popsicleChange(v)<<"\n";
	
	
	return 0;
}

