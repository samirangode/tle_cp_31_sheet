#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;

    vector<int> w(n+1);
    for(int i = 1; i<=n; i++) cin>>w[i];

    vector<vector<int>> adj(n+1);
    for(int i = 1; i<=(n-1); i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vec;
    int val = 0;
    for(int i = 1; i<=n; i++){
        val+=w[i];
        int sz = adj[i].size();
        for(int j = 0; j<sz-1; j++) vec.push_back(w[i]);
    }

    sort(vec.rbegin(), vec.rend());

    cout<<val<<" ";
    for(const auto &x : vec){
        val+=x;
        cout<<val<<' ';
    }
    cout<<'\n';


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
