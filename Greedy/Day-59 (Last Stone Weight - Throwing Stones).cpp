/**
 * Amazon
 * You are given a group of stones, all of which have a positive weight. At each turn, 
 * we select the heaviest two stones and smash them together. When smashing these two 
 * stones together, one of two things can happen:

	1. If the stones are both the same weight, both stones are destroyed
	2. If the weights of the stones are not equal, the smaller of the two stones is 
	   destroyed and the remaining stone’s weight is updated to the difference 
	   
 * Continue smashing stones together until there is at most one stone left and return 
 * the weight of the remaining stone. If not stones remain, return zero.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since July 16, 2021
 */



/** function lastStoneWeight
 * @param vector<int>, denoting the vector of stones (showing weight of each stone)
 * @return int, weight of the last stone remained after all smashes
 */ 
int lastStoneWeight(vector<int>& stones) 
{
    
    /** Logic :
     * 
     * We first sort the vector into descending order and loop till the size of vector is atleast 2
     * 
     * If the weight of two stones are equal (both will be destroyed), hence we delete both the numbers
     * from vector
     * Else, we subtract the weight of lighter stone from heavier stone and delete the lighter stone and
     * again sort the array in descending order
     * 
     * At the end if size of 'stones' vector is 0, it means all stones destroyed, return 0
     * Otherwise return the only element of ''stones' vector (its first element)
     * 
     */ 
    
    sort(stones.begin(), stones.end(), greater<int>());
    
    while(stones.size() >= 2)
    {
        if(stones[0] == stones[1])
        {
            stones.erase(stones.begin()+0);
            stones.erase(stones.begin()+0);
        }
        else
        {
            stones[0] -= stones[1];
            stones.erase(stones.begin()+1);
            sort(stones.begin(), stones.end(), greater<int>());
        }
    }
    
    if(stones.size() == 0)
        return 0;
    return stones[0];
    
}



// main function - driver code
int main()
{
	vector<int> stones;
	
	
	// TESTCASES
	
	stones = {2, 4, 3, 8};
	cout<<lastStoneWeight(stones)<<"\n";
	
	stones = {1, 2, 3, 4};
	cout<<lastStoneWeight(stones)<<"\n";
	
	
	return 0;
}
