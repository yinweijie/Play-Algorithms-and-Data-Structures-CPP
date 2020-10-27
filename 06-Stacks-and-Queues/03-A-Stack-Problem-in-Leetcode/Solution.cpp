#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(const char& c : s)
        {
            if(c == '[' || c == '(' || c == '{')
            {
                st.push(c);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }

                const char toChar = st.top();
                st.pop();

                if(c == ']' && toChar != '[')
                {
                    return false;
                }
                if(c == ')' && toChar != '(')
                {
                    return false;
                }
                if(c == '}' && toChar != '{')
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main()
{
    cout << Solution().isValid("()[]{}") << endl;
    cout << Solution().isValid("([)]") << endl;
    return 0;
}