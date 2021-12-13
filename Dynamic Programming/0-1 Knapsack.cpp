#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int val[N],wt[N];

int Knapsack(int n,int w){
    if(w <= 0 || n <= 0){
        return 0;
    }
    if(wt[n-1] > w){
        return Knapsack(n-1,w);
    }
    return max(Knapsack(n-1,w), Knapsack(n-1,w-wt[n-1]) + val[n-1]);
}
 
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> wt[i];
    }
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
    int w;
    cin >> w;
    cout << Knapsack(n,w) << endl;
    return 0;
}

// Memorisation

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+2;
int val[N],wt[N];
int dp[N][N];

int Knapsack(int n,int w){
    if(w <= 0 || n <= 0)
        return 0;
    if(dp[n][w] != -1)
       return dp[n][w];
    if(wt[n-1] > w)
        dp[n][w] = Knapsack(n-1,w);
    else
        dp[n][w] = max(Knapsack(n-1,w), Knapsack(n-1,w-wt[n-1]) + val[n-1]);
    return dp[n][w];
}
 
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = -1;
        }
    }
    for(int i=0;i<n;i++){
        cin >> wt[i];
    }
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
    int w;
    cin >> w;
    cout << Knapsack(n,w) << endl;
    return 0;
}

// 3
// 15 30 45
// 60 100 150
// 50