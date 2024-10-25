#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int>& a){
    int n= a.size()-1;
    vector<bool> dp(n+1,false);
    dp[0] = true;
    for(int i = 1; i<=n; i++){
        if(i+ a[i] <=n && dp[i-1]) dp[i+a[i]]=true;

        if(i-a[i]-1 >=0 && dp[i-a[i]-1]) dp[i] = true;
    }
    return dp[n];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int> a(n+1);
        for(int i = 1; i<=n; i++){
            cin>>a[i];
        }
        bool ans = solve(a);
        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
// #include <bits/stdc++.h>

// using namespace std;

// #define forn(i, n) for (int i = 0; i < int(n); i++)
// #define sz(v) (int)v.size()
// #define all(v) v.begin(),v.end()
// #define eb emplace_back



// void solve() {
//     int n; cin >> n;
//     vector<int> a(n+1);
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//     }

//     vector<bool> dp(n+1, false);
//     dp[0] = true;
//     for (int i = 1; i <= n; ++i) {
//         if (i + a[i] <= n && dp[i-1]) dp[i + a[i]] = true;
//         if (i - a[i] - 1 >= 0 && dp[i - a[i] - 1]) dp[i] = true;
//     }
//     cout << (dp[n] ? "YES" : "NO") << '\n';
// }

// int main() {
//     int t;
//     cin >> t;

//     forn(tt, t) {
//         solve();
//     }

// }
