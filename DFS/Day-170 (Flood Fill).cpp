/**
 * An image is represented by an m x n integer grid image where image[i][j] represents the pixel 
 * value of the image.
 * 
 * You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image 
 * starting from the pixel image[sr][sc].
 * 
 * To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to 
 * the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally 
 * to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned 
 * pixels with newColor.
 * 
 * Return the modified image after performing the flood fill.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since November 21, 2021
 */



/** function dfs
 * @param vector<vector<int>>, given image vector
 * @param int, current row
 * @param int, current col
 * @param int, old color
 * @param int, new color
 * 
 * DFS algorithm implemented
 * 
 */ 
void dfs(vector<vector<int>> &image, int i, int j, int old, int color)
{
    if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j] != old)
        return;
    
    image[i][j] = color;
    
    dfs(image, i-1, j, old, color);
    dfs(image, i+1, j, old, color);
    dfs(image, i, j-1, old, color);
    dfs(image, i, j+1, old, color);
}



/** function floodFill
 * @param vector<vector<int>>, given image vector
 * @param int, given row 
 * @param int, given col
 * @param int, given new color
 * @return vector<vector<int>>, the answer-image vector from new given color
 */ 
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
{
    if(image[sr][sc] != newColor)
        dfs(image, sr, sc, image[sr][sc], newColor);
    
    return image;
}



/** 
 * function display_answer
 * @param vector<vector<int>>, the answer vector to be displayed
 * 
 * Displays the vector on console
 * 
 */ 
void display_answer(vector<vector<int>> v)
{
	for(vector<int> t : v)
	{
		for(int i : t)
			cout<<i<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}



// main function - driver code
int main()
{
	vector<vector<int>> image, ans;
	
	
	//TESTCASE - 1
	
	image = {{0,1,1}, {0,1,0}, {1,1,1}};
	ans = floodFill(image, 1, 1, 3);
	display_answer(ans);
	
	
	//TESTCASE - 2
	
	image = {{1,1,1}, {1,1,0}, {1,0,1}};
	ans = floodFill(image, 1, 1, 2);
	display_answer(ans);
	
	return 0;
}
