/** Given a positive integer N, return whether or not it has alternating bit values.
 */

#include<iostream>
#include<vector>
using namespace std;


/**
 * @author keshav kabra
 * @since September 9, 2021
 */
 


/** function to_binary
 * @param int, denoting the number in decimal format
 * @param string, to store the binary form of 'num'
 * converts the given integer to its equivalent binary string
 */ 
void to_binary(int num, string &str)
{
	if(num != 0) {
		str += to_string(num%2);
		to_binary(num/2, str);
	}
}



/** function hasAlternatingBits
 * @param string, denoting the string in binary format
 * @return bool, whether string is made up of alternating bits values
 */ 
bool hasAlternatingBits(string str)
{
	if(str.length() == 0)
		return true;
		
	char ch = str[0];
	
	for(int i=1;i<str.length();i++)
	{
		if(ch=='0' && str[i]!='1')
			return false;
		if(ch=='1' && str[i]!='0')
			return false;
		ch = str[i];
	}
	return true;
}



// main function - driver code
int main()
{
	int num;
	
	
	// TESTCASE - 1
	num = 5;
	string bin = "";
	to_binary(num, bin);
	cout<<hasAlternatingBits(bin)<<"\n";
	
	
	// TESTCASE - 2
	num = 8;
	bin = "";
	to_binary(num, bin);
	cout<<hasAlternatingBits(bin)<<"\n";
	
	
	// TESTCASE - 3
	num = 10;
	bin = "";
	to_binary(num, bin);
	cout<<hasAlternatingBits(bin)<<"\n";
	
	
	// TESTCASE - 4
	num = 11;
	bin = "";
	to_binary(num, bin);
	cout<<hasAlternatingBits(bin)<<"\n";
	
	return 0;
}
