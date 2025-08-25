#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<ll> g(n);   
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    sort(g.begin(),g.end(),greater<ll>());
    ll answer = 0;
    for(int i = 0 ; i<n; i+=2){
        answer += g[i];
    }
    cout<<answer<<"\n";
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
