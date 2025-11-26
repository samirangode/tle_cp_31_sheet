#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;

void solve(int k, int n){
    if(k==1){
        cout<<1<<endl;
        return;
    }
    vector<vector<int>> dp(k+1, vector<int>(n+1,1));
    // for(auto& a : dp[1]){
    //     a = 1;
    // }
    // dp[1][0] = 0;
    for(int j = 2; j<=k; j++){
        for(int i = 1; i<=n; i++){
            dp[j][i] = (dp[j-1][n-i]%MOD + dp[j][i-1]%MOD)%MOD;
        }
    }
    cout<<dp[k][n]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        int k;
        cin>>n>>k;
        
        solve(k,n);

    }
}
