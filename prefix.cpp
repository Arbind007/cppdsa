#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int prefix(string str)
{
    stack<int> st;
    for (int i = str.length() - 1; i >= 0; i--)
    {

        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push(str[i] - '0');
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            switch (str[i])
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            case '^':
                st.push(pow(a, b));
                break;
            }
        }
    }
    return st.top();
}

int postfix(string str)
{
    stack<int> st;
    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push(str[i] - '0');
        }
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            switch (str[i])
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            case '^':
                st.push(pow(a, b));
                break;
            }
        }
    }
    return st.top();
}

int main()
{

    cout << prefix("-+7*45+20") << endl;
    cout << postfix("46+2/5*7+") << endl;
}