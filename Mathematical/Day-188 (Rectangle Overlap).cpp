/**
 * You are given two rectangles as integer arrays and want to determine if they overlap. Each rectangle 
 * will be given as two point, [x1, y1, x2, y2] where (x1, y1) represents the bottom-left hand corner a 
 * rectangle and (x2, y2) represents the top-right hand corner of a rectangle. Given two arrays that 
 * represent rectangles, rect1 and rect2, return whether or not they overlap.
 * Two rectangles overlap if the area of their intersection is positive.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since December 15, 2021
 */



/** function isRectangleOverlap
 * @param vector<int>, first rectangle
 * @param vector<int>, second rectangle
 * @return bool, is rectangles are overlapping
 */ 
bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
{
    // by area
    
    bool width = min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]);
    bool height = min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]);
    
    return width && height;
}
    
    
    
// main function - driver code
int main()
{
	vector<int> r1, r2;
	
	
	//TESTCASES
	
	r1 = {0, 0, 1, 1};
	r2 = {0, 0, 3, 3};
	cout<<isRectangleOverlap(r1, r2)<<"\n";
	
	r1 = {0, 0, 1, 1};
	r2 = {1, 1, 4, 4};
	cout<<isRectangleOverlap(r1, r2)<<"\n";
	
	return 0;
}
