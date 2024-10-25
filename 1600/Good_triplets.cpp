#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve(ll n){
    ll ans = 1;
    while(n>0){
        ll digit = n%10;
        n = n/10;
        ans = ans*(digit+1)*(digit+2)/2;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans = solve(n);
        cout<<ans<<endl;
    }
    return 0;
}