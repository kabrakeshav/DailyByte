/**
 * Amazon
 * A frog is attempting to cross a river to reach the other side. Within the river, 
 * there are stones located at different positions given by a stones array (this array is in sorted order). 
 * Starting on the first stone (i.e. stones[0]), the frog makes a jump of size one potentially landing on 
 * the next stone. If the frog’s last jump was of size x, the frog’s next jump may be of size x - 1, x, 
 * or x + 1. Given these following conditions return whether or not the frog can reach the other side by landing on the last stone.
 * The frog may only jump in the forward direction.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;


/**
 * @author keshav kabra
 * @since July 26, 2021
 */



/** function canCross
 * @param vector<int>, the stones array
 * @record bool, whether frog can reach to end or not
 */ 
bool canCross(vector<int>& stones) 
{
	
	// to record available last steps to reach current position
    unordered_map<int, unordered_set<int>> dp;
    
    
    // position 0 need 0 step to be reached
    dp[0].insert(0);
    
    
    for(int position : stones)
    {
    	
    	// to get all future reachable positions
        for(int step : dp[position])
        {
            
            // jump to position x-1
            if(step-1 > 0)
                dp[position+step-1].insert(step-1);
            
            // jump to position x    
            dp[position+step].insert(step);
            
            // jump to position x+1
            dp[position+step+1].insert(step+1);
        }
    }
    
    
    return !dp[stones.back()].empty();
    
}



// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASES
	
	v = {0, 1, 10};
	cout<<canCross(v)<<"\n";
	
	v = {0, 1, 2, 4};
	cout<<canCross(v)<<"\n";
	
	
	return 0;
}
