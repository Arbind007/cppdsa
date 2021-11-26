#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int vis[N];
vector <int> adj[N];

void dfs(int node){
    //preorder
    vis[node] = 1;
    cout << node << " ";
    
    //inorder
    vector <int> ::iterator it;
    for(it=adj[node].begin();it != adj[node].end(); it++){
        if(!vis[*it]){
            dfs(*it);
        }
    }
    //postorder
}

int main(){
    for(int i=0;i<N;i++){
        vis[i] = 0;
    }
    
    int n,m,x,y;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
    return 0;
}

// 7 7
// 1 2 
// 1 3
// 2 4
// 2 5
// 2 6
// 2 7 
// 7 3