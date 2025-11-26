#include <bits/stdc++.h>

using namespace std;



void solve(vector<int>& a, const dp[][]){

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N = 1001, K = 1001;
    int dp[N][K];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i<N; i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for(int i = 2; i<N; i++){
        for(int j = 1; j<K; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }


    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int> a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        solve(a,dp);
        
    }
    

    return 0;
}
