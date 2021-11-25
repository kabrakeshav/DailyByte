/**
 * Given a string, s, that represents a Roman numeral, return its associated integer value.
 */

#include<iostream>

using namespace std;


/**
 * @author keshav kabra
 * @since November 25, 2021
 */



/** function value
 * @param char, denoting one character of given roman string (which can be - I, V, X, L, C, D, M)
 * @return int, integer equivalent of that roman character
 */ 
int value(char r)
{
    if (r == 'I') 
        return 1; 
    if (r == 'V') 
        return 5; 
    if (r == 'X') 
        return 10; 
    if (r == 'L') 
        return 50; 
    if (r == 'C') 
        return 100; 
    if (r == 'D') 
        return 500; 
    if (r == 'M') 
        return 1000; 
  
    return -1; 
}



/** function romanToInt
 * @param string, string form of roman digit
 * @return int, integer equivalent of given roma string
 */ 
int romanToInt(string s)
{
    
    int res = 0;
    
    for(int i=0;i<s.length();i++)
    {
        int val = value(s[i]);
        
        if(i+1 < s.length())
        {
            int val2 = value(s[i+1]);
            if(val >= val2)
                res += val;
            else
            {
                res += val2-val;
                i++;
            }
        }
        else
            res += val;
    }
    
    return res;
}
    
    
    
// main function - driver code
int main()
{
	string roman;
	
	
	// TESTCASES

	roman = "DCLII";
	cout<<romanToInt(roman)<<"\n";
	
	roman = "VIII";
	cout<<romanToInt(roman)<<"\n";
	
	roman = "MCMXCIV";
	cout<<romanToInt(roman)<<"\n";
	
	roman = "LVIII";
	cout<<romanToInt(roman)<<"\n";
	
	roman = "IV";
	cout<<romanToInt(roman)<<"\n";

	
	return 0;
}
