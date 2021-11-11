/**
 * You are given an array of interval objects, which each consist of a start time and an end time. Each 
 * interval object represents when a particular meeting starts and ends. 
 * Return whether or not someone could attend every meeting.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since November 11, 2021
 */



/** function comp
 * Utility function to sort 2-D array of function 'can_attend'
 * Sorts as per first value and then second value
 */ 
static bool comp(vector<int> &a, vector<int> &b)
{
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}
    
    
   
/** function can_attend
 * @param vector<vector<int>>, array of intervals
 * @return bool, true of none intervals overlap else false
 */ 
bool can_attend(vector<vector<int>> v)
{
	int sz = v.size();
	
	sort(v.begin(), v.end(), comp);
	
	int x = 0;
	for(int i=1;i<sz;i++)
	{
		if(v[i][0] <= v[x][1])
			return false;
	}
	
	return true;
}


// main function - driver code
int main()
{
	vector<vector<int>> intervals;
	
	
	// TESTCASES
	
	intervals = {{1, 3}, {5, 10}};
	cout<<can_attend(intervals)<<"\n";
	
	intervals = {{1, 8}, {5, 9}};
	cout<<can_attend(intervals)<<"\n";
	
	
	return 0;
}
