/**
 * In an alien language, surprisingly, they also use English lowercase letters, but possibly in a 
 * different order. The order of the alphabet is some permutation of lowercase letters.
 * 
 * Given a sequence of words written in the alien language, and the order of the alphabet, return true 
 * if and only if the given words are sorted lexicographically in this alien language.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since November 10, 2021
 */



/** function isAlienSorted
 * @param vector<string>, given array of words
 * @param string, new alien alphabet order
 * @return bool, if given array is lexicographically sorted as per the alien-alphabetic order
 */ 
bool isAlienSorted(vector<string>& words, string order) 
{
    int N = words.size();
    
    for(int i=0;i<N-1;i++)
    {
        int K = words[i].size();
        
        for(int j=i+1;j<N;j++)
        {
            int L = words[j].size();
            int x=0, y=0;
            
            while(x<K && y<L)
            {
                if(words[i][x] == words[j][y])
                {
                    x++; y++;
                }
                
                else
                {
                    size_t ind1 = order.find(words[i][x]);
                    size_t ind2 = order.find(words[j][y]);
                    
                    if(ind1 > ind2)
                        return false;
                        
                    break;
                }
            }
            
            // if word2 ends but word1 has more characters in it
            if(x!=K && y==L)
                return false;
        }
    }
    
    return true;
}



// main function - driver code
int main()
{
	string order;
	vector<string> words;
	
	
	// TESTCASES
	
	order = "worldabcefghijkmnpqstuvxyz";
	words = {"word", "world", "row"};
	cout<<isAlienSorted(words, order)<<"\n";
	
	order = "hlabcdefgijkmnopqrstuvwxyz";
	words = {"hello", "leetcode"};
	cout<<isAlienSorted(words, order)<<"\n";
	
	
	return 0;
}
