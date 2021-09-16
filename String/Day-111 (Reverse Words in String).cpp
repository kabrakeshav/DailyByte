/**
 * Given a string s, reverse the words.
 *
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since September 16, 2021
 */
 
 

/** function reverseWords
 * @param string, the string
 * @return string, reversed words string
 */ 
string reverseWords(string s) 
{
    vector<string> v;
    string str = "";
    for(char ch : s)
    {
        if(ch == ' ')
        {
            if(str!="" && str!=" ")
                v.push_back(str);
            str = "";
            continue;
        }
        
        str += ch;
    }
    
    v.push_back(str);
    
    reverse(v.begin(), v.end());
    
    string res = "";
    for(int i=0; i<v.size(); i++) 
	{
        if(v[i]!="" && v[i]!=" ")
            res += v[i];
        if(v[i]!="" && v[i]!=" " && i < v.size()-1)
            res += " ";
    }
    
    return res;
}



// main function - driver code
int main()
{
	string str;
	
	
	// TESTCASES
	
	str = "The Daily Byte";
	cout<<reverseWords(str)<<"\n";
	
	str = "  hello world  ";
	cout<<reverseWords(str)<<"\n";
	
	str = "a good   example";
	cout<<reverseWords(str)<<"\n";
	
	
	return 0;
}
