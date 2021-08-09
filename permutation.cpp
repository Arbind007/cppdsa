#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> answer;

void permu(vector<int> &a, int idx)
{
    if (idx == a.size())
    {
        answer.push_back(a);
        return;
    }

    for (int i = idx; i < a.size(); i++)
    {
        swap(a[i], a[idx]);
        permu(a, idx + 1);
        swap(a[i], a[idx]);
    }

    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    permu(a, 0);
    for (auto v : answer)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
