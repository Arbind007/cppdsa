#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        int count = 1;
        int sum = 0;
        int a;
        cin >> a;
        while (a > 0)
        {
            if (a % 10 > 0)
            {
                v.push_back((a % 10) * count);
                sum++;
            }
            a /= 10;
            count *= 10;
        }
        cout << sum << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    return 0;
}