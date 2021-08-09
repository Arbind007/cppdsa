#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	const int N = 1e6 + 2;
	int tes[N];
	int minind = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		tes[i] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		if (tes[arr[i]] != -1)
		{
			minind = min(minind, tes[arr[i]]);
		}
		else
		{
			tes[arr[i]] = i;
		}
	}
	if (minind == INT_MAX)
	{
		std::cout << "-1" << std::endl;
	}
	else
	{
		cout << minind + 1 << endl;
	}
}