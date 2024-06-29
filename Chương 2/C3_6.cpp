#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n,visited[1001],a[100][100];
vector<int> adj[1001];

void DFS(int u){
    visited[u] = 1;
    for(int i = 0;i<adj[u].size();++i){
        if(visited[i] == 0) DFS(i);
    }
}
int main(){
    cin >> n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) {
            if(a[i]) adj[i].push_back(j);
        }
    }
    
    for(int j =1;j<=n;++j){
        memset(visited,0,sizeof(visited));
        DFS(j);
        for(int i=1;i<=n;++i){
            if(visited[i] == 0){
                cout << "not strongly connected";
                return 0;
            }
        }
    }
    cout << "strongly connected";
}