/**
 *  Amazon. 
 * Given N distinct rooms that are locked we want to know if you can unlock and visit every room. Each 
 * room has a list of keys in it that allows you to unlock and visit other rooms. We start with room 0 
 * being unlocked. 
 * Return whether or not we can visit every room.
 */

#include<iostream>
#include<vector>
#include<set>
using namespace std;


/**
 * @author keshav kabra
 * @since October 15, 2021
 */



/** function recur
 * @param set<int>, to store all rooms that can be visited
 * @param int, current room number
 * @param vector<vector<int>>, denoting the array of rooms with keys
 */ 
void recur(set<int> &st, int ind, vector<vector<int>> &rooms)
{
    for(int j=0;j<rooms[ind].size();j++)
    {
        if(rooms[ind][j] != -4)
            st.insert(rooms[ind][j]);
        rooms[ind][j] = -4;
    }
}



/** function canVisitAllRooms
 * @param vector<vector<int>>, denoting the array of rooms with keys
 * @param bool, whether we can visit all rooms or not
 */ 
bool canVisitAllRooms(vector<vector<int>>& rooms) 
{
    
    /** Logic :
     * 
     * Push all keys present in room-0 into the set. Now, each subsequent time, iterate over each key of set to 
     * know how many more rooms we can visit (via 'recur' function)
     * 
     */ 
    
    int len = rooms.size();
    
    set<int> st;
    for(int i=0;i<len;i++)
    {
        if(i != 0)
        {
            for(int j : st)
                recur(st, j, rooms);
        }
        
        else if(i == 0) 
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                st.insert(rooms[i][j]);
                rooms[i][j] = -4;
            }
        }
    }
    
    for(vector<int> v : rooms)
    {
        for(int i : v)
        {
            if(i != -4)
                return false;
        }
    }
    
    return st.size() == len-1;
    
}



// main function - driver code
int main()
{
	vector<vector<int>> rooms;
	
	
	// TESTCASES
	
	rooms = {{1}, {2}, {3}, {}};
	cout<<canVisitAllRooms(rooms)<<"\n";
	
	rooms = {{1, 2}, {2}, {0}, {}};
	cout<<canVisitAllRooms(rooms)<<"\n";
	
	rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
	cout<<canVisitAllRooms(rooms)<<"\n";
	
	return 0;
}
