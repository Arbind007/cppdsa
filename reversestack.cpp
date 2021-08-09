#include <iostream>
#include <stack>
using namespace std;

void reverseStr(string str)
{
    stack<string> st;

    for (int i = 0; i < str.length(); i++)
    {
        string word = "";
        while (str[i] != ' ' && str.length() > i)
        {
            word += str[i];
            i++;
        }
        st.push(word);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void insertAtBottom(stack<int> &st, int element)
{
    if (st.empty())
    {
        st.push(element);
        return;
    }

    int ele = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(ele);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int element = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, element);
}

int main()
{
    // string str = "Hello how are you?";
    // reverseStr(str);
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverseStack(st);
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}