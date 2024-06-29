#include<iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
const int mod = 1e9+7;
vector<pair<int, int>> a[30];
int n, s;
void dijkstra(int v){
    if (s==v){
        cout << "K/c " << s << " -> " << s << " = 0;        " << s << " <- " << s << '\n';
        return;      
    }
    bool check[20] = {};
    vector<int> d(n+5, mod);
    int pre[30];
    d[s] = 0;
    pre[s] = s;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({s, 0});
    int mi = mod;
    while (!pq.empty()){
        pair<int, int> u = pq.top();
        pq.pop();
        if (u.first==v) mi = min(mi, u.second);
        // if (check[u.first]) continue;
        // check[u.first] = true;
        for (auto it:a[u.first]){
            if (d[it.first]>d[u.first]+it.second){
                d[it.first] = d[u.first] + it.second;
                pq.push({it.first, d[it.first]});
                pre[it.first] = u.first;
            }
        }
    }
    cout << "K/c " << s << " -> " << v << " = "; 
    if (mi == mod){
        cout << "INF;\n"; 
    }
    else{
        cout << d[v] << ";        ";
        vector<int> ans;
        while (s!=v){
            ans.push_back(v);
            v = pre[v];
        }
        for (auto it:ans){
            cout << it << " <- ";
        }
        cout << s << '\n';
    }
}
int main(){
    // #ifndef ONLINE_JUGDE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    cin >> n >> s;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int x;
            cin >> x;
            if (x) a[i].push_back({j, x});
        }
    }
    for (int i=1;i<=n;i++){
        dijkstra(i);
    }
}