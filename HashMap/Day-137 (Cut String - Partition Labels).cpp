/**
 * Given a string s containing only lowercase characters, return a list of integers representing the 
 * size of each substring you can create such that each character in s only appears in one substring.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since October 21, 2021
 */
 


/** function partitionLabels
 * @param string, string to be splitted
 * @return vector, vector denoting sizes of each splitted strings
 */ 
vector<int> partitionLabels(string s) 
{
    
    // refer : https://www.youtube.com/watch?v=5NCjHqx2v-k (Nick White)
    
    if(s.size() == 0)
        return {};
    
    
    // storing last occurence of each character in array of size 26
    vector<int> last_ind(26, 0);
    for(int i=0;i<s.size();i++)
        last_ind[s[i] - 'a'] = i;
    
    
    vector<int> ans;
    
    int start=0, end=0;
    for(int i=0;i<s.length();i++) 
    {
        end = max(end, last_ind[s[i]-'a']);
        if(i == end)
        {
            ans.push_back(end-start+1);
            start = end+1;
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
	
	str = "abacdddecn";
	ans = partitionLabels(str);
	display_answer(ans);
	
	
	str = "aba";
	ans = partitionLabels(str);
	display_answer(ans);
	
	
	str = "ababcbacadefegdehijhklij";
	ans = partitionLabels(str);
	display_answer(ans);
	
	return 0;
}
