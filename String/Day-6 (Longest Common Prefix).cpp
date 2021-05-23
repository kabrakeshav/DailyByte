/**
 * Microsoft
 * Given an array of strings, return the longest common prefix that is shared amongst all strings.
 * Note: you may assume all strings only contain lowercase alphabetical characters.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since May 23, 2021
 */



// function to find longest-common-prefix between given
// two strings
string find_prefix(string answer, string str)
{
    string res = "";
    for(int i=0,j=0 ; i<answer.length(),j<str.length() ; i++,j++)
    {
        if(answer[i] != str[j])
            break;
        res += answer[i];
    }
    return res;
}



// function that will take each word from the given vector
// pass it to helper function 'find_prefix' and update
// the longest-common-prefix found so far
string longestCommonPrefix(vector<string>& v) 
{
    if(v.size() == 0)
        return "";
    string answer = v[0];
    
    for(int i=1;i<v.size();i++)
        answer = find_prefix(answer, v[i]);
    
    return answer;
}



int main()
{
	vector<string> v1 = {"colorado", "color", "cold"};
	vector<string> v2 = {"a", "b", "c"};
	vector<string> v3 = {"spot", "spotty", "spotted"};
	
	cout<<longestCommonPrefix(v1)<<"\n";
	cout<<longestCommonPrefix(v2)<<"\n";
	cout<<longestCommonPrefix(v3)<<"\n";
	
	return 0;
}
