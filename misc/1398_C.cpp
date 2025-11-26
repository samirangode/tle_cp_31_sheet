#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> p(n+1, 0);
    for(int i = 0; i<n; i++){
        p[i+1] = p[i] + (s[i] -'0');
    }

    ll ans = 0;
    unordered_map<ll, ll> cnt;
    for(int k = 0; k<=n; k++){
        ll key = p[k] - k;
        ans += cnt[key];
        cnt[key]++;
    }
    cout<<ans<<endl;
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
