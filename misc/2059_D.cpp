#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n, s1, s2;
    cin>>n>>s1>>s2;
    s1--; s2--;
    vector<vector<int>> g1(n), g2(n);
    vector<bool> good(n);
    set<pair<int,int>> us;
    int m1;
    cin>>m1;
    for(int i = 0; i<m1; i++){
        int v, u;
        cin >> v >> u;
        v--; u--;
        if(v<u){
            swap(u,v);
        }
        us.insert({u,v});
        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    int m2;
    cin>>m2;
    for(int i = 0; i<m2; i++){
        int v, u;
        cin>>v>>u;
        v--; u--;
        if(v<u){
            swap(u,v);
        }
        if(us.find({u,v})!=us.end()){
            good[u] = true; good[v] = true;
        }
        g2[u].push_back(v);
        g2[v].push_back(u);
    }
    const int INF = 1e9;
    vector<vector<int>> d(n, vector<int>(n,INF));
    d[s1][s2]=0;
    // priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;
    set<pair<int, pair<int,int>>> st;
    // pq.push({0,{s1,s2}});
    st.insert({0,{s1,s2}});
    // while(!pq.empty()){
    while(!st.empty()){
        // auto [v,u] = pq.top().second;
        auto [v,u] = st.begin()->second;
        // pq.pop();
        st.erase(st.begin());
        for(int c1 : g1[v]){
            for(int c2 : g2[u]){
                int w = abs(c1-c2);
                // if(d[c1][c2]<d[v][u]+w) continue;
                if(d[c1][c2] > d[v][u]+w){
                    st.erase({d[c1][c2],{c1,c2}});
                    d[c1][c2] = d[v][u] + w;
                    st.insert({d[c1][c2],{c1,c2}});
                }
                // pq.push({d[c1][c2],{c1,c2}});
            }
        }
    }
    int ans = INF;
    for(int i = 0; i<n; i++){
        if(good[i]){
            ans = min(ans,d[i][i]);
        }
    }
    if(ans==INF) 
        ans=-1;
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
