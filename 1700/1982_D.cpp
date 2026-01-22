#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>a[i][j];
        }
    }

    vector<string> s(n);
    for(int i = 0; i<n; i++){
        cin>>s[i];
    }

    // compute initial difference
    int D = 0;
    vector<vector<int>> b(n, vector<int>(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(s[i][j]=='1'){
                D+=a[i][j];
                b[i][j] = 1;
            }
            else{
                D-=a[i][j];
                b[i][j] = 0;
            }
        }
    }

    if(D==0){
        cout<<"YES"<<endl;
        return;
    }

    vector<vector<int>> P(n+1, vector<int>(m+1, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            P[i+1][j+1] = P[i+1][j] + P[i][j+1] - P[i][j] + b[i][j];
        }
    }

    int g = 0;
    for(int r = 0; r+k<=n; r++){
        for(int c = 0; c+k<=m; c++){
            int ones = P[r+k][c+k] - P[r+k][c] - P[r][c+k] + P[r][c];
            int zeros = k*k - ones;
            int d = zeros - ones;
            g = __gcd(d,g);
        }
    }
    if(g==0){
        cout<<"NO"<<endl;
    }
    else{
        cout<< (D%g==0 ? "YES" : "NO") <<endl;
    }
}   


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}