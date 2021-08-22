/**
 * You are given two lists of integers and an integer representing a process id to kill. One of 
 * the lists represents a list of process ids and the other represents a list of each of the 
 * processes’ corresponding (by index) parent ids. When a process is killed, all of its children 
 * should also be killed. Return a list of all the process ids that are killed as a result of 
 * killing the requested process.
 */

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/**
 * @author keshav kabra
 * @since August 22, 2021
 */



/** function kill_process
 * @param pid: the process id
 * @param ppid: the parent process id
 * @param kill: a PID we want to kill
 * @return: a list of PIDs of processes that will be killed in the end
 */
vector<int> kill_process(vector<int> &pid, vector<int> &ppid, int kill) 
{
    
    /** Logic :
     * 
     * We store the processes to be killed in a queue and iterate on the queue till it is empty.
     * 
     * Hence, at the beginning, we push the 'kill' into queue and then start a loop which runs while queue is
     * non-empty.
     * At each iteration, the top of queue denotes a process to be killed, hence push it into answer vector and 
     * pop it out from the queue.
     * 
     * Now, we search for the popped element in the vector 'ppid' - since we have to kill all the processes 
     * whose parent was the popped element.
     * The index where we found popped element in 'ppid' vector, the corresponding process is at the same
     * index in 'pid' vector.
     * Thus, we push the approprite elements into the queue and continue the process.
     * 
     * At the end, return the answer vector
     * 
     */ 
    
    queue<int> q;
    vector<int> answ;

    q.push(kill);

    while(!q.empty())
    {
        int top = q.front();
        answ.push_back(top);
        q.pop();

        for(int i=0;i<ppid.size();i++)
        {
            if(ppid[i] == top) {
                q.push(pid[i]);
            }
        }
    }

    return answ;
}



/** function display_answer
 * @param vector, denoting the array
 * prints the given array on the console
 */ 
void display_answer(vector<int> v)
{
    for(int i : v)
        cout<<i<<" ";
    cout<<"\n";
}



// main function - driver code
int main()
{
	vector<int> pid, ppid;
	vector<int> ans;
	
	
	// TESTCASE - 1
	pid = {2, 4, 3, 7};
	ppid = {0, 2, 2, 3};
	ans = kill_process(pid, ppid, 3);
	display_answer(ans);
	
	
	// TESTCASE - 2
	pid = {2, 4, 3, 7};
	ppid = {0, 2, 2, 3};
	ans = kill_process(pid, ppid, 2);
	display_answer(ans);
	
	
	// TESTCASE - 3
	pid = {1, 2, 3};
	ppid = {0, 1, 1};
	ans = kill_process(pid, ppid, 2);
	display_answer(ans);
	
	
	return 0;
}
