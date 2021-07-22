/**
 * Amazon
 * Given an integer array, two players take turns picking a number from the ends of the array.
 * First, player one picks a number (either the left end or right end of the array) followed by player
 * two. Each time a player picks a particular numbers, it is no longer available to the other player.
 * This picking continues until all numbers in the array have been chosen. 
 * Once all numbers have been picked, the player with strictly larger score wins. 
 * Return whether or not player one will win. Player one starts first always.
 * You may assume that each player is playing to win 
 * (i.e. both players will always choose the maximum of the two numbers each turn) 
 * and that there will always be a winner (no tie).
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since July 21, 2021
 */



/** functiom get_answer
 * @param vector<int>, denoting the integer array
 * @param int, denoting the starting index (from where the integer can be picked)
 * @param int, denoting the ending index (from where the integer can be picked)
 * @param int, denoting score of player-1
 * @param int, denoting score of player-2
 * @param bool, denoting the turn of players (true for turn of player-1)
 * @return bool, denoting whether player-1 wins or not
 */ 
bool get_answer(vector<int> &nums, int start, int end, int s1, int s2, bool turn)
{
    
    /** Logic :
     * 
     * If starting index is greater than ending index, there is no element to be picked, hence return if
     * player-1 score is greater than or equal to player-2 score
     * 
     * We need to return true in any case where player-1 wins.
     * 
     * Hence, if it is player-1 turn, we can pick element either from start or from end, hence make recursive call
     * appropriately
     * We are doing OR operation as if player-1 wins in any case we return true
     * 
     * if it is player-2 turn, we can pick element either from start or from end, hence make recursive call
     * appropriately
     * We are doing AND operation as to return false, player-1 should not win in any case (or player-2 must
     * win in both cases)
     * 
     */ 
    
    if (start > end) 
        return s1 >= s2;
    
    if (turn) {
        return (get_answer(nums, start+1, end, s1+nums[start], s2, !turn)
                || get_answer(nums, start, end-1, s1+nums[end], s2, !turn));
    }
    
    else {
        return get_answer(nums, start+1, end, s1, s2+nums[start], !turn)
                && get_answer(nums, start, end-1, s1, s2+nums[end], !turn);
    }
    
}



/** function PredictTheWinner
 * @param vector<int>, denoting the integer array
 * @return boolean, denoting whether player-1 wins or not
 */ 
bool PredictTheWinner(vector<int>& nums) 
{  
    
    // recursive function
    return get_answer(nums, 0, nums.size()-1, 0, 0, true);
}



// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASE
	
	v = {1, 2, 3};
	cout<<PredictTheWinner(v)<<"\n";
	
	
	return 0;
}
