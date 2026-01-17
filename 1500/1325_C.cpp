#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> edges(n-1);

    vector<vector<pair<int,int>>> adjList(n+1);

    for(int i = 0; i<=(n-2); i++){
        int u, v;
        cin>>u>>v;
        edges[i] = {u,v};
        adjList[u].push_back({v,i});
        adjList[v].push_back({u,i});
    }

    vector<int> sel_edges(n-1,-1);
    int count = 0;
    for(int i = 1; i<=n; i++){
        if(adjList[i].size()==1){
            if(sel_edges[adjList[i][0].second]==-1){
                sel_edges[adjList[i][0].second] = count;
                count++;
            }
        }
    }

    // vector<int> ans(n-1);
    for(int i = 0; i<=(n-2); i++){
       if(sel_edges[i]==-1){
            sel_edges[i] = count;
            count++;
       } 
    }

    for(int i = 0; i<=(n-2); i++){
        cout<<sel_edges[i]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--){
        solve();
    }
}