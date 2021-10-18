/**
 * Given an image represented as a 2D array of pixels, return the image rotation ninety degrees.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since October 18, 2021
 */



/** function rotate
 * @param vector<vector<int>>, array to be rotated
 */ 
void rotate(vector<vector<int>>& matrix) 
{
    if(matrix.size() == 0)
        return;
    
    int N = matrix.size();
    
    vector<vector<int>> dest(N, vector<int>(N));
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            dest[j][N-i-1] = matrix[i][j];
        }
    }
    matrix = dest;
}



/** function display_answer
 * @param vector<vector<int>>, denoting the array
 * prints the given array on the console
 */ 
void display_answer(vector<vector<int>> ans)
{
	for(vector<int> v : ans)
	{
    	for(int i : v)
        	cout<<i<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}



// main function - driver code
int main()
{
	vector<vector<int>> v;
	
	
	// TESTCASE
	
	v = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
	rotate(v);
	display_answer(v);
	
	return 0;
}
