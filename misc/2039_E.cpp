#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
const int MOD = 998244353;

// dp[i] = # of ways to form a length-n array starting from a length-i array
//         whose inversion count is > max(a)

long long dp[N];


void solve(){
    int n;
    cin >> n;
    
    long long suffixSum = 0;
    for(int i = n; i>=1; i--){
        // dp[i] = i * (sum of dp[j] for j = i+1..n) + 1
        dp[i] = (1LL*i*suffixSum + 1)%MOD;
        suffixSum = (suffixSum + dp[i])%MOD;
    }

    // arrays that never exceed inversion count 1
    long long ans = (n - 1)%MOD;

    // Step 3: Count arrays that eventually exceed 1 inversion.
    // They exceed 1 inversion for the first time at some length k (>= 3).

    for(int k = 3; k<=n; k++){
        // ways(k) = ((k - 1) * (k - 2))/2 - 1, all modded
        // We use long long carefully to avoid overflow, then mod again.
        long long w = (1LL * (k-1)*(k-2)/2 - 1 + MOD)% MOD;
        long long contrib = (w*dp[k])%MOD;
        ans = (ans+contrib)%MOD;
    }

    cout<< ans <<"\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

