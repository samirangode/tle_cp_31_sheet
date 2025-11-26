#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<ll>> a(n, vector<ll>(m,0));
    vector<vector<ll>> sums(n, vector<ll>(m,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>a[i][j];
            sums[i][j] = sums[i][j-1] + a[i][j];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
        
        }
    }

    
   
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
