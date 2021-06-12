/**
 * Google
 * Create a class CallCounter that tracks the number of calls a client has made within the last 3 seconds.
 * Your class should contain one method, ping(int t) that receives the current timestamp (in milliseconds) of
 * a new call being made and returns the number of calls made within the last 3 seconds.
 * You may assume that the time associated with each subsequent call to ping is strictly increasing & positive.
 */

#include<iostream>
#include<deque>
using namespace std;

/**
 * @author keshav kabra
 * @since June 12, 2021
 */



// class CallCounter
class CallCounter 
{
    
    // private member variables
    private:
        deque<int> dq;

    public:
    
        // constructor
        CallCounter() 
        {
            dq.clear();
        }


        /** method ping
         * @param int, denoting the time in milliseconds
         * @return int, denoting the number of calls made within 3000 ms
         */ 
        int ping(int t) 
        {
            
            /** Logic :
             * Push each new request at the last of the dequeue
             * 
             * If dequeue was empty, it is the first request, hence return 1.
             * 
             * Else, check if the difference in front of dequeue (denoting oldest 
             * request) and current time is greater then 3000, if it is so, it means
             * that the front request was made before 3 seconds, hence it should not
             * be counted and thus, we pop it out. 
             * 
             * Do the same thing till either dequeue becomes empty or difference in
             * front and current time becomes <= 3000.
             * Push current request into dequeue and return its size as answer.
             * 
             * Time complexity : O(1)  --  At worst case we need to pop out all 3000 records
             * Space complexity : O(1) -- At worst we need deque of size 3000
             */ 
            
            if(dq.size() == 0) 
            {
                dq.push_back(t);
                return 1;
            }
            else
            {
                while(dq.size()>0 && t-dq.front() > 3000)
                    dq.pop_front();
                dq.push_back(t);
                return dq.size();
            }
        }
        
};



// main function - driver code
int main()
{
    
	CallCounter obj;
	
	// TESTCASES
	
	cout<<obj.ping(1)<<"\n";
	cout<<obj.ping(300)<<"\n";
	cout<<obj.ping(3000)<<"\n";
	cout<<obj.ping(3002)<<"\n";
	cout<<obj.ping(7000)<<"\n";
	
	return 0;
}
