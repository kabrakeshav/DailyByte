/**
 * Google
 * Given two integer arrays, return their intersection.
 * Note: the intersection is the set of elements that are common to both arrays.
 */
 
// header files
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

/**
 * @author keshav kabra
 * @since May 30, 2021
 */


/** function intersection
 * @param vector, denoting first array
 * @param vector, denoting second array
 * @return vector, denoting the intersection of vector1 and vector2
 */ 
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
    
    // to store answer (intersection of nums1 and nums2)
    vector<int> ans;
    
    // if any of vector is empty
    // the intersection will be empty array
    if(nums1.size()==0 || nums2.size()==0)
        return ans;
    
    // removing the duplicates from vectors in-place
    nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
    nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
    
    /** Loop through vectors after removing duplicates
     * if an elements is now present in both vectors,
     * it will be included in the intersection
     * We have taken set to remove any chances of any duplications
     */ 
    set<int> a;
    for(int i=0;i<nums1.size();i++)
    {
        if(find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end())
        {
            a.insert(nums1[i]);
        }
    }
    
    // returning answer (intersection)
    for(int i : a)
        ans.push_back(i);
    return ans;
}



/** function display
 * @param vector, denoting the array (vector) to be displayed
 * prints the vector elements on the colsole
 */ 
void display(vector<int> &v)
{
    for(int i : v)
        cout<<i<<" ";
    cout<<"\n";
}



// main function - driver code
int main()
{
    vector<int> ans;
    
	// TESTCASES
	
	vector<int> v1 = {2, 4, 4, 2};
	vector<int> v2 = {2, 4};
	ans = intersection(v1, v2);
	display(ans);

    v1 = {1, 2, 3, 3};
	v2 = {3, 3};
	ans = intersection(v1, v2);
	display(ans);

    v1 = {2, 4, 6, 8};
	v2 = {1, 3, 5, 7};
	ans = intersection(v1, v2);
	display(ans);
	
	return 0;
}

