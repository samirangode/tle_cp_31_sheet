// #include <bits/stdc++.h>

// using namespace std;

// #define int long long

// const int N = 4e4 + 4, M = 502;
// const int MOD = 1e9 + 7;
// vector<int> palin;

// // void solve(){
// //     int n;
// //     cin>>n;
// // }

// int reverse(int n){
//     int r = 0;
//     while(n>0){
//         r = r*10 + n%10;
//         n=n/10;
//     }
//     return r;
// }

// int32_t main(){
    
//     int dp[N];
//     memset(dp, 0, sizeof dp);
//     dp[0] = 1;
//     for(int i = 0; i<palin.size(); i++){
//         for(int w = palin[i]; w<N; w++){
//             dp[w] += dp[w-palin[i]];
//         }
//     }


//     for(int i = 1; i<N; i++){
//         if(i==reverse(i)){
//             palin.push_back(i);
//         }
//     }
    
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin>>t;
//     while(t--){
//         // solve();
//         int n;
//         cin>>n;
//         cout<<dp[n];
//     }
// }

#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 40000;          // n ≤ 4e4
static const int N = MAXN + 1;          // dp indices 0..MAXN
static const int MOD = 1'000'000'007;

int revnum(int x) {
    int r = 0;
    while (x > 0) { r = r * 10 + (x % 10); x /= 10; }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1) Build list of palindromic "coins"
    vector<int> palin;
    for (int i = 1; i <= MAXN; ++i) {
        if (i == revnum(i)) palin.push_back(i);
    }

    // 2) Unbounded-knapsack DP (coins-first to avoid permutations)
    vector<int> dp(N, 0);
    dp[0] = 1;
    for (int p : palin) {
        for (int s = p; s <= MAXN; ++s) {
            dp[s] += dp[s - p];
            if (dp[s] >= MOD) dp[s] -= MOD;         // or dp[s] %= MOD;
        }
    }

    // 3) Answer queries
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}
