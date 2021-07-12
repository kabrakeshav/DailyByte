/**
 * Apple
 * Given a list of positive numbers without duplicates and a target number, 
 * find all unique combinations of the numbers that sum to the target.
 * You may use the same number more than once.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since July 12, 2021
 */



/** function get_answer
 * @param vector<int>, denoting the array of numbers
 * @param int, denoting the sum we want to generate
 * @param int, index from where we need to make permutations
 * @param int, denoting the size of vector 'v' (of numbers)
 * @param vector<vector<int>>, to store all possible answers
 * @param vector<int>, array to store one particular answer (to be added to 'ans')
 */ 
void get_answer(vector<int> v, int target, int index, int sz, vector<vector<int>> &ans, vector<int> &res)
{
    
    /** Logic :
     * 
     * If 'target' is equal to 0, it means 'res' is storing one particular combination that sums-up to 'target',
     * hence push it to answer vector.
     * 
     * If 'target' becomes less than 0, we can not make the sum from previous choices, hence simply return.
     * 
     * Else, iterate on array 'v' from index 'index' to its size, at every step push the number to temporary
     * vector 'res' and make recursive call to get_answer by subtracting v[i] from target.
     * At the end, pop this element out of 'res' - to perform backtracking
     * 
     */ 
    
    if(target == 0)
    {
        ans.push_back(res);
        return;
    }
    if(target < 0)
        return;
    
    for(int i=index;i<sz;)
    {
        res.push_back(v[i]);
        get_answer(v, target-v[i], i, sz, ans, res);
        i++;
        res.pop_back();
    }
}



/** function combinationSum
 * @param vector<int>, denoting the array of numbers
 * @param int, denoting the sum we want to generate
 * @return vector<vector<int>>, denoting the array to store all unique combinations of elements which forms target
 */ 
vector<vector<int>> combinationSum(vector<int>& v, int target) 
{
    
    /** Logic :
     * 
     * If size of vector is 0, return empty answer.
     * 
     * Else, call a recursive-backtracking function 'get_answer' to store all possible answers into 'ans', 
     * return 'ans' at the end
     * 
     */ 
    
    int sz = v.size();
    vector<vector<int>> ans;

    if(sz == 0)
        return ans;

    vector<int> res;

    get_answer(v, target, 0, sz, ans, res);

    return ans;
}



/** function print_answer
 * @param vector<vector<<int>>, denoting the array which stores all unique combinaations of sum
 *
 * displays the contents on vector on console
 *
 */
void print_answer(vector<vector<int>> v)
{
	for(vector<int> t : v)
	{
		for(int i : t)
			cout<<i<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}



// main function - driver code 
int main()
{
	
	vector<int> num;
	vector<vector<int>> ans;
	
	
	// TESTCASE 
	
	num = {2, 4, 6, 3};
	ans = combinationSum(num, 6);
	print_answer(ans);
	
	
	return 0;
}
