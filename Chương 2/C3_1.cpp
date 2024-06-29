#include<iostream>
#include<vector>
using namespace std;
bool chuaxet[1001];
void DFS(int u, vector<int> adj[]){
    cout << u << " ";
    chuaxet[u] = false;
    for(int i=0;i<adj[u].size();++i){
        if(chuaxet[adj[u][i]] == true) DFS(adj[u][i],adj);
    }
}
int main(){
    for(int i=1;i<=1000;++i) chuaxet[i] = true;
    int n;cin >> n;
    vector<int> adj[1001];
    int a[n+1][n+1];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(a[i][j] == 1){
                adj[i].push_back(j);
            }
        }
    }
    DFS(1,adj);
}