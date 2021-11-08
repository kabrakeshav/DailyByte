/**
 * Given an array digits that represents a non-negative integer, add one to the number and return 
 * the result as an array.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since November 8, 2021
 */



/** function plusOne
 * @param vector<int>, given array
 * @param vector<int>, modified array (by adding 1 to overall digit formed)
 */ 
vector<int> plusOne(vector<int>& digits) 
{
    int carry = 0;
    
    for(int i=digits.size()-1 ; i>=0 ; i--)
    {
        if(i == digits.size()-1)
        {
            digits[i] += 1;
            carry = digits[i]/10;
            digits[i] %= 10;
        }
        else 
        {
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i] %= 10;
        }
    }
    
    if(carry != 0)
        digits.insert(digits.begin(), carry);
    
    return digits;
}



/** function display_answer
 * @param vector<int>, denoting the answer array
 * 
 * Displays the array on console
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
	vector<int> v, ans;
	
	v = {1, 2};
	ans = plusOne(v);
	display_answer(ans);
	
	v = {9, 9};
	ans = plusOne(v);
	display_answer(ans);
	
	return 0;
}
