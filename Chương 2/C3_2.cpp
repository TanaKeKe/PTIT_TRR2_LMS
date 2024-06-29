#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool chuaxet[1001];
void DFS(int u,vector<int> adj[]){
    chuaxet[u] = false;
    stack<int> st;
    st.push(u);
    cout << u << " ";
    while(!st.empty()){
        int k = st.top();
        st.pop();
        for(int i=0;i<adj[k].size();++i){
            if(chuaxet[adj[k][i]] == true){
                cout << adj[k][i] << " ";
                chuaxet[adj[k][i]] = false;
                st.push(k);
                st.push(adj[k][i]);
                break;
            }
        }
    }
}
int main(){
    for(int i=1;i<=1000;++i) chuaxet[i] = true;
    int n;cin >> n;
    int a[n+1][n+1];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin >> a[i][j];
        }
    }
    vector<int> adj[1001];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(a[i][j]){
                adj[i].push_back(j);
            }
        }
    }
    DFS(1,adj);
    
}