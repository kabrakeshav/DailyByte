/**
 * In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. 
 * (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
 * We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
 * 
 * Return the minimum number of rotations so that all the values in tops are the same, or all the 
 * values in bottoms are the same.
 * If it cannot be done, return -1.
 */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


/**
 * @author keshav kabra
 * @since November 9, 2021
 */



/** function make_top
 * @param vector<int>, top array of dominoes
 * @param vector<int> bottom array of dominoes
 * @return int, minimum number of rotations so that all the values in either top are the same
 */ 
int make_top(vector<int> &top, vector<int> &bottom)
{
    
    /** Logic :
     * 
     * We will try to make the values in top array same. For this, in function 'minDominoRotations', first time
     * we passed (top, bottom) as arguments and for second time we passed (bottom, top) as arguments.
     * 
     * Firstly we take count of each number (1-6) present in 'top' array into the vector 'cnt'. Now, we will 
     * iterate on each of numbers in range [1, 6] and the values in 'top' array in inner-loop.
     * 
     * If the value of 'i' is not equal to array top's current value, we need to swap it with corresponding
     * value in 'bottom' array.
     * The condition for swapping values from 'bottom' array is that, bottom's jth index should be equal to i - if
     * not, we can not swap the dominoes and hence break the loop.
     * 
     */ 
    
    vector<int> cnt(7, 0);
    for(int i : top)
        cnt[i] += 1;
    
    int mn = INT_MAX;
    for(int i=1;i<=6;i++)
    {
        int temp = 0;
        for(int j=0;j<top.size();j++)
        {
            if(top[j] != i)
            {
                if(bottom[j] != i) 
                {
                    temp = -1;
                    break;
                }
                temp++;
            }
        }
        
        if(temp != -1)
            mn = min(mn, temp);
    }
    
    return mn==INT_MAX ? -1 : mn;
}



/** function minDominoRotations
 * @param vector<int>, top array of dominoes
 * @param vector<int> bottom array of dominoes
 * @return int, minimum number of rotations so that all the values in either top or bottom are the same
 */ 
int minDominoRotations(vector<int>& top, vector<int>& bottom) 
{
    int t = make_top(top, bottom);
    int b = make_top(bottom, top);
    
    return min(t, b);
}



// main function - driver code
int main()
{
    
	vector<int> top, bottom;
	
	// TESTCASES
	
	top = {2, 1, 2, 4, 2, 2};
	bottom = {5, 2, 6, 2, 3, 2};
	cout<<minDominoRotations(top, bottom)<<"\n";
	
	top = {3, 5, 1, 2, 3};
	bottom = {3, 6, 3, 3, 4};
	cout<<minDominoRotations(top, bottom)<<"\n";
	
	return 0;
}
