/** 
 * You’re about to set sail off a pier and first want to count the number of ships that are already 
 * in the harbor. The harbor is deemed safe to sail in if the number of boats in the harbor is strictly 
 * less than limit. 
 * Given a 2D array that presents the harbor, where O represents water and S represents a ship, return 
 * whether or not it’s safe for you to set sail.
 * Note: All ships in the harbor can only lie entirely vertically or entirely horizontally and cannot 
 * be connected to another ship.
 */

#include<iostream>
#include<vector>
using namespace std;



/**
 * @author keshav kabra
 * @since September 23, 2021
 */



/** function get_answer
 * @param vector<vector<char>>, denoting 2D array (harbor)
 * @param int, denoting the limit
 * @return bool, whether or not it’s safe for boat to set sail
 */ 
bool get_answer(vector<vector<char>> &v, int lim)
{
	int cnt = 0;
	
	for(vector<char> temp : v)
	{
		for(char ch : temp)
		{
			if(ch == 'S')
				cnt++;
		}
	}
	
	return cnt+1 < lim;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	vector<vector<char>> v = {{'O', 'O', 'S'}, {'S', 'O', 'O'}, {'O', 'O', 'S'}};
	cout<<get_answer(v, 5)<<"\n";
	
	v = {{'O', 'O', 'O'}, {'S', 'O', 'S'}, {'O', 'O', 'S'}};
	cout<<get_answer(v, 3)<<"\n";
	
	return 0;
}
