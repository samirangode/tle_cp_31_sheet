#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>> adj;
// vector<int> vis;
vector<int> sz;
void dfs(int u, int par){
    sz[u] = 1;
    for(int v : adj[u]){
        if (v==par) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}


void solve(){
    int n;
    cin>>n;
    
    adj.assign(n+1,{});
    
    for(int i = 1; i<=(n-1); i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n&1){
        cout<<"-1\n";
        return;
    }
    sz.assign(n+1,0);
    
    dfs(1, -1);
    int ans = 0;

    for(int i = 2; i<=n; i++){
        if(!(sz[i]&1)) ans+=1;
    }

    cout<<ans<<endl;

}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}