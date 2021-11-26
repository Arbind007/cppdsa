#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main()
{
    int k;
    cin >> k;

    vector<vector<int> //
           >
        a(k);

    for (int i = 0; i < k; i++)
    {
        int size;
        cin >> size;

        a[i] = vector<int>(size);
        for (int j = 0; j < size; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<int> idx(k, 0);

    priority_queue<pii, vector<pii>, greater<pii> //
                   >
        pq;
    for (int i = 0; i < k; i++)
    {
        // pq.push(a[i][0], i);
    }

    vector<int> ans;

    while (!pq.empty())
    {
        // vector<pair<int, int>
        //        //
        //        >
        //     x = pq.top();
        // pq.pop();
    }

    return 0;
}