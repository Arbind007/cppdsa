//using recursion

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
vector <int> a;
int solve(int i,int j){
    if(i == j){
        return a[i];
    }
    if(i > j){
        return 0;
    }
    int l = a[i] + min(solve(i+2,j),solve(i+1,j-1));
    int r = a[j] + min(solve(i,j-2),solve(i+1,j-1));
    return max(l,r);
}

int main(){
    int n;
    cin >> n;
    a = vector <int> (n);
    for(auto &i : a){
        cin >> i;
    }
    cout << solve(0,n-1);
    return 0;
}

//using memorization

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
vector <int> a;
int dp[100][100];
int solve(int i,int j){
    if(i == j){
        return a[i];
    }
    if(i > j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    } 
    int l = a[i] + min(solve(i+2,j),solve(i+1,j-1));
    int r = a[j] + min(solve(i,j-2),solve(i+1,j-1));
    return dp[i][j] = max(l,r);
}

int main(){
    memset(dp,-1,sizeof dp);
    int n;
    cin >> n;
    a = vector <int> (n);
    for(auto &i : a){
        cin >> i;
    }
    cout << solve(0,n-1);
    return 0;
}


// 4
// 1 2 3 4
