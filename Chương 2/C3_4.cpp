#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool chuaxet[1001];
vector<int> adj[1001];
int a[1001][1001];
void DFS(int u){
    chuaxet[u] = false;
    stack<int> st;
    st.push(u);
    while(!st.empty()){
        int k = st.top();
        st.pop();
        for(int i=0;i<adj[k].size();++i){
            if(chuaxet[adj[k][i]] == true){
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
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(a[i][j]) adj[i].push_back(j);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;++i){
        if(chuaxet[i] == true){
            ++ans;
            DFS(i);
        }
    }
    cout << ans;
}