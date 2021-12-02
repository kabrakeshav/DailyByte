/**
 * You are playing a game with a friend. In this game you’re given a string s and you and your friend 
 * take turns making moves. A move consists of flipping two consecutive + signs into - signs. 
 * 
 * Given a string s, return a list containing all possible states of s after you’ve made the first move.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since December 2, 2021
 */



/** function generatePossibleNextMoves
 * @param string, given string
 * @return vector<string>, list containing all possible states of given string after we’ve made the first move as per given rules
 */ 
vector<string> generatePossibleNextMoves(string s) 
{
    vector<string> ans;
    int len = s.length();

    for(int i=0;i<len-1;i++)
    {
        if(s[i]=='+' && s[i+1]=='+')
        {
            string ss = s;
            ss[i] = '-';
            ss[i+1] = '-';
            ans.push_back(ss);
        }
    }

    return ans;
}



/** function display_answer
 * @param vector<string>, containing answer array
 * 
 * displays answer-array on console
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
	vector<string> ans;
	
	ans = generatePossibleNextMoves("++");
	display_answer(ans);
	
	ans = generatePossibleNextMoves("++++");
	display_answer(ans);
	
	ans = generatePossibleNextMoves("---+++-+++-+");
	display_answer(ans);
	
    return 0;
}
