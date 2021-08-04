/**
 * Facebook
 * You are a product manager and currently leading a team to develop a new product. Unfortunately, 
 * the latest version of your product fails the quality check. Since each version is developed based 
 * on the previous version, all the versions after a bad version are also bad.
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
 * which causes all the following ones to be bad.
 * You are given an API bool isBadVersion(version) which returns whether version is bad. Implement 
 * a function to find the first bad version. You should minimize the number of calls to the API.
 * 
 * https://leetcode.com/problems/first-bad-version/
 * 
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since August 4, 2021
 */



// The API isBadVersion is defined for you.
// bool isBadVersion(int version);



/** function firstBadVersion
 * @param int, total number of versions
 * @return int, the first bad version
 */
int firstBadVersion(int n) 
{
    
    /** Logic :
     * 
     * Simple binary search is employed to solve the problem
     * 
     * We find the mid of all the versions available. If the mid element is a bad-version, the first bad-version
     * must be on the left side and hence, by the rule of binary search, we alter right pointer to mid-1.
     * 
     * Also, if the mid element is not a bad-version, the first bad-version must be on the right side and 
     * hence, by the rule of binary search, we alter left pointer to mid+1.
     * 
     * Since, there must be a bad-version, we return the left pointer
     * 
     */ 
    
    int left = 1;
    int right = n;
    
    while(left <= right)
    {
        int mid = left + (right-left)/2;
        if(isBadVersion(mid) == true)
            right = mid-1;
        
        if(isBadVersion(mid) == false)
            left = mid+1;
        
    }
    return left;
    
}



// main function - driver code
int main()
{
	
	cout<<firstBadVersion(5)<<"\n";
	return 0;
}
