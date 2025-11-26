#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i<=n; i++) cin>>a[i];

    vector<vector<int>> positions(n+1);
    for(int i = 1; i<=n; i++){
        positions[a[i]].push_back(i);
    }

    const int INF = n+5;

    vector<int> bestAt(n+1, INF);

    for(int i = 1; i<=n; i++){
        if(positions[i].empty()) continue;

        int maxGap = 0;
        int prev = 0;
        for(int pos: positions[i]){
            maxGap = max(pos-prev, maxGap);
            prev = pos;
        }
        maxGap = max(maxGap, (n+1) - prev);

        int fx = maxGap;

        bestAt[fx] = min(bestAt[fx], i);
    }
    vector<int> ans(n+1, -1);
    int cur = INF;
    for(int k = 1; k<=n; k++){
        cur = min(cur, bestAt[k]);
        ans[k] = (cur==INF ? -1 : cur);
    }
    for(int k = 1; k<=n; k++){
        cout<<ans[k]<<(k==n ? '\n': ' ');
    }
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