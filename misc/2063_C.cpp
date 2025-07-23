#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<unordered_set<int>> adj(n);
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i<(n-1); i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].insert(v-1);
        adj[v-1].insert(u-1);
    }
    for(int i = 0; i<=(n-1); i++){
        pq.push({adj[i].size(),i});
    }
    int count = 2;
    unordered_set<int> to_check;
    int ans = 0;
    while(!pq.empty() && count>0){
        auto curr = pq.top();
        if(to_check.find(curr.second)==to_check.end()){
            count--;
            if(ans>0) ans--;
            ans+=curr.first;
            to_check = adj[curr.second];
            pq.pop();
        }
        else{
            to_check.erase(curr.second);
            curr.first-=1;
            pq.pop();
            pq.push(curr);
        }
    }
    cout<<ans<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
