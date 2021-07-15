/**
 * Google
 * You are given a bag of tokens, an initial energy of E, 
 * and want to maximize your number of points, called score (initially 0). 
 * To gain a single score you can exchange tokens[i] amount of energy 
 * (i.e. if I have 100 energy and a token that has a value 50 I can exchange 50 energy to gain a token).
 *  If you do not have enough energy you can give away a token in exchange for an increase in energy 
 *  by tokens[i] amount (i.e. you give away a token and your energy is increased by the value of 
 *  that token: energy += tokens[i]). Return the maximum number of tokens you can gain.
 *  Note: Each coin may only be used once and you can pickup tokens in any order. Not all tokens need to be used.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since July 15, 2021
 */



/** function bagOfTokensScore
 * @param vector<int>, denoting the array of coins
 * @param int, denoting the power
 * @return int, denoting the maximum points we can collect
 */ 
int bagOfTokensScore(vector<int>& token, int power) 
{
    
    /** Logic :
     * 
     * We always buy tokens where start points (cheapest) and sell tokens where end points (most expensive)
     * hence, we sort the array
     * 
     * We used two pointer approach, if current power is greater than left side's pointer (i), we buy that
     * token (cheapest)
     * If this is not true, we sell a token to increase our power
     * 
     * Time Complexity  : O(N logN) -- sorting array
     * Space Complexity : O(1)
     * 
     */ 
    
    sort(token.begin(), token.end());
    
    int score = 0;
    
    int i = 0;
    int j = token.size()-1;
    int temp_point = 0;
    
    while(i <= j)
    {
        if(power >= token[i]) {
            power -= token[i];
            temp_point++;
            score = max(score, temp_point);
            i++;
        }
        else if(power<token[i] && temp_point>0) {
            temp_point--;
            power += token[j];
            j--;
        }
        else
            break;
    }
    
    return score;
}



// main function - driver code
int main()
{
	vector<int> coin;
	int power;
	
	
	// TESTCASES
	
	coin = {100, 150, 200};
	power = 150;
	cout<<bagOfTokensScore(coin, power)<<"\n";
	coin.clear();
	
	coin = {100,200,300,400};
	power = 200;
	cout<<bagOfTokensScore(coin, power)<<"\n";
	coin.clear();
	
	coin = {300};
	power = 200;
	cout<<bagOfTokensScore(coin, power)<<"\n";
	
	
	return 0;
}

