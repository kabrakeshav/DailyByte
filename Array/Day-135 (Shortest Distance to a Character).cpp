/**
 * Apple. 
 *Given a string and a character, return an array of integers where each index is the shortest distance 
 * from the character.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since October 19, 2021
 */
 


/** function shortestToChar
 * @param string, denoting the string
 * @param char, denoting the character
 * @return vector<int>, array of integers where each index is the shortest distance with given character
 */ 
vector<int> shortestToChar(string s, char c) 
{
    
    // storing each index of character 'c' in a vector 'position'
    vector<int> position;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == c)
            position.push_back(i);
    }
    
    
    // to hold answer
    vector<int> ans;
    
    /** Logic :
     * 
     * After storing each index where character 'c' is occurring in string 's', we iterate on given string.
     *
     * Also, make a variable 'ptr' which points to the index in position array where we are considering occurences
     * 
     * Now, if ptr == 0 :
     *   > The given char of string is at left of first 'c' in the string, hence push abs(position[ptr]-i)
     * 
     * If the character is same as occurring ptr's character in position array and ptr is less than position 
     * array's size, we push 0 and increment ptr by 1
     * 
     * Else, the current character of string lies somewhere between two 'c' characters, hence we will push
     * the minimum distance
     * 
     */ 
    
    
    int ptr = 0;
    
    for(int i=0;i<s.length();i++)
    {
        if(i == position[ptr] && ptr+1<position.size()) 
        {
            ans.push_back(0);
            ptr++;
        }
        
        else
        {
            if(ptr == position.size())
                ans.push_back(abs(position[ptr]-i));
            else
            {
                if(ptr == 0)
                    ans.push_back(abs(position[ptr]-i));
                else
                    ans.push_back(min(abs(position[ptr]-i), abs(position[ptr-1]-i)));
            }
        }
    }
    
    return ans;
}



/** function display_answer
 * @param vector, denoting the array
 * prints the given array on the console
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
	string str;
	vector<int> ans;
	
	
	// TESTCASES
	
	str = "dailybyte";
	ans = shortestToChar(str, 'y');
	display_answer(ans);
	
	str = "loveleetcode";
	ans = shortestToChar(str, 'e');
	display_answer(ans);
	
	return 0;
}
