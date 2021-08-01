/**
 * Apple, LinkedIn
 * There are a row of N houses, each house can be painted with one of the three colors: Orange, White or Green.
 * The cost of painting each house with a certain color may be different because houses may differ in sizes. 
 * You have to paint all the houses such that NO two adjacent houses have the same color.
 * The cost of painting each house with a certain color is represented by a N x 3 cost matrix.
 * For example, matrix[0][0] is the cost of painting house 0 with color Orange;
 * matrix[1][2] is the cost of painting house 1 with color Green, and so on.
 * Find the minimum total cost to paint all houses.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since August 1, 2021
 */



/** function minCost
 * @param vector<vector<int>>, denoting the matrix showing cost of painting houses with each color respectively
 * @return int, the min cost of painting houses with no adjacent house having the same color
 */ 
int minCost(vector<vector<int>> v)
{
    
    /** Logic :
     * 
     * We will pick the smallest cost color for the first house. Now, for the second house, we have to pick
     * the minimum cost of the remaining two colors (as adjacent houses can not be of same color)
     * Thus, each time, we ignore the color of the previous house and take min of the remaining two colors
     * 
     * The answer will be the minimum value at the last row of the given matrix
     * 
     * Time complexity  : O(N) -- entire matrix is traversed
     * Space complexity : O(1) -- same matrix is utilized
     * 
     */ 
    
    int size = v.size();
    
    if(size == 0)
        return 0;
    
    for(int i=1; i<size; i++)
    {
        v[i][0] += min(v[i-1][1], v[i-1][2]);
        v[i][1] += min(v[i-1][0], v[i-1][2]);
        v[i][2] += min(v[i-1][0], v[i-1][1]);
    }
    
    return min(v[size-1][0], min(v[size-1][1], v[size-1][2]));
    
}



// main function - driver code
int main()
{
	
	vector<vector<int>> v;
	
	
	// TESTCASE
	
	v = {{1, 3, 5}, {2, 4, 6}, {5, 4, 3}};
	cout<<minCost(v)<<"\n";
	
	v = {{14, 2, 11}, {11, 14, 5}, {14, 3, 10}};
	cout<<minCost(v)<<"\n";
	
	v = {{11, 12, 13}, {14, 15, 16}};
	cout<<minCost(v)<<"\n";
	
	
	return 0;
}
