#include <bits/stdc++.h>

using namespace std;

#define int long long

int MOD = 1e9+7;
void solve(){
    string s;
    cin>>s;
    int m = s.size();
    int n = 0;
    for(char c : s){
        if(c=='a') n++;
    }
    

    int ans = 0;
    vector<int> dp(n,1);
    int pref_use = 0;
    int pref_c = 0;
    int j = n-1;
    for(int i = m; i>=0; i--){
        if(s[i]=='a'){
            dp[j] = dp[j] + pref_use;
            pref_c = (pref_c%MOD + dp[j]%MOD)%MOD;
            ans = (ans + dp[j]%MOD)%MOD;
            j--;
            if(j<0) break;
        }
        else if(s[i]=='b'){
            pref_use = pref_c;
        }
    }

    cout<<ans<<endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
