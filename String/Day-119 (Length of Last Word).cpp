/**
 * Given a string, s, return the length of the last word.
 * string may contain spaces at end
 * Note: You may not use any sort of split() method.
 */

#include<iostream>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since September 28, 2021
 */
 


/** function findLength
 * @param string, string of characters
 * @return int, length of last word in string
 */ 
int findLength(string s)
{
    reverse(s.begin(), s.end());
    int ans = 0;
    
    bool char_f = false;
    for(int i=0;i<s.length();i++)
    {
        
        // ignoring the spaces at end
        if(char_f==false && s[i]==' ')
            continue;
            
        if(char_f==true && s[i]==' ')
            break;
            
        else
        {
            char_f = true;
            ans++;
        }
    }
    
    return ans;
}



// main function - driver code
int main()
{
    
    // TESTCASES
    
	cout<<findLength("The Daily Byte")<<"\n";
	cout<<findLength("Start Coding Here   ")<<"\n";
	cout<<findLength("abcdefg   ")<<"\n";
	
	return 0;
}
