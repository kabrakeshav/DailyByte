/**
 * You are given a license key represented as a string s that consists of only alphanumeric characters and 
 * dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.
 * 
 * We want to reformat the string s such that each group contains exactly k characters, except for the 
 * first group, which could be shorter than k but still must contain at least one character. Furthermore, 
 * there must be a dash inserted between two groups, and you should convert all lowercase letters to 
 * uppercase.
 * 
 * Return the reformatted license key.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since December 1, 2021
 */



/** function licenseKeyFormatting
 * @param string, license key
 * @param int, group length in reformatted license-key
 * @return string, the reformatted license-key
 */ 
string licenseKeyFormatting(string S, int K) 
{
    string str = "";
    
    for(char ch : S)
    {
        if(ch>='a' && ch<='z')
            str += ch-32;
        else if(ch != '-')
            str += ch;
    }
    
    reverse(str.begin(), str.end());
    
    vector<string> v;
    
    for(int i=0; i<str.length(); i+=K)
    {
        string sub = str.substr(i, K);
        if(sub.length() > 0)
            v.push_back(sub);
    }
    
    reverse(v.begin(), v.end());
    
    str = "";
    
    for(int i=0;i<v.size();i++)
    {
        reverse(v[i].begin(), v[i].end());
        str += v[i];
        if(i != v.size()-1)
            str += "-";
    }
    
    return str;
}
    
    
    
// main function - driver code
int main()
{
	
	// TESTCASES
	
	cout<<licenseKeyFormatting("5F3Z-2e-9-w", 4)<<"\n";
	cout<<licenseKeyFormatting("2-5g-3-J", 2)<<"\n";
	cout<<licenseKeyFormatting("49DkeDb39LXI", 3)<<"\n";
	cout<<licenseKeyFormatting("9Dklsi3nsEKE92", 3)<<"\n";
}
