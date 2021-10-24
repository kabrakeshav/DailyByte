/**
 * Given a 2D matrix, return a list containing all of its element in spiral order.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


/**
 * @author keshav kabra
 * @since October 24, 2021
 */
 
 

/** function spiralOrder
 * @param vector<vector<int>>, denoting the matrix
 * @return vector<int>, spiral order traversal of the matrix
 */ 
vector<int> spiralOrder(vector<vector<int>>& mat) 
{
    
    // *** suggested : https://www.youtube.com/watch?v=1ZGJzvkcLsA
    
    vector<int> v;
    if(mat.size() == 0)
        return v;
    
    int top, bottom, left, right;
    
    top = 0;
    bottom = mat.size()-1;
    left = 0;
    right = mat[0].size()-1;
    
    int dir = 0;
    int i;
    
    while(top<=bottom && left<=right)
    {
        if(dir == 0)
        {
            for(i=left;i<=right;i++)
                v.push_back(mat[top][i]);
            top++;
        }
        else if(dir == 1)
        {
            for(i=top;i<=bottom;i++)
                v.push_back(mat[i][right]);
            right--;
        }
        else if(dir == 2)
        {
            for(int i=right;i>=left;i--)
                v.push_back(mat[bottom][i]);
            bottom--;
        }
        else if(dir == 3)
        {
            for(int i=bottom;i>=top;i--)
                v.push_back(mat[i][left]);
            left++;
        }
        dir = (dir+1)%4;
    }
    
    return v;
} 



/** function display_answer
 * @param vector, denoting the array
 * prints the given array on the console
 */ 
void display_answer(vector<int> ans)
{
	for(int i : ans)
        cout<<i<<" ";
    cout<<"\n";
}



// main function - driver code
int main()
{
	vector<vector<int>> v;
	vector<int> ans;
	
	
	// TESTCASES
	
	v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	ans = spiralOrder(v);
	display_answer(ans);
	
	v = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	ans = spiralOrder(v);
	display_answer(ans);
	
	return 0;
}
