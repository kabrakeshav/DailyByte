/**
 * Amazon
 * Given two arrays of numbers, where the first array is a subset of the second array, 
 * return an array containing all the next greater elements for each element in the first array, 
 * in the second array. If there is no greater element for any element, output -1 for that number.
 */

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since June 11, 2021
 */



/** function nextGreaterElement
 * @param vector, denoting the first vector
 * @param vector, denoting the second vector
 * @return vector, denoting next greater element for nums1 in nums2
 */ 
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
{
    
    /** Logic :
     * 
     * First find the next greater element to right for each element in vector nums2
     * Thus, now for every element of nums2, we know its next greater element to right.
     * Store the next greater element in another vector, say v.
     * 
     * Now, iterate through nums1 (which is subset of nums2) and find the index (ind) of each
     * element of nums1 in nums2.
     * Now, the element at index 'ind' in vector v is the next greater element of nums1 in 
     * nums2.
     * Store this in answer vector and return it.
     * 
     * Time complexity : O(n)  -- iterate through vectors
     * Space complexity : O(n) -- Used additional vectors and stack to solve problem.
     */ 
    
    int N = nums2.size();
    
    vector<int> v;
    stack<int> s;
    
    for(int i=N-1;i>=0;i--)
    {
        if(s.empty())
            v.push_back(-1);
        else if(s.size()>0 && s.top()>nums2[i])
            v.push_back(s.top());
        else if(s.size()>0 && s.top()<=nums2[i])
        {
            while(s.size()>0 && s.top()<=nums2[i])
                s.pop();
            if(s.empty())
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        s.push(nums2[i]);
    }
    
    reverse(v.begin(), v.end());
    
    
    vector<int> ans;
    
    for(int i : nums1)
    {
        int x = find(nums2.begin(), nums2.end(), i)-nums2.begin();
        ans.push_back(v[x]);
    }
    
    return ans;
}



/** function display_answer
 * @param vector, denoting the vector to be displayed on the console
 * Displays vector on the console
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
    
    vector<int> ans;
	
	// TESTCASES
	
	vector<int> v1{4, 1, 2};
	vector<int> v2{1,3,4,2};
	ans = nextGreaterElement(v1, v2);
	display_answer(ans);
	
	vector<int> v3{2, 4};
	vector<int> v4{1, 2, 3, 4};
	ans = nextGreaterElement(v3, v4);
	display_answer(ans);
	
	return 0;
}
