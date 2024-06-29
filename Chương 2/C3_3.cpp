#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool chuaxet[1001];
void BFS(int u,vector<int> adj[]){
    chuaxet[u] = false;
    cout << u << " ";
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for(int i=0;i<adj[k].size();++i){
            if(chuaxet[adj[k][i]] == true){
                chuaxet[adj[k][i]] = false;
                cout << adj[k][i] << " ";
                q.push(adj[k][i]);
            }
        }
    }
}
int main(){
    for(int i=1;i<=1000;++i) chuaxet[i] = true;
    int n;cin >> n;
    int a[n+1][n+1];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }
    
    vector<int> adj[1001];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(a[i][j]) adj[i].push_back(j);
        }
    }
    
    BFS(1,adj);
}