#include <bits/stdc++.h>
using namespace std;

bool isPow(int n)
{
    return (n && !(n & (n - 1)));
}

int main()
{
    cout << isPow(16);
    return 0;
}