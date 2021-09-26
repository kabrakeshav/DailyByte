/** 
 * Given a list of points, return the k closest points to the origin (0, 0).
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since September 26, 2021
 */



/** function comp
 * @param pair<vector<int>, int>, first pair
 * @param pair<vector<int>, int>, second pair
 * @return bool, if first pair's second value of <= second pair's second value
 * 
 * Use to sort the distace map in kClosest function
 */ 
static bool comp(pair<vector<int>, int> &p1, pair<vector<int>, int> &p2)
{
    return p1.second <= p2.second;
}



/** function kClosest
 * @param vector<vector<int>>, points array
 * @param int, value of K
 * @return vector<vector<int>>, K closest points to origin
 */ 
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
{
    vector<vector<int>> ans;
    
    
    // finding distace of respective points and store them into map
    map<vector<int>, int> mp;
    for(vector<int> v : points)
    {
        double dis = (v[0]*v[0] + v[1]*v[1]);
        mp[v] = dis;
    }
    
    
    // sorting map based on distaces
    vector<pair<vector<int>, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), comp);
    
    
    // acquiring answer
    for(auto it : v)
    {
        if(K-- > 0)
            ans.push_back(it.first);
    }
    
    return ans;
}



/** function print_answer
 * @param vector<vector<int>>, vector to be displayed
 * Displays vector on the console
 */ 
void print_answer(vector<vector<int>> &ans)
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
	
	
	// TESTCASE - 1
	
	v = {{1, 1}, {-2, -2}};
	ans = kClosest(v, 1);
	print_answer(ans);
	
	
	// TESTCASE - 2
	
	v = {{3, 3}, {5, -1}, {-2, 4}};
	ans = kClosest(v, 2);
	print_answer(ans);
	
	return 0;
}

