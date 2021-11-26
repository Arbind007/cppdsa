#include <bits/stdc++.h>
using namespace std;

const int N =  1e5 + 2;

vector <int> adj[N] ;

int main(){
    int n,m;
    
    cin >> n >> m;
    // vector<vector<int>> adjm(n+1,vector<int>(n+1,0));
    
    // for(int i=0;i<m;i++){
    //     int x,y;
    //     cin >> x >> y;
        
    //     adjm[x][y] = 1;
    //     adjm[y][x] = 1;
    //     // cout << adjm[x][y] << " " << adjm[y][x] << endl;
    // }
    
    // for(auto it : adjm){
    //     for(auto i : it){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    
    // for(int i=1;i<n+1;i++){
    //     for(int j=1;j<n+1;j++){
    //         cout << adjm[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for(int i=1;i<n+1;i++){
        cout << i << "->";
        vector <int> ::iterator it;
        for(it = adj[i].begin(); it < adj[i].end(); it++){
            cout << *it << " ";
        }
        cout << endl;
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
// 3 7