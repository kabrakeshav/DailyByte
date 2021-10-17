/**
 * Google
 * Email addresses are made up of local and domain names. For example in kevin@dailybyte.com, kevin 
 * is the local name and dailybye.com is the domain name. 
 * 
 * Email addresses may also contain '+' or '.' characters besides lowercase letters. If there is a '.' in 
 * the local name of the email address it is ignored. 
 * Everything after a '+' in the local name is also ignored. 
 * 
 * For example ke.vin+abc@dailybyte.com is equivalent to kevin@dailybyte.com 
 * Given a list of email addresses, find the number of unique addresses.
 */

#include<iostream>
#include<vector>
#include<set>
using namespace std;


/**
 * @author keshav kabra
 * @since October 16, 2021
 */



/** function split_email
 * @param string, email address
 * @param string, to store first part of email address (ahead of '@')
 * @param string, to store second part of email address (after of '@')
 */ 
void split_email(string em, string& first, string& sec)
{
    
    bool flag = true;
    for(char ch : em)
    {
        if(ch == '@') {
            flag = false;
            continue;
        }
        if(flag == true)
            first += ch;
        else
            sec += ch;
    }
}



/** function split_plus_dot
 * @param string, the first part (ahead of '@') in the email address
 * 
 * The function makes the string such that we have ignored Everything after '+' symbol and also
 * ignored '.' characters
 * 
 */ 
void split_plus_dot(string &str)
{
    string res = "";
    for(char ch : str)
    {
        if(ch == '+')
            break;
        if(ch == '.')
            continue;
        res += ch;
    }
    
    str = res;
}



/** function numUniqueEmails
 * @param vector<string>, array of email addresses
 * @return int, number of unique email addresses
 */ 
int numUniqueEmails(vector<string>& emails) 
{
    set<string> st;
    
    for(string em : emails)
    {
        string fir="", sec="";
        
        split_email(em, fir, sec);
        split_plus_dot(fir);
        
        string res = fir + '@' + sec;
        st.insert(res);
    }
    
    return st.size();
}



// main function - driver code
int main()
{
	vector<string> v;
	
	
	// TESTCASES
	
	v = {"test.email+kevin@dailybyte.com", "test.e.mail+john.smith@dailybyte.com", "testemail+david@daily.byte.com"};
	cout<<numUniqueEmails(v)<<"\n";
	
	v = {"a@leetcode.com", "b@leetcode.com", "c@leetcode.com"};
	cout<<numUniqueEmails(v)<<"\n";
	
	return 0;
}
