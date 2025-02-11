#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll m, x;
    cin>>m;
    cin>>x; 
    vector<ll> cost(m+1);
    vector<ll> happiness(m+1);
    // ll max_h_value = 1e5 + 1;
    ll max_h_value = INT_MIN;
    for(int i = 1; i<=m; i++){
        cin>>cost[i];
        cin>>happiness[i];
        max_h_value = max(max_h_value,happiness[i]);
    }
    max_h_value = min(m*max_h_value, (ll)1e5+1);

    vector<vector<ll>> dp(m+1, vector<ll>(max_h_value+1, INT_MAX));
    for(int i = 0; i<=m; i++){
        dp[i][0] = 0;
    }
    // for(int h=0; h<=1000; h++){
    //     dp[0][h] = 0;
    // }

    for(ll i = 1; i<=m; i++){
        for(ll h = 1; h<=max_h_value; h++){
            ll choose_cost = INT_MAX;
            if(h-happiness[i]>=0){
                ll cost_prev = dp[i-1][h-happiness[i]];
                if(cost_prev + cost[i] <= (i-1)*x){
                    choose_cost = cost_prev + cost[i]; 
                }
            }
            ll nc_cost = dp[i-1][h];
            dp[i][h] = min(choose_cost, nc_cost);
        }
    }
    ll max_happiness = 0;
    for(int h = 1; h<=max_h_value; h++){
        if(dp[m][h]<INT_MAX)
            max_happiness = h;
    }
    cout<<max_happiness<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();

    }

}
