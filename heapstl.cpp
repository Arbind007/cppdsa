#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>
                   //
                   >
        pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    priority_queue<int, vector<int>, greater<int>
                   //
                   >
        pq2;
    pq2.push(2);
    pq2.push(3);
    pq2.push(1);
    cout << pq2.top() << endl;
    pq2.pop();
    cout << pq2.top() << endl;
    return 0;
}

//push O(logn)
//pop O(logn)
//top O(1)
//size O(1)