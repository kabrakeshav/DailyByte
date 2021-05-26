/**
 * Amazon
 * Given a string representing your stones and another string representing a list of jewels, 
 * return the number of stones that you have that are also jewels.
 */

#include<iostream>
#include<unordered_map>
using namespace std;

/**
 * @author keshav kabra
 * @since May 26, 2021
 *
 */



/** 
 * method numJewelsInStones
 * @param jewels, string denoting jewels
 * @param stones, string denoting stones
 * @return int, number of stones that are also jewels
 */
int numJewelsInStones(string jewels, string stones)
{
    
    /** Logic :
     * store the frequency of each character of string stones into a map
     * Now, iterate through string jewels and add frequency of the character 
     * if it is also present in string jewels
     */ 
     
    unordered_map<char,int> mp;
    for(char ch : stones)
        mp[ch]++;
    
    int ans = 0;
    for(char ch : jewels)
    {
        if(mp.find(ch) != mp.end())
            ans += mp[ch];
    }
    return ans;
}

int main()
{
    
    // TESTCASES
    cout<<numJewelsInStones("abc", "ac")<<"\n";
    cout<<numJewelsInStones("Af", "AaaddfFf")<<"\n";
    cout<<numJewelsInStones("AYOPD", "ayopd")<<"\n";
    
    return 0;
}
