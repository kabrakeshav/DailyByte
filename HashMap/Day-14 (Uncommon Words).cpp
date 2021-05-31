/**
 * Amazon
 * Given two strings representing sentences, return the words that are not common to both strings AND appear exactly once.
 * (i.e. the words that only appear in one of the sentences). 
 * You may assume that each sentence is a sequence of words (without punctuation) correctly separated
 * using space characters.
 */
 

// header files
#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;

/**
 * @author keshav kabra
 * @since May 31, 2021
 */


/** function uncommonFromSentences
 * @param string, denoting first string
 * @param string, denoting second string
 * @return vector, denoting the words that are uncommon in the two strings
 */ 
vector<string> uncommonFromSentences(string str1, string str2)
{
    
    /** Logic :
     * We split the strings by space and store them in respective vectors.
     * Now, in map, we store the count of each string from the above created
     * vectors.
     * 
     * To get answer vector, we iterate over the map and check if the 'value' is 1,
     * If 'value' is 1, it means that this 'key' (string) has occurred only once in
     * both strings (and hence uncommon). 
     * So, we add it to our answer-vector.
     * At the end, we have to return this answer-vector.
     */ 
    
	vector<string> v1, v2;
	string word;
	
	// splitting string by space
	istringstream ss1(str1);
	while(ss1 >> word)
		v1.push_back(word);
	
	// splitting string by space   
	istringstream ss2(str2);
	while(ss2 >> word)
		v2.push_back(word);
	
	vector<string> ans;
	
	unordered_map<string, int> mp;
	for(string str : v1)
		mp[str]++;
	for(string str : v2)
		mp[str]++;
	
	// if value is equal to 1
	// add the key to ans vector
	for(auto it : mp)
	{
		if(it.second == 1)
		ans.push_back(it.first);
	}
	
	return ans;
}



/** function display
 * @param, vector, denoting vector of strings
 * displays the contents of vector (strings) on the console
 */ 
void display(vector<string> v)
{
	for(string str : v)
		cout<<str<<" ";
	cout<<"\n";
}



// main function - driver code
int main()
{
    
	// TESTCASES
	
	vector<string> v;
	
	v = uncommonFromSentences("the quick", "brown fox");
	display(v);
	
	v = uncommonFromSentences("the tortoise beat the haire", "the tortoise lost to the haire");
	display(v);
	
	v = uncommonFromSentences("copper coffee pot", "hot coffee pot");
	display(v);
	
	return 0;
}
