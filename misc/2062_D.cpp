#include <bits/stdc++.h>

using namespace std;


void dfs(int i, int par, 
        vector<long long>& a, vector<vector<int>>& adj,
        vector<pair<long long , long long>>& lr,
        long long& ans){

    long long maxC = lr[i].first;
    for(int c : adj[i]){
        if(c!=par){
            dfs(c,i,a,adj,lr,ans);
            maxC = max(maxC,a[c]);
        }
    }
    a[i] = min(lr[i].second, maxC);
    for(int c : adj[i]){
        if(c!=par){
            ans += max(a[c]-a[i],0ll);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    vector<pair<long long ,long long>> lr(n);
    for(int i=0; i<n; i++){
        int l,r;
        cin>>l>>r;
        lr[i].first = l;
        lr[i].second = r;
    }
    vector<vector<int>> adj(n);
    vector<long long> a(n);
    for(int i = 0; i<(n-1);i++){
        int u, v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    long long ans = 0;
    dfs(0,-1,a,adj,lr,ans);
    ans+=a[0];
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
