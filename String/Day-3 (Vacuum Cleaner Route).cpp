/**
 * Amazon
 * Given a string representing the sequence of moves a robot vacuum makes, return whether or not it will 
 * return to its original position. 
 * The string will only contain L, R, U, and D characters, representing left, right, up, and down respectively.
 */


#include<iostream>
using namespace std;

/**
 * @author keshav kabra
 * @since May 19, 2021
 */


/**
	 * @param string of moves, s
	 * @return is vaccum cleaner returns to original position
	 * Logic : return if number of L equals to number of R and
	 *         number of U equals to number of D.
*/
bool return_to_original_position(string str)
{
	int lr=0, ud=0;
	
	for(int i=0;i<str.length();i++)
	{
		if(str[i] == 'L')
			lr++;
		else if(str[i] == 'R')
			lr--;
		else if(str[i] == 'U')
			ud++;
		else if(str[i] == 'D')
			ud--;
	}
	
	return (lr==0 && ud==0);
}



// main function - driver code
int main()
{
	
	// TESTCASES
	cout<<return_to_original_position("LR")<<"\n";
	cout<<return_to_original_position("URURD")<<"\n";
	cout<<return_to_original_position("RUULLDRD")<<"\n";
	
	return 0;
}
