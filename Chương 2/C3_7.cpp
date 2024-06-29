#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
int n,a[1001][1001];
vector<int> adj[1001];
int visited[1001];
void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int i=0;i<adj[s].size();++i){
            if(visited[adj[s][i]] == 0){
                q.push(adj[s][i]);
                visited[adj[s][i]] = 1;
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) adj[j].clear();
        memset(visited,0,sizeof(visited));
        for(int j=1;j<=n;++j){
            for(int k = 1;k<=n;++k){
                if(j!=i){
                    if(k!=i){
                        if(a[j][k]) adj[j].push_back(k);
                    }
                }
            }
        }
        int cnt = 0;
        for(int j = 1;j<=n;++j){
            if(visited[j] == 0 && j!=i){
                ++cnt;
                BFS(j);
            }
        }
        if(cnt > 1) cout << i << " ";
    }
}