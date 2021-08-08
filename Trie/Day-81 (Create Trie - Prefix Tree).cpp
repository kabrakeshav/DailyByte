/**
 * Microsoft
 * Implement a trie class that supports insertion and search and prefix-finding functionalities.
 * Note: You may assume only lowercase alphabetical characters will added to your trie.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @author keshav kabra
 * @since August 8, 2021
 */



/* class Trie
 * supports supports insertion and search and prefix-finding functionalities
 */
class Trie 
{
	public:
	    
	    vector<string> v;
	    
	    
	    Trie() 
		{
	        v.clear();
	    }
	    
	    
	    /** Inserts a word into the trie. */
	    void insert(string word) 
		{
	        this->v.push_back(word);
	    }
	    
	    
	    /** Returns if the word is in the trie. */
	    bool search(string word) 
		{
	        bool res;
	        res = find(v.begin(), v.end(), word) != v.end();
	        
	        return res;
	    }
	    
	    
	    /** Returns if there is any word in the trie that starts with the given prefix. */
	    bool startsWith(string prefix)
		{        
	        for(string str : v)
	        {
	            auto res = mismatch(prefix.begin(), prefix.end(), str.begin());
	            
	            if(res.first == prefix.end())  // 'prefix' is prefix of str
	                return true;
	        }
	        
	        return false;
	    }
	    
};



// main function - driver code
int main()
{
	
	// TESTCASE
	
	Trie* trie = new Trie();
	trie->insert("programming");
	
	cout<<trie->search("computer")<<"\n"; // returns false.
	cout<<trie->search("programming")<<"\n"; // returns true.
	
	return 0;
}
