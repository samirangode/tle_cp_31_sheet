#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> vis(n+1, false);
    vector<int> ans;
    ans.push_back(1);
    vis[1] = true;

    for(auto child : adj[1]) pq.push(child);

    while(!pq.empty()){
        int node = pq.top(); pq.pop();
        if(!vis[node]){
            vis[node] = true;
            ans.push_back(node);
            for(auto child : adj[node]){
                if(!vis[child]){
                    pq.push(child);
                }
            }
        }
    }

    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}