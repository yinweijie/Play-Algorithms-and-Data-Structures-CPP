#include <queue>
#include <iostream>

using namespace std;

class MyStack {
private:
    queue<int>* m_qin;
    queue<int>* m_qout;
    int m_top;
public:
    /** Initialize your data structure here. */
    MyStack() {
        m_qin = new queue<int>();
        m_qout = new queue<int>();
    }
    ~MyStack()
    {
        delete m_qin;
        delete m_qout;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        m_qin->push(x);
        m_top = x;
    }
    
    void move()
    {
        int n = m_qin->size() - 1;
        for(int i = 0; i < n; i++)
        {
            int front = m_qin->front();
            m_qin->pop();
            m_qout->push(front);
            m_top = front;
        }
    }

    void swap()
    {
        queue<int>* tmp = m_qin;
        m_qin = m_qout;
        m_qout = tmp;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        move();

        int ret = m_qin->front();
        m_qin->pop();

        swap();

        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return m_top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (m_qin->size() + m_qout->size() == 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyStack st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();

    cout << st.empty() << endl;
    return 0;
}