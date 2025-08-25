// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// void solve(){
//     int n;
//     cin>>n;

//     vector<ll> b(n);
//     for(int i = 0; i<n; i++){
//         cin>>b[i];
//     }
//     vector<ll> prefix_mx(n), suffix_mx(n);
//     for(int i = 0; i<n; i++){
//         prefix_mx[i] = b[i] + i;
//         suffix_mx[i] = b[i] - i;
//     }
//     for(int i = 1; i<n; i++){
//         prefix_mx[i] = max(prefix_mx[i-1], prefix_mx[i]);
//     }
//     for(int i = n-2; i>=0; i--){
//         suffix_mx[i] = max(suffix_mx[i+1], suffix_mx[i]);
//     }

//     ll ans = LLONG_MIN;
//     for(int m = 1; m<=n-2; m++){
//         ll cand = b[m] + prefix_mx[m-1] + suffix_mx[m+1];
//         ans = max(ans, cand);
//     }
//     cout<<ans<<endl;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }

///// Alternative solution
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<ll> b(n);

    for(int i = 0; i<n; i++) cin>>b[i];

    const long long NEG = (long long)-4e18;

    // dp0 = F(i,0) (always 0), dp1 = F(i,1), dp2 = F(i,2), dp3 = F(i,3)
    long long dp0 = 0, dp1 = NEG, dp2 = NEG, dp3 = NEG;

    for(int i = 0; i<n; i++){
        // update in descending order
        ll ndp3 = max(dp3, (dp2==NEG? NEG : dp2 + (b[i]-i))); // take as r
        ll ndp2 = max(dp2, (dp1==NEG? NEG : dp1 + b[i]));
        ll ndp1 = max(dp1,                  dp0 + (b[i]+ i));
        dp3 = ndp3; dp2 = ndp2; dp1 = ndp1;
    }
    cout<<dp3<<endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}