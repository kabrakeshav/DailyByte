/**
 * Given a 2D matrix nums, return the matrix transposed.
 * Note: The transpose of a matrix is an operation that flips each value in the matrix across 
 * its main diagonal.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since October 6, 2021
 */



/** function transpose
 * @param vector<vector<int>>, matrix to be transposed
 * @return vector<vector<int>>, transposed matrix
 */ 
vector<vector<int>> transpose(vector<vector<int>>& A) 
{
    if(A.size() == 0)
        return A;
    
    int row = A.size();
    int col = A[0].size();
    
    vector<vector<int>> ans(col, vector<int>(row,0));
    
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            ans[j][i] = A[i][j];
    
    return ans;
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
	vector<vector<int>> v, ans;
	
	
	// TESTCASES
	
	v = {{1, 2}, {3, 4}};
	ans = transpose(v);
	display_answer(ans);
	
	v = {{2, 4, -1}, {-10, 5, 11}, {18, -7, 6}};
	ans = transpose(v);
	display_answer(ans);
	
	return 0;
}
