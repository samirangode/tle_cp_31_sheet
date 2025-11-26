#include <bits/stdc++.h>

using namespace std;

#define long long ll


void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());
    for(int i = 2; i<n; i+=2){
        if(a[i]!=a[i+1]){
           cout<<"NO"<<endl; 
           return;
        }
    }
    cout<<"YES"<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}