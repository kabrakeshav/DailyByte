/** Amazon 
 * You are at a birthday party and are asked to distribute cake to your guests. Each guest is only 
 * satisfied if the size of the piece of cake they’re given, matches their appetite (i.e. is greater 
 * than or equal to their appetite). 
 * Given two arrays, appetite and cake where the ith element of appetite represents the ith guest’s 
 * appetite, and the elements of cake represents the sizes of cake you have to distribute, return the 
 * maximum number of guests that you can satisfy.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since September 13, 2021
 */



/** function max_people
 * @param vector<int>, appetite array
 * @param vector<int>, cake size array
 * @return int, max number of people whose appetite can be satisfied with given cakes
 */ 
int max_people(vector<int> app, vector<int> cake)
{
    
    /** Logic :
     * 
     * We sort both the arrays, and iterate on appetite array
     * 
     * If appetite[i] is less than or equal to cake[index], we increment the answer variable by one, else
     * we break the loop (since array is sorted, no other appetite can be satisfied) and return answer
     * 
     */ 
    
	sort(app.begin(), app.end());
	sort(cake.begin(), cake.end());
	
	int ans = 0;
	
	int ind = 0;
	for(int i=0;i<app.size();i++)
	{
		if(app[i] <= cake[ind])
		{
			ans++;
			ind++;
		}
		else
			break;
	}
	
	return ans;
	
}



// main function - driver code
int main()
{
	vector<int> app, cake;
	
	
	// TESTCASES
	
	app = {1, 2, 3};
	cake = {1, 2, 3};
	cout<<max_people(app, cake)<<"\n";
	
	app = {3, 4, 5};
	cake = {2};
	cout<<max_people(app, cake)<<"\n";
	
	
	return 0;
}
