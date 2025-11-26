#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1e5;
int inTime[MAXN+1], outTime[MAXN+1];
void dfs(int u, int par, vector<vector<int>>& edges, int& timer){
    inTime[u]= ++timer;
    for(int c : edges[u]){
        if(par!=c){
            dfs(c,u,edges,timer);
        }
    }
    outTime[u] = timer;
}

void solve(){
    int n;
    cin>>n;
    vector<int> val(n);
    map<int,int> mp;
    for(int i=0; i<n; i++){
        cin>>val[i];
        mp[val[i]]++;
    }
    vector<vector<int>> edges(n);
    for(int i=0; i<(n-1); i++){
        int u, v; cin>>u>>v;
        edges[u-1].push_back(v-1);
    }
    int prefix_count = 0;
    unordered_map<int, int> val_greater_than;
    for(auto it: mp){
        prefix_count+=it.second;
        val_greater_than[it.first] = n-prefix_count;
    }
    // euler tour and fenwick tree

    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
