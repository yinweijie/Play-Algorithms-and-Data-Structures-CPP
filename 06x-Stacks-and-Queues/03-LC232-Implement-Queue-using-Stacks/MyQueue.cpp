#include <stack>
#include <iostream>

using namespace std;

class MyQueue {
private:
    stack<int> m_st_in;
    stack<int> m_st_out;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        m_st_in.push(x);
    }

    void move()
    {
        if(m_st_out.empty())
        {
            while(!m_st_in.empty())
            {
                int topE = m_st_in.top();
                m_st_in.pop();
                m_st_out.push(topE);
            }
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        move();

        int ret = m_st_out.top();
        m_st_out.pop();
        
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        move();

        return m_st_out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (m_st_in.size() + m_st_out.size() == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyQueue myQueue;

    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue.peek() << endl; // return 1
    cout << myQueue.pop() << endl; // return 1, queue is [2]
    cout << myQueue.empty() << endl; // return false

    return 0;
}