/**
 * Given an array of integers, nums, each element in the array either appears once or twice. Return a 
 * list containing all the numbers that appear twice.
 * Note: Each element in nums is between one and nums.length (inclusive).
 */

#include<iostream>
#include<vector>
#include<set>
using namespace std;


/**
 * @author keshav kabra
 * @since September 29, 2021
 */



/** function findDuplicate
 * @param vector<int>, denoting array of numbers
 * @return vector<int>, all the numbers that appeared twice in given array
 */ 
vector<int> findDuplicate(vector<int>& nums) 
{
	vector<int> ans;
	
	set<int> st;
    for(int i : nums)
    {
        if(st.find(i) != st.end())
            ans.push_back(i);
        st.insert(i);
    }
    
    return ans;
}



/** function display_answer
 * @param vector, denoting the array
 * prints the given array on the console
 */ 
void display_answer(vector<int> v)
{
    for(int i : v)
        cout<<i<<" ";
    cout<<"\n";
}



// main function - driver code
int main()
{
	vector<int> v, ans;
	
	
	// TESTCASES
	
	v = {2, 3, 1, 5, 5};
	ans = findDuplicate(v);
	display_answer(ans);
	
	v = {1, 2, 3};
	ans = findDuplicate(v);
	display_answer(ans);
	
	v = {7, 2, 2, 3, 3, 4, 4};
	ans = findDuplicate(v);
	display_answer(ans);
	
	return 0;
}

