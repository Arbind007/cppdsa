#include <iostream>
using namespace std;

int pairsum(int arr[], int n, int key)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i] + arr[j] == key)
            {
                cout << i << " " << j << endl;
                return true;
            }
        }
    }
    return false;
}
int pairsum2(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        if (arr[low] + arr[high] == key)
        {
            cout << low << " " << high << endl;
            return true;
        }
        else if (arr[low] + arr[high] > key)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    cout << pairsum(arr, n, key) << endl;
    return 0;
}