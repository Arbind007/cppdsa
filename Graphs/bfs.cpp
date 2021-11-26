#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int vis[N];
vector <int> adj[N];

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
    
    queue <int> q;
    q.push(1);
    vis[1] = 1;
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        
        vector <int> ::iterator it;
        for(it = adj[temp].begin() ; it != adj[temp].end() ; it++){
            if(!vis[*it]){
                q.push(*it);
                vis[*it] = 1;
            }
        }
    }
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