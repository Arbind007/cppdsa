// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
using namespace std;

int method1(int arr[], int n)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum = sum + arr[k];
            }

            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum << endl;
    return 0;
}

int method2(int arr[], int n)
{
    int maxSum = INT_MIN;
    int currSum[n + 1];
    currSum[0] = 0;
    for (int i = 1; i < n; i++)
    {
        currSum[i] = currSum[i - 1] + arr[i - 1];
    }
    for (int i = 1; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum = currSum[i] - currSum[j];
            maxSum = max(sum, maxSum);
        }
    }
    cout << maxSum << endl;
    return 0;
}

int method3(int arr[], int n)
{
    int currentSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        if (currentSum < 0)
        {
            currentSum = 0;
        }
        maxSum = max(maxSum, currentSum);
    }
    cout << maxSum << endl;
    return 0;
}

int main()
{
    int arr[4] = {-1, 4, 7, 2};
    int n = 4;
}