#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    int n;cin >> n;
    int start;cin >> start;
    int a[n+1][n+1];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cin >> a[i][j];
    }
    vector<int> adj[1001];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(a[i][j] == 1){
                adj[i].push_back(j);
            }
        }
    }
    // for(auto x : adj[4]) cout << x << " ";
    // cout << "\n";
    //cout << start << " ";
    stack<int> st;
    st.push(start);
    vector<int> res;
    while(!st.empty()){
        if(adj[st.top()].size() != 0){
        	int s = st.top();
            int k = adj[s][0];
            adj[s].erase(adj[s].begin());
            vector<int>::iterator it = lower_bound(adj[k].begin(),adj[k].end(),s);
            adj[k].erase(it);
            st.push(k);
        }
        else{
            res.push_back(st.top());
            st.pop();
        }
    }
    for(int i = res.size()-1;i>=0;--i) cout << res[i] << " ";
}