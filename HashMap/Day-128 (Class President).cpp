/**
 * High school students are voting for their class president and you’re tasked with counting the votes. 
 * Each presidential candidates is represented by a unique integer and the candidate that should win 
 * the election is the candidate that has received more than half the votes. Given a list of integers, 
 * return the candidate that should become the class president.
 * Note: You may assume there is always a candidate that has received more than half the votes.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


/**
 * @author keshav kabra
 * @since October 11, 2021
 */



/** function answer
 * @param vector<int>, denoting array of votes
 * @return int, candidate that has received more than half the votes
 */
int answer(vector<int> v)
{
	int sz = v.size();
	
	unordered_map<int, int> mp;
	
	for(int i : v)
	{
		mp[i]++;
		if(mp[i] > sz/2)
			return i;
	}
	
	return -1;
}



// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASES
	
	v = {1, 1, 2, 2, 1};
	cout<<answer(v)<<"\n";
	
	v = {1, 3, 2, 3, 1, 2, 3, 3, 3};
	cout<<answer(v)<<"\n";
	
	return 0;
}
