/**
 * Microsoft
 * Design a class, MovingAverage, which contains a method, 
 * next that is responsible for returning the moving average from a stream of integers.
 * A moving average is the average of a subset of data at a given point in time.
 * Define a constructor as : MovingAverage movingAverage = new MovingAverage(capacity);
 */

#include<iostream>
#include<vector>
using namespace std;

/**
 * @author keshav kabra
 * @since June 13, 2021
 */


// class MovingAverage 
class MovingAverage 
{
    
    // private member variables
	private :
		int window_size;
		vector<int> v;
		int sum;
		
	public :
		
		// constructor
		MovingAverage(int sz)
		{
			this->window_size = sz;
			this->v.clear();
			this->sum = 0;
		}
		
		
		/** method next
		 * @param int, denoting the value
		 * @return double, denoting average of window
		 */ 
		double next(int val)
		{
		    
		    /** Logic :
		     * First add the passed value to 'sum' (variable is holding sum of this window)
		     * Now, push the 'val' into vector
		     * If the size of vector is greater than window_size, it means we need to pop
		     * out the top of vector and hence, we subtract the top of vector from 'sum' and
		     * pop the top of the vector.
		     * 
		     * At the end, simply return the average by dividing 'sum' with vector-size
		     * 
		     * Time complexity : O(1)  -- Just push, pop and divide operations performed
		     * Space complexity : O(N) -- N is the size of the window (the max size of vector possible)
		     * 
		     */ 
		    
			this->sum += val;
			this->v.push_back(val);
			if(this->v.size() > this->window_size) 
			{
				this->sum -= this->v.front();
				this->v.erase(this->v.begin());
			}
			
			return this->sum/ (this->v.size() * 1.0);
		}
	
};



// main function - driver code
int main()
{
	
	MovingAverage* obj = new MovingAverage(3);
	
	// TESTCASES
	
	cout<<obj->next(3)<<"\n";
	cout<<obj->next(5)<<"\n";
	cout<<obj->next(7)<<"\n";
	cout<<obj->next(6)<<"\n";
	
	
	return 0;
}
