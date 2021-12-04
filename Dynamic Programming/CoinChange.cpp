//recursion
#include <bits/stdc++.h>
using namespace std;

int count(int S[], int m, int n)
{
	if (n == 0)
		return 1;
	
	if (n < 0)
		return 0;

	if (m <= 0 && n >= 1)
		return 0;
		
	return count(S, m - 1, n) +	count(S, m, n - S[m - 1]);
}

int main()
{
	int m;
	cin >> m;
	int arr[m];
    for(int i=0;i<m;i++){
        cin >> arr[i];
    }
	int k;
	cin >> k;
	cout << count(arr, m, k);
	
	return 0;
}

//memorisation
#include <bits/stdc++.h>
using namespace std;

int coinchange(vector<int>& a, int v, int n,vector<vector<int> >& dp)
{
    if (v == 0)
        return dp[n][v] = 1;
    if (n == 0)
        return 0;
    if (dp[n][v] != -1)
        return dp[n][v];
    if (a[n - 1] <= v) 
        return dp[n][v] = coinchange(a, v - a[n - 1], n, dp)+ coinchange(a, v, n - 1, dp);
    else 
        return dp[n][v] = coinchange(a, v, n - 1, dp);
}

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int v;
    cin >> v;
    vector<vector<int> > dp(n + 1,vector<int>(v + 1, -1));
    cout << coinchange(a, v, n, dp) << endl;
    return 0;
}

//tabulation
#include <bits/stdc++.h>
using namespace std;

int count(int S[], int m, int n)
{
	 int table[n+1];  
	 for(int i=0;i<=n;i++)
	     table[i] = 0;
	 table[0] = 1; 
	 for(int i=0; i<m; i++)         
        for(int j=S[i]; j<=n; j++)         
            table[j] += table[j-S[i]];
     return table[n];
}

int main()
{
	int m;
	cin >> m;
	int arr[m];
    for(int i=0;i<m;i++){
        cin >> arr[i];
    }
	int k;
	cin >> k;
	cout << count(arr, m, k);
	
	return 0;
}


// 3
// 1 2 3
// 4