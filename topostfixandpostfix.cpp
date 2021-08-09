#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int prec(char a)
{
    if (a == '^')
    {
        return 3;
    }
    else if (a == '*' || a == '/')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string to_postfix(string str)
{
    string st;
    stack<char> ch;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
        {
            st += str[i];
        }
        else if (str[i] == '(')
        {
            ch.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (!ch.empty() && ch.top() != '(')
            {
                st += ch.top();
                ch.pop();
            }
            if (!ch.empty())
            {
                ch.pop();
            }
        }
        else
        {
            while (!ch.empty() && prec(ch.top()) > prec(str[i]))
            {
                st += ch.top();
                ch.pop();
            }
            ch.push(str[i]);
        }
    }
    while (!ch.empty())
    {
        st += ch.top();
        ch.pop();
    }

    return st;
}

string to_prefix(string str)
{
    reverse(str.begin(), str.end());
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            str[i] = ')';
        }
        else if (str[i] == ')')
        {
            str[i] = '(';
        }
    }
    string st = to_prefix(str);
    reverse(st.begin(), st.end());
    return st;
}

int main()
{
    cout << to_postfix("(a-b/c)*(a/k-l)") << endl;
    // cout << to_fix("(a-b/c)*(a/k-l)") << endl;
}
