/** 
 * Facebook
 * Given N points on a Cartesian plane, return the minimum time required to visit all points in 
 * the order that they’re given.
 * Note: You start at the first point and can move one unit vertically, horizontally, or diagonally 
 * in a single second.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since August 24, 2021
 */



/** function minTimeToVisitAllPoints
 * @param vector<vector<int>>, denoting the points array
 * @return int, minimum time to visit all points in the order that they’re given.
 */ 
int minTimeToVisitAllPoints(vector<vector<int>>& points) 
{
    
    /** Logic :
     * 
     * By observing the question carefully, we can find out that the time to visit two adjacent points
     * is the max of the absolute differences between their respective coordinates
     * 
     */ 
    
    int ans = 0;
    
    vector<int> p1 = points[0];
    
    for(int i=1;i<points.size();i++)
    {
        vector<int> p2 = points[i];
        
        int dx = abs(p2[0] - p1[0]);
        int dy = abs(p2[1] - p1[1]);
        
        ans += max(dx, dy);
        
        p1 = p2;
    }
    
    return ans;
}



// main function - driver code
int main()
{
	vector<vector<int>> points;
	
	
	// TESTCASES
	
	points = {{0, 0}, {1, 1}, {2, 2}};
	cout<<minTimeToVisitAllPoints(points)<<"\n";
	
	points = {{0, 1}, {2, 3}, {4, 0}};
	cout<<minTimeToVisitAllPoints(points)<<"\n";
	
	points = {{1, 1}, {3, 4}, {-1, 0}};
	cout<<minTimeToVisitAllPoints(points)<<"\n";
	
	
	return 0;
}
