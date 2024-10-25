#include <bits/stdc++.h>

using namespace std;

void DFS(int v,vector<vector<int>>& dp, vector<vector<int>>& adj, 
        vector<vector<int>>& lr, int p = -1){
            dp[v][0] = dp[v][1] = 0;
    for(int u : adj[v]){
        if(u==p) continue;
        DFS(u,dp,adj,lr,v);
        dp[v][0] += max(abs(lr[v][0] - lr[u][0]) + dp[u][0], abs(lr[v][0] - lr[u][1]) + dp[u][1]);
        dp[v][1] += max(abs(lr[v][1] - lr[u][0]) + dp[u][1], abs(lr[v][1] - lr[u][1]) + dp[u][1]);
    }
}

void solve(vector<vector<int>>& adj, vector<vector<int>>& lr){
    int n = lr.size();
    vector<vector<int>> dp(n,vector<int>(2,0));
    DFS(0,dp,adj,lr);
    
    cout<<max(dp[0][1],dp[0][0])<<endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> lr(n,vector<int>(2));

        for(int i=0; i<n; i++){
            cin>>lr[i][0];
            cin>>lr[i][1];
        }
        vector<vector<int>> adj(n);

        for(int i = 0; i<(n-1); i++){
            int a,b;
            cin>>a; cin>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }

        solve(adj, lr);

    }

    return 0;
}
