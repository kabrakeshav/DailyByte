/**
 * Apple
 * You are serving people in a lunch line and need to ensure each person gets a “balanced” meal. 
 * A balanced meal is a meal where there exists the same number of food items as drink items. 
 * Someone is helping you prepare the meals and hands you food items (i.e. F) or a drink items (D) 
 * in the order specified by the items string. 
 * Return the maximum number of balanced meals you are able to create without being able to modify items.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since July 18, 2021
 */



/** function count_balanced_meal
 * @param string, denoting the string of meal
 * @return int, denoting the total number of balanced meals
 */
int count_balanced_meal(string str)
{
	
	/** Logic :
	 * count 'F' and 'D' while traversing the string, anytime they are equal to each other,
	 * increment the 'ans' by 1
	 * Return 'ans' at the end
	 *
	 * Time complexity  : O(N)
	 * Space complexity : O(1)
	 */
	
	int ans = 0;
	int food=0, drink=0;
	
	for(char ch : str) 
	{
		if(ch == 'D')
			drink++;
		else if(ch == 'F')
			food++;
		
		if(food == drink)
			ans++;
	}
	
	return ans;
}



// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<count_balanced_meal("FDFDFD")<<"\n";
	cout<<count_balanced_meal("FDFFDFDD")<<"\n";
	
	
	return 0;
}
