/** Given a list of words, return all the words that require only a single row of a keyboard to type.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since September 9, 2021
 */



/** function findWords
 * @param vector<string>, denoting the array of string
 * @return vector<string>, array of all words that require only a single row of a keyboard to type
 */ 
vector<string> findWords(vector<string>& words) 
{
    
    // each row of keyboard is stored as different string
    string s1 = "qwertyuiop";
    string s2 = "asdfghjkl";
    string s3 = "zxcvbnm";
    
    // to store answer
    vector<string> ans;
    
    
    // iterating on array of string
    for(int i=0;i<words.size();i++)
    {
        
        // initially we assume row is 0 (we are on none of the rows of keyboard)
        // set this variable based on first character found in string
        int row = 0;
        
        // iterating on each character of the word
        for(int j=0;j<words[i].size();j++)
        {
            
            // converting character to its lower-case form
            char ch = tolower(words[i][j]);
            
            // if we found the character in string s1 and 'row' is either 0 (first char of string) or
            // it is already 1, continue on to the next term
            // same for row 2 and 3
            if(s1.find(ch)!=string::npos && (row==0 || row==1))
                row = 1;
            else if(s2.find(ch)!=string::npos && (row==0 || row==2))
                row = 2;
            else if(s3.find(ch)!=string::npos && (row==0 || row==3))
                row = 3;
                
            // we need to change rows    
            else {
                row = -1;
                break;
            }
        }
        
        // pusing the word only if it can be typed using one row of keyboard
        if(row != -1)
            ans.push_back(words[i]);
    }
    
    // returning answer
    return ans;
}
    


/** function display_answer
 * @param vector, denoting the array
 * prints the given array on the console
 */ 
void display_answer(vector<string> v)
{
    for(string str : v)
        cout<<str<<" ";
    cout<<"\n";
}



// main function - driver code
int main()
{
	vector<string> words, ans;
	
	
	// TESTCASE - 1
	
	words = {"two", "dad", "cat"};
	ans = findWords(words);
	display_answer(ans);
	
	
	// TESTCASE - 2
	
	words = {"ufo", "xzy", "byte"};
	ans = findWords(words);
	display_answer(ans);
	
	
	// TESTCASE - 3
	
	words = {"Hello","Alaska","Dad","Peace"};
	ans = findWords(words);
	display_answer(ans);
	
	return 0;
}
