/**
 * Design a class to implement a stack using only a single queue. 
 * Your class, StackUsingSingleQueue, should support the following stack methods: 
 * push() (adding an item), pop() (removing an item), peek() 
 * (returning the top value without removing it), and empty() 
 * (whether or not the stack is empty).
 */
 
#include<iostream>
#include<queue>
using namespace std;

/**
 * @author keshav kabra
 * @since June 14, 2021
 */


//class QueueStack
class QueueStack 
{
    
    /**
     * Time complexity : O(N)  --  push method takes O(N) time, others take O(1) time
     * Space complexity : O(N) --  we have to maintain a queue for implementing stack
     */ 
    
    
    // private member variable - a queue
	private :
		queue<int> q;
	
	public :
		
		
		/** method push
		 * @param int, the number to be pushed into stack
		 * 
		 * We will first push the current value into the queue and
		 * then pop all the values already present in the queue and
		 * add them after the newly added element.
		 * Hence, affectively we have implemented 'First In'
		 */ 
		void push(int num)
		{
			int sz = q.size();
			q.push(num);
			
			for(int i=0;i<sz;i++)
			{
				q.push(q.front());
				q.pop();
			}
		}
		
		
		/** method pop
		 * displays the top of stack and pops it out
		 */ 
		void pop()
		{
			if(q.size() == 0)
				cout<<"No elements in stack";
			else
			{
				int ele = q.front();
				q.pop();
				cout<<"Popped element: "<<ele<<"\n";
			}
		}
		
		
		/** method peek
		 * @return int, denoting the top of stack
		 * 
		 * returns top of stack without removing it
		 */ 
		int peek()
		{
			if(q.size() == 0)
				return -1;
			return q.front();
		}
		
		
		/** method empty
		 * @return bool, denting if the stack is empty or not
		 */ 
		bool empty()
		{
			return q.size() == 0;
		}
		
};



// main function - driver code
int main()
{
	
	// creating object of QueueStack class
	QueueStack* obj = new QueueStack();
	
	
	// TESTCASES
	obj->push(1);
	obj->push(2);
	cout<<"Top: "<<obj->peek()<<"\n";
	obj->pop();
	cout<<"Top: "<<obj->peek()<<"\n";
	obj->pop();
	cout<<"Top: "<<obj->peek()<<"\n";
	obj->pop();
	
	
	return 0;
}
