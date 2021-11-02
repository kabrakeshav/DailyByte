/**
 * 
 * Index of element in array due to which array is not sorted
 * 
 * Students in a class are lining up in ascending height order, but are having some trouble doing so. 
 * Because of this, it’s possible that some students might be out of order. In particular, a student 
 * that is taller than both their neighboring students (i.e. the person to both their left and right) 
 * sticks out like a sore thumb. Given an integer array that represents each students height, return 
 * the index of a “sore thumb”.
 * Note: If there are multiple sore thumbs you may return the index of any of them. All numbers in the 
 * array will be unique. You may assume that to the left and right bounds of the array negative infinity 
 * values exist.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since November 2, 2021
 */



/** function sore_thumb
 * @param vector<int>, denoting the array of lined students
 * @return int, the non-sorted height element index from array
 */ 
int sore_thumb(vector<int> v)
{
	for(int i=1;i<v.size()-1;i++)
	{
		if(v[i]>v[i-1] && v[i]>v[i+1])
			return i;
	}
	return -1;
}



// main function - driver code
int main()
{
	vector<int> v;
	
	
	// TESTCASE
	
	v = {1, 2, 3, 7, 5};
	cout<<sore_thumb(v)<<"\n";
	
	return 0;
}
