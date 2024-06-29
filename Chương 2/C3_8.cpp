#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n,a[1001][1001];
vector<int> adj[1001];
int visited[1001];
void BFS(int u){
    visited[u] = 1;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int i=0;i<adj[s].size();++i){
            if(visited[adj[s][i]] == 0){
                q.push(adj[s][i]);
                visited[adj[s][i]] =1;
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) if(a[i][j]) adj[i].push_back(j);
    }
    
    for(int i=1;i<=n;++i){
        int k = adj[i].size();
        for(int j = 0;j<k;++j){
            int l = adj[i][0];
            auto it = adj[i].begin();
            adj[i].erase(it);
            // for(auto x : adj[i]) cout << x << " ";
            // cout << "\n";
            int cnt =0;
            memset(visited,0,sizeof(visited));
            for(int z =1;z<=n;++z){
                if(visited[z] ==0 ){
                    ++cnt;
                    BFS(z);
                }
            }
            if(cnt > 1) cout << i << " " << l << "\n";
            adj[i].push_back(l);
            // for(auto x : adj[i]) cout << x << " ";
            // cout << "\n";
        }
    }
}