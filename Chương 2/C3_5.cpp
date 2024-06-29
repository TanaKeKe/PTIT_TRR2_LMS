#include<iostream>
#include<cstring> 
#include<queue>
#include<vector> 
using namespace std;
 
 int n, a[1001][1001];
 bool visited[1001]={false};
 vector<int> df;
 vector<int> bf;
void dfs(int u,int t){
    df.push_back(u);
    visited[u]=1;
    if(u==t){
        cout<<"DFS path: ";
        for(int i=df.size()-1;i>=0;i--){
        cout<<df[i]<<" ";
    }
    cout<<endl;
    return;
}
    for(int v=1;v<=n;v++){
        if(a[u][v]==1&&visited[v]==0){
            dfs(v,t);
        }
    }
    if(df.back()!=t){
    df.pop_back();
 
    }
}
void bfs(int s,int t){
    queue<int> q;
    q.push(s);
    visited[s]=1;
    vector< vector<int> > path(n+1);
    path[s].push_back(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u==t){
            cout<<"BFS path: ";
            for(int i=path[u].size()-1;i>=0;i--){
            cout<<path[u][i]<<" ";
 
            }
            cout<<endl;
            return;
            }
            for(int v=1;v<=n;v++){
                if(a[u][v]==1&& visited[v]==0 ){
                    q.push(v);
                    visited[v]=1;
                    path[v]=path[u];
                    path[v].push_back(v);
                }
            }
        }
        cout<<"no path"<<endl;
        bf.clear();
    }
int main(){
    memset(visited,false,sizeof(visited));
    cin>>n;
    int s,t;
    cin>>s>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    dfs(s,t);
    memset(visited,false,sizeof(visited));
    bf.clear();
    bfs(s,t);
    return 0;
}