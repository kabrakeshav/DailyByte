/**
 * Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining 
 * elements to the right.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since December 13, 2021
 */



/** function duplicateZeros
 * @param vector<int>, given array
 * duplicates 0s to right
 */ 
void duplicateZeros(vector<int>& arr) 
{
    vector<int> v;
    int N = arr.size();
    
    if(N < 2)
        return;
    
    for(int i=0;i<N;i++)
    {
        if(v.size() >= N)
            break;
        
        if(v.size()==N-1 && arr[i]==0)
        {
            v.push_back(0);
            break;
        }
        
        else if(arr[i] == 0) 
        {
            v.push_back(0);
            v.push_back(0);
        }
        else
            v.push_back(arr[i]);
    }
    
    arr = v;
}
    
  

/** function display_answer
 * Displays given vector on console
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
	vector<int> v;
	
	// TESTCASES
	
	v = {1, 0, 2, 3, 0, 4, 5, 0};
	duplicateZeros(v);
	display_answer(v);
	
	v = {1, 0, 4, 0, 5, 8};
	duplicateZeros(v);
	display_answer(v);
	
	
	return 0;
}
