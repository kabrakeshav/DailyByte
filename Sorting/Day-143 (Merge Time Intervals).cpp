/**
 * Given a list of interval object, merge all overlapping intervals and return the result.
 * Note: an interval object is a simple object that contains a start time and end time and can be 
 * constructed by passing a starting and ending time to the constructor.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since October 27, 2021
 */



/** function comp
 * @param vector<int>, first pair of time interval
 * @param vector<int>, second pair of time interval
 * @return bool, if first interval is smaller than the second one
 */ 
static bool comp(vector<int> &a, vector<int> &b)
{
    if(a[0] == b[0])
        return a[1] < b[1];
        
    return a[0] < b[0];
}



/** function merge
 * @param vector<vector<int>>, denoting the intervals array
 * @return vector<vector<int>>, denoting the merged intervals array
 */ 
vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    int sz = intervals.size();
    
    sort(intervals.begin(), intervals.end(), comp);
    
    vector<vector<int>> ans;
    
    ans.push_back(intervals[0]);
    int x = 0;
    
    for(int i=1;i<sz;i++)
    {
        if(intervals[i][0] <= ans[x][1])
        {
            if(ans[x][1] < intervals[i][1])
                ans[x][1] = intervals[i][1];
        }
        
        else
        {
            ans.push_back(intervals[i]);
            x++;
        }
    }
    
    return ans;
}



/** function display_answer
 * @param vector, denoting the array of overlapped intervals
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
	
	v = {{1, 3}, {1, 8}};
	ans = merge(v);
	display_answer(ans);
	
	v = {{1, 2}, {2, 6}, {7, 10}};
	ans = merge(v);
	display_answer(ans);
	
	return 0;
}
