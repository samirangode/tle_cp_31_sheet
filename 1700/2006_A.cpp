#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    // vector<vector<int>> adj(n + 1);
    vector<int> deg(n+1,0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        // adj[u].push_back(v);
        // adj[v].push_back(u);
        deg[u]+=1;
        deg[v]+=1;
    }
    string s;
    cin >> s;
    s = " " + s;
    int x = 0, y=0, z=0, w = 0;
    for(int i = 2; i<=n; i++){
        if(deg[i]==1){
            if(s[i]=='?'){
                z+=1;
            }
            else if(s[i]=='0') x+=1;
            else y+=1;
        }
        else if(s[i]=='?'){
            w+=1;
        }
    }
    if(s[1]=='0'){
        cout<<(y+(z+1)/2)<<endl;
    }
    else if(s[1]=='1'){
        cout<<(x + (z+1)/2)<<endl;
    }
    else{
        int val = 0;
        if(x==y){
            val = w%2;
        }
        cout<<(max(x,y) + (z + val)/2)<<endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}