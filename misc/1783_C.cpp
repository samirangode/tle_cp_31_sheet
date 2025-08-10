#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    vector<ll> presum(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        
    }
    vector<int> orig = a;
    sort(a.begin(), a.end());
    for(int i = 0; i<n; i++){
        if(i==0){
            presum[i] = a[i];
        }
        else{
            presum[i] = presum[i-1] + a[i];
        }
    }

    int ind = upper_bound(presum.begin(),presum.end(), 1ll*m) - presum.begin();

    if(ind==n){
        cout<<1<<endl;
        return;
    }
    if(ind==0){
        cout<<n+1<<endl;
        return;
    }
    
    int rank = n - ind + 1;
    ll prev_presum = presum[ind-1];
    ll new_presum = prev_presum - a[ind-1] + orig[ind];
    if(new_presum<=m){
        // new rank
        rank-=1;

    }
    cout<<rank<<endl;
    return;
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
