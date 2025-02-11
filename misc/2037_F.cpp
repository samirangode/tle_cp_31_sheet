#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> h(n);
    for(ll i = 0; i<n; i++){
        cin>>h[i];
    }
    vector<ll> x(n);
    for(ll i = 0; i<n; i++){
        cin>>x[i];
    }
    ll hi = 1e9 + 10;
    ll lo = 1;
    bool possible = false;
    // ll mid = lo;
    while(hi>lo){
        long long mid = lo + (hi-lo)/2;

        vector<pair<long long, long long>> sweep;
        for(ll i = 0; i<n; i++){
            // int attack_needed_to_kill = h[i]/mid;
            long long ma = (h[i] + mid - 1) / mid;
            if(ma>m) continue;
            sweep.push_back({x[i] + ma -m,+1});
            sweep.push_back({x[i] + m - ma +1, -1});
        }
        sort(sweep.begin(), sweep.end());
        long long sc = 0;
        bool canKill = false;
        for(auto &it : sweep){
            sc+=it.second;
            if(sc>=k){
                canKill = true;
                break;
            }
        }
        if(canKill){
            hi = mid;
            possible= true;
        }
        else lo =mid + 1;
    }
    if (!possible)
        cout<<-1<<endl;
    else
        cout<<hi<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
