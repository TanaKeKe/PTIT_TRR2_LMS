#include<iostream>
#include<vector>
using namespace std;
vector<int> adj[1001];
int n;
int daxet[1001];
int res[1001];

void HMT(int k){
	for(int i =0;i< adj[res[k-1]].size();++i){
		if((k==n+1)&&(res[1] == adj[res[k-1]][i])){
			for(int j =1;j<=n;++j) cout << res[j] << " ";
			cout << res[1];
			cout << endl;
		}
		else if(daxet[adj[res[k-1]][i]] == 0){
			res[k] = adj[res[k-1]][i];
			daxet[adj[res[k-1]][i]] = 1;
			HMT(k+1);
			daxet[adj[res[k-1]][i]] = 0;
		}
	}
}
int main(){
    cin >> n;
    int k;cin >> k;
    int a[n+1][n+1];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin >> a[i][j];
        }
    }
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(a[i][j]) adj[i].push_back(j);
        }
    }
    res[1] = k;
    daxet[k] = 1;
    HMT(2);
    
}